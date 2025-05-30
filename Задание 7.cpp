
#include <iostream>
using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
 * @brief Проверяет, что количество строк и столбцов являются положительными числами.
 * @param max_rows Максимальное количество строк.
 * @param max_cols Максимальное количество столбцов.
 * @return true, если оба значения положительные; false в противном случае.
 */
bool checkPositiveValues(const int max_rows, const int max_cols);

/**
 *@brief Заполняет двумерный массив случайными значениями.
 *@param array Указатель на двумерный массив.
 *@param rows Количество строк в массиве.
 *@param cols Количество столбцов в массиве.
 */
void fillArrayRandomly(int** array, const int rows, const int cols);

/**
 * @brief Заменяет максимальный по модулю элемент каждого столбца на нуль.
 * @param array Указатель на двумерный массив.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void replaceMinWithZero(int** array, const int rows, const int cols);

/**
 * @brief Вставляет последнюю строку после каждой строки, содержащей максимальный по модулю элемент.
 * @param arr3 Указатель на двумерный массив, в который будет производиться вставка.
 * @param array Указатель на исходный двумерный массив.
 * @param new_rows Количество новых строк после вставки.
 * @param rows Количество строк в исходном массиве.
 * @param cols Количество столбцов в массивах.
 */
void insertFirstRowAfterMaxAbsColumn(int** arr3, int** array, const int new_rows, const int rows, const int cols);

/**
*@brief Выводит двумерный массив на экран.
*@param  array Указатель на двумерный массив
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void printArray(int** array, const int rows, const int cols);

/**
 * @brief Создает новый двумерный массив с заданным количеством строк и столбцов.
 * @param rows Количество строк в новом массиве.
 * @param columns Количество столбцов в новом массиве.
 * @return Указатель на новый двумерный массив типа int.
 */
int** getNewArray(const int rows, const int columns);

/**
 * @brief Создает копию существующего двумерного массива с заданным количеством строк и столбцов.
 * @param arr Указатель на существующий двумерный массив типа int, который нужно скопировать.
 * @param rows Количество строк в существующем массиве.
 * @param columns Количество столбцов в существующем массиве.
 * @return Указатель на новую копию двумерного массива типа int.
 */
int** copyArray(int** arr, const int rows, const int columns);

/**
 * @brief Освобождает память, выделенную под двумерный массив типа int.
 * @param arr Указатель на двумерный массив типа int, который нужно освободить.
 * @param rows Количество строк в двумерном массиве.
 */
void deleteArray(int** arr, const int rows);

/**
 * @brief Проверка болтше ли по модулю 1е число 2ого
 * @param num1 первое число
 * @param num2 второе число
 * @return результат true или false
 */
bool isFirstAbsoluteValueGreaterThanSecond(const int num1, const int num2);

/**
 * @brief Возвращает, сколько строк нужно довать для нового маси=сива ихз задания 2
 * @param arr Указатель двумерный массив типа int
 * @param rows Количество строк массиве.
 * @param columns Количество столбцов массиве.
 * @return количество строк
 */
int countRowsWithMaxElement(int** array, const int rows, const int cols);

/**
 * @brief Возвращает максимальный элемент по модулю
 * @param arr Указатель двумерный массив типа int
 * @param rows Количество строк массиве.
 * @param columns Количество столбцов массиве.
 * @return количество строк
 */
int getMaxelementInMatrix(int** array, const int rows, const int cols);

