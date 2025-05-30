#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода.
 * @return Введенное пользователем значение типа double.
 * @note Если ввод некорректный, программа завершается с кодом ошибки.
 */
double getValue();

/**
 * @brief Считывает диапазон для генерации случайных чисел.
 * @param min Ссылка для хранения минимального значения.
 * @param max Ссылка для хранения максимального значения.
 */
void getRange(int& min, int& max);

/**
 * @brief Проверяет, что количество строк и столбцов являются положительными числами.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return true, если оба значения положительные; false в противном случае.
 */
bool checkPositiveValues(const int rows, const int cols);

/**
 * @brief Заполняет двумерный массив случайными значениями в заданном диапазоне.
 * @param array Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 * @param min Минимальное значение для генерации.
 * @param max Максимальное значение для генерации.
 */
void fillArrayRandomly(int** array, const int rows, const int cols, const int min, const int max);

/**
 * @brief Заменяет максимальный по модулю элемент каждого столбца на нуль.
 * @param array Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void replaceMaxWithZero(int** array, const int rows, const int cols);

/**
 * @brief Вставляет первую строку после каждой строки, содержащей максимальный по модулю элемент.
 * @param newArray Указатель на новый двумерный массив.
 * @param originalArray Указатель на исходный двумерный массив.
 * @param new_rows Количество строк в новом массиве.
 * @param rows Количество строк в исходном массиве.
 * @param cols Количество столбцов в массивах.
 */
void insertFirstRowAfterMaxAbsElement(int** newArray, int** originalArray, const int new_rows, const int rows, const int cols);

/**
 * @brief Выводит двумерный массив на экран.
 * @param array Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void printArray(int** array, const int rows, const int cols);

/**
 * @brief Создает новый двумерный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на созданный массив.
 */
int** createArray(const int rows, const int cols);

/**
 * @brief Копирует содержимое одного массива в другой.
 * @param source Указатель на исходный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на новый массив с копией данных.
 */
int** copyArray(int** source, const int rows, const int cols);

/**
 * @brief Освобождает память, выделенную под двумерный массив.
 * @param array Указатель на массив.
 * @param rows Количество строк.
 */
void deleteArray(int** array, const int rows);

/**
 * @brief Проверяет, является ли первое число по модулю больше второго.
 * @param num1 Первое число.
 * @param num2 Второе число.
 * @return true, если |num1| > |num2|; иначе false.
 */
bool isFirstAbsoluteValueGreaterThanSecond(const int num1, const int num2);

/**
 * @brief Находит максимальный по модулю элемент в массиве.
 * @param array Указатель на массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Значение максимального по модулю элемента.
 */
int getMaxAbsElementInMatrix(int** array, const int rows, const int cols);

/**
 * @brief Подсчитывает количество строк, содержащих максимальный по модулю элемент.
 * @param array Указатель на массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Количество строк с максимальным элементом.
 */
int countRowsWithMaxAbsElement(int** array, const int rows, const int cols);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Введите количество строк: ";
    int rows = static_cast<int>(getValue());

    cout << "Введите количество столбцов: ";
    int cols = static_cast<int>(getValue());

    if (!checkPositiveValues(rows, cols))
    {
        return 1;
    }

    int min, max;
    getRange(min, max);

    int** originalArray = createArray(rows, cols);
    fillArrayRandomly(originalArray, rows, cols, min, max);

    cout << "Случайно заполненный массив:" << endl;
    printArray(originalArray, rows, cols);

    int** modifiedArray = copyArray(originalArray, rows, cols);
    replaceMaxWithZero(modifiedArray, rows, cols);

    cout << "\nМассив после замены максимального элемента столбца на 0:" << endl;
    printArray(modifiedArray, rows, cols);
    deleteArray(modifiedArray, rows);

    int newRows = rows + countRowsWithMaxAbsElement(originalArray, rows, cols);
    int** expandedArray = createArray(newRows, cols);
    insertFirstRowAfterMaxAbsElement(expandedArray, originalArray, newRows, rows, cols);

    cout << "\nМассив после вставки первой строки после строк с максимальным элементом:" << endl;
    printArray(expandedArray, newRows, cols);

    deleteArray(expandedArray, newRows);
    deleteArray(originalArray, rows);

    return 0;
}

double getValue()
{
    double value = 0.0;
    cin >> value;
    if (cin.fail())
    {
        cerr << "Некорректное значение" << endl;
        exit(1);
    }
    return value;
}

void getRange(int& min, int& max)
{
    cout << "Введите минимальное значение диапазона: ";
    min = static_cast<int>(getValue());
    
    cout << "Введите максимальное значение диапазона: ";
    max = static_cast<int>(getValue());
    
    if (min > max)
    {
        cerr << "Ошибка: Минимальное значение не может быть больше максимального" << endl;
        exit(1);
    }
}

bool checkPositiveValues(const int rows, const int cols)
{
    if (rows > 0 && cols > 0)
    {
        return true;
    }
    cerr << "Ошибка: Количество строк и столбцов должно быть положительным." << endl;
    return false;
}

void fillArrayRandomly(int** array, const int rows, const int cols, const int min, const int max)
{
    const int range = max - min + 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            array[i][j] = rand() % range + min;
        }
    }
}

void replaceMaxWithZero(int** array, const int rows, const int cols)
{
    for (int j = 0; j < cols; ++j)
    {
        int maxRowIndex = 0;
        for (int i = 1; i < rows; ++i)
        {
            if (abs(array[i][j]) > abs(array[maxRowIndex][j]))
            {
                maxRowIndex = i;
            }
        }
        array[maxRowIndex][j] = 0;
    }
}

bool isFirstAbsoluteValueGreaterThanSecond(const int num1, const int num2)
{
    return abs(num1) > abs(num2);
}

int getMaxAbsElementInMatrix(int** array, const int rows, const int cols)
{
    int maxElement = array[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (abs(array[i][j]) > abs(maxElement))
            {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}

int countRowsWithMaxAbsElement(int** array, const int rows, const int cols)
{
    int count = 0;
    int maxElement = getMaxAbsElementInMatrix(array, rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (array[i][j] == maxElement)
            {
                ++count;
                break;
            }
        }
    }
    return count;
}

void insertFirstRowAfterMaxAbsElement(int** newArray, int** originalArray, const int new_rows, const int rows, const int cols)
{
    int maxElement = getMaxAbsElementInMatrix(originalArray, rows, cols);
    int* firstRow = new int[cols];
    for (int j = 0; j < cols; ++j)
    {
        firstRow[j] = originalArray[0][j];
    }

    int newIndex = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            newArray[newIndex][j] = originalArray[i][j];
        }
        ++newIndex;

        bool containsMax = false;
        for (int j = 0; j < cols; ++j)
        {
            if (originalArray[i][j] == maxElement)
            {
                containsMax = true;
                break;
            }
        }

        if (containsMax && newIndex < new_rows)
        {
            for (int j = 0; j < cols; ++j)
            {
                newArray[newIndex][j] = firstRow[j];
            }
            ++newIndex;
        }
    }
    delete[] firstRow;
}

void printArray(int** array, const int rows, const int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

int** createArray(const int rows, const int cols)
{
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        array[i] = new int[cols];
    }
    return array;
}

int** copyArray(int** source, const int rows, const int cols)
{
    int** newArray = createArray(rows, cols);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            newArray[i][j] = source[i][j];
        }
    }
    return newArray;
}

void deleteArray(int** array, const int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        delete[] array[i];
    }
    delete[] array;
}