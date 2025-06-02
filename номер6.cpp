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
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const size_t n);

/**
 * @brief Заполнение массива автоматически случайными числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона
 * @param max - максимальное значение диапазона
 */
void fillArrayRandom(int* arr, const size_t n, const int min, const int max);

/**
 * @brief Проверяет диапазон
 * @param min - минимальное значение диапазона
 * @param max - максимальное значение диапазона
 */
void checkRange(const int min, const int max);

/**
 * @brief Заменяет минимальный элемент массива на средний
 * @param arr Массив целых чисел
 * @param n Размер массива
 * @param result Результирующий массив (копия исходного)
 */
void replaceMinWithAverage(const int arr[], int result[], const size_t n);

/**
 * @brief Проверяет, содержит ли массив две пары соседних элементов с одинаковыми знаками
 * @param arr Указатель на массив
 * @param n Количество элементов
 * @return true если есть две пары, иначе false
 */
bool hasTwoPairsWithSameSign(const int arr[], const size_t n);

/**
 * @brief Выводит индексы элементов, значения которых больше предыдущих
 * @param arr Указатель на массив
 * @param n Количество элементов
 */
void printIndicesGreaterThanPrevious(const int arr[], const size_t n);

/**
 * @brief Заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона
 * @param max - максимальное значение диапазона
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
    case