#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace chrono;


int* createArr(int size) {
    int* arr = new int[size];
    srand(steady_clock::now().time_since_epoch().count()); // инициализация системы псевдослучайных чисел для rand()
    for (int i = 0; i < size; i++) {
        arr[i] = rand(); // от 0 до 32767
    }
    return arr;
}

void printArr(int size, int* arr) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void shakerSwap(int a[], int i) {
    int buff = a[i];
    a[i] = a[i - 1];
    a[i - 1] = buff;
}
void shakerSort(int n, int a[])
{
    int leftMark = 1;
    int rightMark = n - 1;
    while (leftMark <= rightMark)
    {
        for (int i = rightMark; i >= leftMark; i--
            )
            if (a[i - 1] > a[i]) shakerSwap(a, i);
        leftMark++;
        for (int i = leftMark; i <= rightMark;
            i++)
            if (a[i - 1] > a[i]) shakerSwap(a, i);
        rightMark--;
    }
}

void insertSort(int n, int a[]) {
    int buff = 0, j;
    for (int i = 1; i < n; i++)
    {
        buff = a[i];
        for (j = i - 1;
            j >= 0 && a[j] < buff; j--)
            a[j + 1] = a[j];
        a[j + 1] = buff;
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int* fromTrashToGold = createArr(size);

    cout << "Созданный массив: ";
    //printArr(size, fromTrashToGold);
    cout << "Шейкер-сортировка: ";
    time_point<steady_clock> start = steady_clock::now();
    //shakerSort(size, fromTrashToGold);
    //printArr(size, fromTrashToGold);
    cout << "Сортировка вставками: ";
    insertSort(size, fromTrashToGold);
    //printArr(size, fromTrashToGold);
    time_point<steady_clock> fin = steady_clock::now();
    long dur = duration_cast<milliseconds>(fin - start).count();
    cout << dur;

    delete[] fromTrashToGold;

    return 0;
}
