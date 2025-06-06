#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief Оператор выбора способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY = 1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief Проверяет размер массива
 * @param n - размер массива
 */
void checkN(const size_t n);

/**
 * @brief Считывает размер массива
 * @return размер массива
 */
size_t getSize();

/**
 * @brief Считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief Вывод массива на экран
 * @param arr Указатель на массив целых чисел
 * @param n Размер массива
 */
void printArray(const int* arr, const size_t n);

/**
 * @brief Заполнение массива автоматически случайными числами в заданном диапазоне
 * @param arr Указатель на массив целых чисел
 * @param n Размер массива
 * @param min Минимальное значение диапазона
 * @param max Максимальное значение диапазона
 */
void fillArrayRandom(int* arr, const size_t n, const int min, const int max);

/**
 * @brief Проверяет диапазон
 * @param min Минимальное значение диапазона
 * @param max Максимальное значение диапазона
 */
void checkRange(const int min, const int max);

/**
 * @brief Заменяет минимальный элемент массива на среднее арифметическое
 * @param arr Указатель на исходный массив целых чисел
 * @param result Указатель на результирующий массив (копия исходного)
 * @param n Размер массива
 */
void replaceMinWithAverage(const int arr[], int result[], const size_t n);

/**
 * @brief Проверяет, содержит ли массив две пары соседних элементов с одинаковыми знаками
 * @param arr Указатель на массив целых чисел
 * @param n Количество элементов в массиве
 * @return true если есть две пары, иначе false
 */
bool hasTwoPairsWithSameSign(const int arr[], const size_t n);

/**
 * @brief Выводит индексы элементов, значения которых больше предыдущих
 * @param arr Указатель на массив целых чисел
 * @param n Количество элементов в массиве
 */
void printIndicesGreaterThanPrevious(const int arr[], const size_t n);

/**
 * @brief Заполнение массива вручную
 * @param arr Указатель на массив целых чисел
 * @param n Размер массива
 * @param min Минимальное значение диапазона
 * @param max Максимальное значение диапазона
 */
void fillArray(int* arr, const size_t n, const int min, const int max);

int main()
{
    setlocale(LC_ALL, "Russian");
    size_t n = getSize();
    int* arr = new int[n];
    int* arrCopy = new int[n]; // Копия массива для изменений

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Выберите способ заполнения массива:\n"
         << RANDOM << " - случайное заполнение\n"
         << MANUALLY << " - ручное заполнение\n";
    
    int choice = getNumber();

    switch (choice)
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Неверный выбор" << endl;
        delete[] arr;
        delete[] arrCopy;
        return -1;
    }

    // Копируем исходный массив
    for (size_t i = 0; i < n; i++) {
        arrCopy[i] = arr[i];
    }

    cout << "Исходный массив:" << endl;
    printArray(arr, n);

    replaceMinWithAverage(arr, arrCopy, n);
    cout << "Массив после замены минимального элемента на среднее:" << endl;
    printArray(arrCopy, n);

    cout << "Индексы элементов, больших предыдущих:" << endl;
    printIndicesGreaterThanPrevious(arr, n);

    if (hasTwoPairsWithSameSign(arr, n))
    {
        cout << "Есть две пары соседних элементов с одинаковыми знаками." << endl;
    }
    else
    {
        cout << "Нет двух пар соседних элементов с одинаковыми знаками." << endl;
    }

    delete[] arr;
    delete[] arrCopy;
    return 0;
}

void checkN(const size_t n)
{
    if (n <= 0)
    {
        cerr << "Неверный размер массива" << endl;
        exit(1);
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n = 0;
    cin >> n;
    if (n < 0) {
        cerr << "Размер массива не может быть отрицательным" << endl;
        exit(1);
    }
    checkN(static_cast<size_t>(n));
    return static_cast<size_t>(n);
}

int getNumber()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        cerr << "Неверный ввод данных" << endl;
        exit(1);
    }
    return number;
}

void printArray(const int* arr, const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const size_t n, const int min, const int max)
{
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cerr << "Неверный диапазон" << endl;
        exit(1);
    }
}

void replaceMinWithAverage(const int arr[], int result[], const size_t n)
{
    size_t minIndex = 0;
    for (size_t i = 1; i < n; ++i)
    {
        if (result[i] < result[minIndex])
        {
            minIndex = i;
        }
    }

    int sum = 0;
    for (size_t i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    result[minIndex] = sum / static_cast<int>(n);
}

void printIndicesGreaterThanPrevious(const int arr[], const size_t n)
{
    for (size_t i = 1; i < n; ++i)
    {
        if (arr[i] > arr[i - 1])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

bool hasTwoPairsWithSameSign(const int arr[], const size_t n)
{
    if (n < 4) return false;

    for (size_t i = 0; i < n - 3; ++i)
    {
        if ((arr[i] * arr[i + 1] > 0) && (arr[i + 2] * arr[i + 3] > 0))
        {
            return true;
        }
    }
    return false;
}

void fillArray(int* arr, const size_t n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();

        if (arr[i] < min || arr[i] > max)
        {
            cerr << "Значение вне диапазона" << endl;
            i--;
        }
    }
}