/**
 * @brief Точка входа в программу
 * @return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    cout << "Введите количество строк: ";
    int max_rows = getValue();

    cout << "Введите количество столбцов: ";
    int max_cols = getValue();

    if (!checkPositiveValues(max_rows, max_cols))
    {
        return 1;
    }

    int** array = getNewArray(max_rows, max_cols);
    fillArrayRandomly(array, max_rows, max_cols);

    cout << "Случайно заполненный массив:" << endl;
    printArray(array, max_rows, max_cols);

    int** secondArr = copyArray(array, max_rows, max_cols);
    replaceMinWithZero(secondArr, max_rows, max_cols);

    cout << "\nМассив после замены максимального элемента столбца на 0:" << endl;
    printArray(secondArr, max_rows, max_cols);

    deleteArray(secondArr, max_rows);


    cout << "\nВставляет первую строку после строки с максимальным по модулю элементом в каждом столбце двумерного массива:" << endl;
    int newrows = max_rows + countRowsWithMaxElement(array, max_rows, max_cols);
    int** arr3 = getNewArray(newrows, max_cols);
    insertFirstRowAfterMaxAbsColumn(arr3, array, newrows, max_rows, max_cols);

    printArray(arr3, newrows, max_cols);

    deleteArray(arr3, newrows);
    deleteArray(array, max_rows);

    return 0;
}

void fillArrayRandomly(int** array, const int rows, const int cols)
{
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            array[i][j] = rand() % (100 - -100 + 1) + -100;
        }
    }
}

void replaceMaxWithZero(int** array, const int rows, const int cols) {
    for (size_t j = 0; j < cols; ++j) {
        int maxAbsValueRowIndex = 0;
        for (size_t i = 1; i < rows; ++i) {
            if (abs(array[i][j]) > abs(array[maxAbsValueRowIndex][j])) {
                maxAbsValueRowIndex = i;
            }
        }
        array[maxAbsValueRowIndex][j] = 0;
    }
}

bool isFirstAbsoluteValueGreaterThanSecond(const int num1, const int num2) {
    return (abs(num1) > abs(num2));
}

int countRowsWithMaxElement(int** array, const int rows, const int cols) {
    int rowsWithMaxElement = 0;
    int maxElement = getMaxelementInMatrix(array, rows, cols);
    bool isMaxElementInRow = false;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (abs(maxElement) == abs(array[i][j])) {
                isMaxElementInRow = true;
            }
        }
        if (isMaxElementInRow) {
            rowsWithMaxElement++;
            isMaxElementInRow = false;
        }
    }
    return rowsWithMaxElement;
}


int getMaxelementInMatrix(int** array, const int rows, const int cols) {
    int max_elem = 0;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (isFirstAbsoluteValueGreaterThanSecond(array[i][j], max_elem) == true) {
                max_elem = array[i][j];
            }
        }
    }
    return max_elem;
}
void insertFirstRowAfterMaxAbsColumn(int** arr3, int** array, const int new_rows, const int rows, const int cols) {
    // Находим максимальный по модулю элемент в исходном массиве
    int max_elem = getMaxelementInMatrix(array, rows, cols);
    cout << "MAX=" << max_elem << endl;

    // Создаем временную строку для хранения первой строки исходного массива
    int* temprow = new int[cols]();
    for (size_t j = 0; j < cols; j++) {
        temprow[j] = array[0][j];
    }

    bool need_insert = false;
    for (size_t i = 0, new_i = 0; i < rows && new_i < new_rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (abs(max_elem) == abs(array[i][j])) {
                need_insert = true;
            }
            arr3[new_i][j] = array[i][j];
        }
        new_i++;

        // Если текущая строка содержит максимальный по модулю элемент, вставляем временную строку после нее
        if (need_insert == true) {
            for (size_t j = 0; j < cols; j++) {
                arr3[new_i][j] = temprow[j];
            }
            new_i++;
            need_insert = false;
        }
    }

    delete[] temprow;
}

void printArray(int** array, const int rows, const int cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail()) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

int** getNewArray(const int max_rows, const int max_cols) {
    int** array = new int* [max_rows];
    for (size_t i = 0; i < max_rows; ++i)
    {
        array[i] = new int[max_cols];
    }
    return array;
}

int** copyArray(int** arr, const int rows, const int columns)
{
    int** resultArray = getNewArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            resultArray[i][j] = arr[i][j];
        }
    }
    return resultArray;
}

void deleteArray(int** arr, const int rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

bool checkPositiveValues(const int max_rows, const int max_cols)
{
    if (max_rows > 0 && max_cols > 0)
    {
        return true; // Оба значения положительные
    }
    else
    {
        cout << "Ошибка: Количество строк и столбцов должно быть положительным числом." << endl;
        return false; // Хотя бы одно значение не положительное
    }
}
