#include <iostream>
using namespace std;
int main() {
    setlocale(0, "rus");
    int f;
    int d = 0;
    //srand(time(0));
    /*const int N = 9;
    int arr[N];*/
    int n;
    cout << "Введите кол-во элементов: ";
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        //arr[i] = rand() % 61 - 20; // [0...60] --> [-20...40]
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1.
    cout << "Найти минимальный элемент массива" << endl;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[d]) {
            d = i;
        }
    }
    arr[d] = arr[n / 2];

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 2.
    cout << "indexes: ";
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            cout << i << " ";
        }
    }
    cout << endl;
    // 3.
    cout << " Найти две пары с одинаковыми знаками ";
    f = 0;
    for (int g = 1; g < n; g++) {
        if (arr[g] * arr[g - 1] >= 0) {
            f++;
        }
    }
    if (f >= 2) {
        cout << "Две пары есть";
    }
    else {
        cout << "Двух пар нет";
    }

    delete[] arr;
}
