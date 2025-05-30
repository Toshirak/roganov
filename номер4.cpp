#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
 * Считывает значение с клавиатуры с проверкой ввода.
 * @return Введенное пользователем значение типа double.
 * @note Если ввод некорректный, программа завершается с кодом ошибки 1.
 */
double getValue();

/**
 * Вычисляет значение функции y = tan(x) - 1/3*tan^3(x) + 1/5*tan^5(x) - 1/3.
 * @param x Входное значение аргумента функции.
 * @return Значение функции y для заданного x.
 */
double calculateFunction(const double x);

/**
 * Считывает значение шага с клавиатуры и проверяет, что оно положительное.
 * @return Положительное значение шага типа double.
 * @note Если введенное значение шага неположительное, пользователю предлагается повторить ввод.
 */
double getPositiveStep();

/**
 * Вычисляет и выводит значения функции для заданного диапазона x с указанным шагом.
 * @param startX Начальное значение x.
 * @param endX Конечное значение x.
 * @param step Шаг изменения x.
 * @note Если тангенс не существует для какого-либо x (когда cos(x) близок к нулю), выводится сообщение об ошибке.
 */
void calculateAndPrintValues(const double startX, const double endX, const double step);

/**
 * Точка входа в программу.
 * @return 0 в случае успешного выполнения, 1 в случае ошибки.
 * @note Программа запрашивает у пользователя начальное и конечное значения x, а также шаг.
 *       Если начальное значение x больше конечного, программа завершается с кодом ошибки 1.
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX = getValue();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

    double step = getPositiveStep();

    cout << "x | y" << endl;
    cout << "--------" << endl;

    calculateAndPrintValues(startX, endX, step);
    return 0;
}

/**
 * Считывает значение с клавиатуры с проверкой ввода.
 * @return Введенное пользователем значение типа double.
 * @note Если ввод некорректный, программа завершается с кодом ошибки 1.
 */
double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        exit(1);
    }
    return value;
}

/**
 * Вычисляет значение функции y = tan(x) - 1/3*tan^3(x) + 1/5*tan^5(x) - 1/3.
 * @param x Входное значение аргумента функции.
 * @return Значение функции y для заданного x.
 */
double calculateFunction(const double x)
{
    return tan(x) - 1.0 / 3.0 * pow(tan(x), 3) + 1.0 / 5.0 * pow(tan(x), 5) - 1.0 / 3;
}

/**
 * Считывает значение шага с клавиатуры и проверяет, что оно положительное.
 * @return Положительное значение шага типа double.
 * @note Если введенное значение шага неположительное, пользователю предлагается повторить ввод.
 */
double getPositiveStep()
{
    double step;
    do {
        cout << "Введите шаг: ";
        step = getValue();
        if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
        }
    } while (step <= 0);
    return step;
}

/**
 * Вычисляет и выводит значения функции для заданного диапазона x с указанным шагом.
 * @param startX Начальное значение x.
 * @param endX Конечное значение x.
 * @param step Шаг изменения x.
 * @note Если тангенс не существует для какого-либо x (когда cos(x) близок к нулю), выводится сообщение об ошибке.
 */
void calculateAndPrintValues(const double startX, const double endX, const double step)
{
    for (double x = startX; x < endX + step; x += step)
    {
        if (fabs(cos(x)) < numeric_limits<double>::epsilon())
        {
            cout << "Ошибка: Тангенс не существует для x = " << x << endl;
        }
        else
        {
            double y = calculateFunction(x);
            cout << x << " | " << y << endl;
        }
    }
}