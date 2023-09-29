#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;


int* createArr(long size) {
    int* arr = new int[size];
    srand(steady_clock::now().time_since_epoch().count()); // инициализация си-стемы псевдослучайных чисел для rand()
    for (int i = 0; i < size; i++) {
        arr[i] = rand(); // от 0 до 32767
    }
    return arr;
}

void printArr(long size, int* arr) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int enumSearch(int val, long size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == val)
            return i;
    }
    return -1;
}

int binarySearch(int val, long size, int
    a[])
{
    int lastIndex = size - 1;
    int firstIndex = 0;
    while (lastIndex >= firstIndex)
    {
        int middleIndex = (firstIndex +
            lastIndex) / 2;
        if (a[middleIndex] == val)
        {
            return middleIndex;
        }
        else
            if (a[middleIndex] < val)
                firstIndex = middleIndex + 1;
            else
                if (a[middleIndex] > val)
                    lastIndex = middleIndex - 1;
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    long size = 1000000000;
    int requiredNum;

    int* fromTrashToGold = createArr(size);

 
    cout << "Значение, которое необходимо найти: ";
    cin >> requiredNum;

    // enumSearch
    time_point<steady_clock> start1 = steady_clock::now();
    int enumResult = enumSearch(requiredNum, size, fromTrashToGold);
    time_point<steady_clock> fin1 = steady_clock::now();
    long dur1 = duration_cast<milliseconds>(fin1 - start1).count();

    // Сортировка для бинарного поиска
    time_point<steady_clock> start3 = steady_clock::now();
    sort(fromTrashToGold, fromTrashToGold + size);
    time_point<steady_clock> fin3 = steady_clock::now();
    long dur3 = duration_cast<milliseconds>(fin3 - start3).count();

    // binarySearch
    time_point<steady_clock> start2 = steady_clock::now();
    int binaryResult = binarySearch(requiredNum, size, fromTrashToGold);
    time_point<steady_clock> fin2 = steady_clock::now();
    long dur2 = duration_cast<milliseconds>(fin2 - start2).count();

    // Результаты
    if (enumResult != -1) {
        cout << "Позиция значения в enumSearch: " << enumResult << endl;
    }
    else {
        cout << "Значение не найдено в enumSearch" << endl;
    }

    if (binaryResult != -1) {
        cout << "Позиция значения в binarySearch: " << binaryResult << endl;
    }
    else {
        cout << "Значение не найдено в binarySearch" << endl;
    }

    cout << "Время выполнения enumSearch: " << dur1 << " мс" << endl;
    cout << "Время выполнения binarySearch: " << dur2 << " мс" << endl;
    cout << "Время выполнения sort: " << dur3 << " мс" << endl;


    delete[] fromTrashToGold;

    return 0;
}

