#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::cerr;

// Объявление функций
int* allocateArray(std::size_t n);
void freeArray(int* p) noexcept;
std::size_t readSize();
void readArray(int* arr, std::size_t n);
void printArray(const int* arr, std::size_t n);
std::size_t indexOfMin(const int* arr, std::size_t n);
void replaceMinByMiddle(int* arr, std::size_t n);
void printIncreasingIndexes(const int* arr, std::size_t n);
bool hasTwoEqualSignPairs(const int* arr, std::size_t n);

// ---------- main ----------
int main() {
    setlocale(LC_ALL, "rus");

    const std::size_t n = readSize();
    int* const arr = allocateArray(n);

    readArray(arr, n);
    printArray(arr, n);

    // 1. заменить минимальный элемент серединным
    int* copy_arr = allocateArray(n); // Исправлено: используем allocateArray
    for (std::size_t i = 0; i < n; ++i) {
        copy_arr[i] = arr[i];
    }
    replaceMinByMiddle(copy_arr, n);
    printArray(copy_arr, n);
    freeArray(copy_arr); // Исправлено: используем freeArray

    // 2. индексы, где элемент больше предыдущего
    printIncreasingIndexes(arr, n);

    // 3. есть ли хотя бы две пары соседей одинакового знака
    cout << "Две пары с одинаковыми знаками: "
        << (hasTwoEqualSignPairs(arr, n) ? "есть\n" : "нет\n");

    freeArray(arr);
    return 0;
}

// ---------- работа с памятью ----------
/**
 * @brief Выделяет память для массива целых чисел.
 * @param n Размер массива.
 * @return Указатель на выделенную память.
 */
int* allocateArray(std::size_t n) {
    return new int[n];
}

/**
 * @brief Освобождает память, выделенную для массива целых чисел.
 * @param p Указатель на выделенную память.
 */
void freeArray(int* p) noexcept {
    delete[] p;
}

// ---------- ввод ----------
/**
 * @brief Считывает размер массива из стандартного ввода.
 * @return Размер массива.
 */
std::size_t readSize() {
    std::size_t n;
    cout << "Введите кол-во элементов: ";
    if (!(cin >> n) || n == 0) {
        cerr << "Ошибка ввода: нужно натуральное число.\n";
        std::exit(EXIT_FAILURE);
    }
    return n;
}

/**
 * @brief Считывает элементы массива из стандартного ввода.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 */
void readArray(int* arr, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Ошибка ввода: ожидалось целое число.\n";
            std::exit(EXIT_FAILURE);
        }
    }
}

// ---------- вывод ----------
/**
 * @brief Выводит элементы массива в стандартный вывод.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 */
void printArray(const int* arr, std::size_t n) {
    for (std::size_t i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << '\n';
}

// ---------- алгоритмы ----------
/**
 * @brief Находит индекс минимального элемента в массиве.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 * @return Индекс минимального элемента.
 */
std::size_t indexOfMin(const int* arr, std::size_t n) {
    if (n == 0) return 0;
    std::size_t minIdx = 0;
    for (std::size_t i = 1; i < n; ++i)
        if (arr[i] < arr[minIdx]) minIdx = i;
    return minIdx;
}

/**
 * @brief Заменяет минимальный элемент массива на серединный.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 */
void replaceMinByMiddle(int* arr, std::size_t n) {
      if (n > 0) {
    std::size_t min_index = indexOfMin(arr, n);
    arr[min_index] = arr[n / 2];
      }

}

/**
 * @brief Выводит индексы элементов массива, которые больше предыдущих.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 */
void printIncreasingIndexes(const int* arr, std::size_t n) {
    cout << "indexes: ";
    for (std::size_t i = 1; i < n; ++i)
        if (arr[i] > arr[i - 1]) cout << i << ' ';
    cout << '\n';
}

/**
 * @brief Проверяет, есть ли в массиве хотя бы две пары соседних элементов одинакового знака.
 * @param arr Указатель на массив.
 * @param n Размер массива.
 * @return true, если есть хотя бы две пары, false в противном случае.
 */
bool hasTwoEqualSignPairs(const int* arr, std::size_t n) {
    std::size_t pairs = 0;
    for (std::size_t i = 1; i < n; ++i)
        if (arr[i] * arr[i - 1] >= 0 && ++pairs == 2) return true;
    return false;
}
