#include <iostream>
#include <memory>      // std::unique_ptr
#include <cstdlib>     // std::exit

using std::cin;
using std::cout;
using std::cerr;

// ---------- тип "динамический массив" ----------
struct DynArray
{
    std::unique_ptr<int[]> data;
    std::size_t            size{0};

    explicit DynArray(std::size_t n)
        : data(new int[n]), size(n) {}
};

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

void readArray(DynArray& a)
{
    for (std::size_t i = 0; i < a.size; ++i) {
        if (!(cin >> a.data[i])) {
            cerr << "Ошибка ввода: ожидалось целое число.\n";
            std::exit(EXIT_FAILURE);
        }
    }
}

// ---------- вывод ----------
void printArray(const DynArray& a)
{
    for (std::size_t i = 0; i < a.size; ++i) cout << a.data[i] << ' ';
    cout << '\n';
}

// ---------- алгоритмы ----------
std::size_t indexOfMin(const DynArray& a)
{
    if (a.size == 0) return 0;
    std::size_t minIdx = 0;
    for (std::size_t i = 1; i < a.size; ++i)
        if (a.data[i] < a.data[minIdx]) minIdx = i;
    return minIdx;
}

void replaceMinByMiddle(DynArray& a)
{
    a.data[indexOfMin(a)] = a.data[a.size / 2];
}

void printIncreasingIndexes(const DynArray& a)
{
    cout << "indexes: ";
    for (std::size_t i = 1; i < a.size; ++i)
        if (a.data[i] > a.data[i - 1]) cout << i << ' ';
    cout << '\n';
}

bool hasTwoEqualSignPairs(const DynArray& a)
{
    std::size_t pairs = 0;
    for (std::size_t i = 1; i < a.size; ++i)
        if (a.data[i] * a.data[i - 1] >= 0 && ++pairs == 2) return true;
    return false;
}

// ---------- main ----------
int main()
{
    setlocale(LC_ALL, "rus");

    DynArray arr(readSize());   // один объект — и всё
    readArray(arr);
    printArray(arr);

    replaceMinByMiddle(arr);
    printArray(arr);

    printIncreasingIndexes(arr);

    cout << "Две пары с одинаковыми знаками: "
         << (hasTwoEqualSignPairs(arr) ? "есть\n" : "нет\n");
    return 0;
}
