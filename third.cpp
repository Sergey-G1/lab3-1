#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <set>


using namespace std;
using namespace chrono;

struct Record {
    string surname;
    string phone;
    int roomNumber;
};

const int MAX_RECORDS = 10;
set<int> usedRoomNumbers;


int generateRoomNumber() {
    int roomNumber;
    do {
        roomNumber = rand() % 100 + 1;
    } while (usedRoomNumbers.count(roomNumber) > 0);
    usedRoomNumbers.insert(roomNumber);
    return roomNumber;
}

Record generateRandomRecord(int i) {
    Record record;
    record.surname = "Surname" + to_string(i);
    record.phone = to_string(rand() % 10) + "-" + to_string(rand() % 10) + to_string(rand() % 10);
    record.roomNumber = generateRoomNumber();
    return record;
}


void printRecord(const Record& record) {
    cout << "Имя: " << record.surname << "    Телефон: " << record.phone << "    Номер комнаты: " << record.roomNumber << endl;
}

void shakerSwap(Record records[], int i) {
    Record buff = records[i];
    records[i] = records[i - 1];
    records[i - 1] = buff;
}

void sortBySurname(Record records[], int size) {
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--) {
            if (records[i - 1].surname > records[i].surname) {
                shakerSwap(records, i);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++) {
            if (records[i - 1].surname > records[i].surname) {
                shakerSwap(records, i);
            }
        }
        rightMark--;
    }
}


void sortByRoomNumber(Record records[], int size) {
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark) {
        for (int i = rightMark; i >= leftMark; i--) {
            if (records[i - 1].roomNumber > records[i].roomNumber) {
                shakerSwap(records, i);
            }
        }
        leftMark++;
        for (int i = leftMark; i <= rightMark; i++) {
            if (records[i - 1].roomNumber > records[i].roomNumber) {
                shakerSwap(records, i);
            }
        }
        rightMark--;
    }
}

void searchRecord(Record records[], int size, string& key) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (records[i].surname == key or to_string(records[i].roomNumber) == key) {
            printRecord(records[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "Запись не найдена" << endl;
    }
}

int main() {
    int c;
    setlocale(LC_ALL, "Russian");
    srand(steady_clock::now().time_since_epoch().count());

    Record records[MAX_RECORDS];

    for (int i = 0; i < MAX_RECORDS; i++) {
        records[i] = generateRandomRecord(i);
    }

    cout << "Введите команду:" << endl;
    cout << "1 - Сортировка по фамилиям" << endl;
    cout << "2 - Сортировка по комнатам" << endl;
    cout << ">";
    cin >> c;
    if (c == 1) {
        sortBySurname(records, MAX_RECORDS);
        cout << "Сортировка по фамилиям:" << endl;
    }
    else if (c == 2) {
        sortByRoomNumber(records, MAX_RECORDS);
        cout << "Сортировка по комнатам:" << endl;

    }
    else {
        cout << "Неверное значение!" << endl;
        cout << "..." << endl;
        cout << "Вывод всех записей" << endl;


    }
    for (int i = 0; i < MAX_RECORDS; i++) {
        printRecord(records[i]);
    }

    cout << "Введите фамилию или номер комнаты для поиска: ";
    string searchKey;
    cin >> searchKey;
    cout << "Результаты поиска:" << endl;
    searchRecord(records, MAX_RECORDS, searchKey);

    return 0;
}
