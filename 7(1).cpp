#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::cerr;

// ---------- работа с памятью ----------
int* allocateArray(std::size_t n)
{
    return new int[n];
}

void freeArray(int* p) noexcept
{
    delete[] p;
}

// ---------- ввод ----------
std::size_t readSize()
{
    std::size_t n;
    cout << "Введите кол-во элементов: ";
    if (!(cin >> n) || n == 0) {
        cerr << "Ошибка ввода: нужно натуральное число.\n";
        std::exit(EXIT_FAILURE);
    }
    return n;
}

void readArray(int* arr, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            cerr << "Ошибка ввода: ожидалось целое число.\n";
            std::exit(EXIT_FAILURE);
        }
    }
}

// ---------- вывод ----------
void printArray(const int* arr, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << '\n';
}

// ---------- алгоритмы ----------
std::size_t indexOfMin(const int* arr, std::size_t n)
{
    if (n == 0) return 0;
    std::size_t minIdx = 0;
    for (std::size_t i = 1; i < n; ++i)
        if (arr[i] < arr[minIdx]) minIdx = i;
    return minIdx;
}

void replaceMinByMiddle(int* arr, std::size_t n)
{
    arr[indexOfMin(arr, n)] = arr[n / 2];
}

void printIncreasingIndexes(const int* arr, std::size_t n)
{
    cout << "indexes: ";
    for (std::size_t i = 1; i < n; ++i)
        if (arr[i] > arr[i - 1]) cout << i << ' ';
    cout << '\n';
}

bool hasTwoEqualSignPairs(const int* arr, std::size_t n)
{
    std::size_t pairs = 0;
    for (std::size_t i = 1; i < n; ++i)
        if (arr[i] * arr[i - 1] >= 0 && ++pairs == 2) return true;
    return false;
}

// ---------- main ----------
int main()
{
    setlocale(LC_ALL, "rus");

    const std::size_t n   = readSize();
    int* const        arr = allocateArray(n);

    readArray(arr, n);
    printArray(arr, n);

    // 1. заменить минимальный элемент серединным
    replaceMinByMiddle(arr, n);
    printArray(arr, n);

    // 2. индексы, где элемент больше предыдущего
    printIncreasingIndexes(arr, n);

    // 3. есть ли хотя бы две пары соседей одинакового знака
    cout << "Две пары с одинаковыми знаками: "
         << (hasTwoEqualSignPairs(arr, n) ? "есть\n" : "нет\n");

    freeArray(arr);
    return 0;
}
