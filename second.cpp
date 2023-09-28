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
    srand(steady_clock::now().time_since_epoch().count()); // ������������� ��-����� ��������������� ����� ��� rand()
    for (int i = 0; i < size; i++) {
        arr[i] = rand(); // �� 0 �� 32767
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


    cout << "��������, ������� ���������� �����: ";
    cin >> requiredNum;

    // enumSearch
    time_point<steady_clock> start1 = steady_clock::now();
    int enumResult = enumSearch(requiredNum, size, fromTrashToGold);
    time_point<steady_clock> fin1 = steady_clock::now();
    long dur1 = duration_cast<milliseconds>(fin1 - start1).count();

    // ���������� ��� ��������� ������
    time_point<steady_clock> start3 = steady_clock::now();
    sort(fromTrashToGold, fromTrashToGold + size);
    time_point<steady_clock> fin3 = steady_clock::now();
    long dur3 = duration_cast<milliseconds>(fin3 - start3).count();

    // binarySearch
    time_point<steady_clock> start2 = steady_clock::now();
    int binaryResult = binarySearch(requiredNum, size, fromTrashToGold);
    time_point<steady_clock> fin2 = steady_clock::now();
    long dur2 = duration_cast<milliseconds>(fin2 - start2).count();

    // ����������
    if (enumResult != -1) {
        cout << "������� �������� � enumSearch: " << enumResult << endl;
    }
    else {
        cout << "�������� �� ������� � enumSearch" << endl;
    }

    if (binaryResult != -1) {
        cout << "������� �������� � binarySearch: " << binaryResult << endl;
    }
    else {
        cout << "�������� �� ������� � binarySearch" << endl;
    }

    cout << "����� ���������� enumSearch: " << dur1 << " ��" << endl;
    cout << "����� ���������� binarySearch: " << dur2 << " ��" << endl;
    cout << "����� ���������� sort: " << dur3 << " ��" << endl;


    delete[] fromTrashToGold;

    return 0;
}
