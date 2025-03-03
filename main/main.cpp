#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

#define c cout
#define e endl


void task1() {
    ifstream file1("file1.txt");
    ifstream file2("file2.txt");

    if (!file1.is_open() || !file2.is_open()) {
        c << "Не вдалося відкрити один із файлів!" << e;
        return;
    }

    string line1, line2;
    int lineNumber = 1;
    bool allMatch = true;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            allMatch = false;
            c << "Рядок " << lineNumber << " не співпадає:" << e;
            c << "file1: " << line1 << e;
            c << "file2: " << line2 << e;
        }
        lineNumber++;
    }


    while (getline(file1, line1)) {
        allMatch = false;
        c << "Додатковий рядок у file1 (" << lineNumber << "): " << line1 << e;
        lineNumber++;
    }

    while (getline(file2, line2)) {
        allMatch = false;
        c << "Додатковий рядок у file2 (" << lineNumber << "): " << line2 << e;
        lineNumber++;
    }

    if (allMatch) {
        c << "Усі рядки співпадають." << e;
    }

    file1.close();
    file2.close();
}


void task2() {
    ifstream input("text.txt");
    ofstream output("statistics.txt");

    if (!input.is_open()) {
        c << "Не вдалося відкрити файл text.txt" << e;
        return;
    }

    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
    string line;

    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯ";
    string consonants = "бвгґджзйклмнпрстфхцчшщБВГҐДЖЗЙКЛМНПРСТФХЦЧШЩ";

    while (getline(input, line)) {
        lineCount++;
        for (char ch : line) {
            if (isdigit(ch)) digitCount++;
            if (vowels.find(ch) != string::npos) vowelCount++;
            if (consonants.find(ch) != string::npos) consonantCount++;
            charCount++;
        }
        charCount++;
    }

    output << "Кількість символів: " << charCount << e;
    output << "Кількість рядків: " << lineCount << e;
    output << "Кількість голосних: " << vowelCount << e;
    output << "Кількість приголосних: " << consonantCount << e;
    output << "Кількість цифр: " << digitCount << e;

    c << "Статистику збережено у файл 'statistics.txt'" << e;

    input.close();
    output.close();
}


void task3() {
    ifstream input("text.txt");
    ofstream output("modified_text.txt");

    if (!input.is_open()) {
        c << "Не вдалося відкрити файл text.txt" << e;
        return;
    }

    string line;
    vector<string> lines;

    while (getline(input, line)) {
        lines.push_back(line);
    }
    input.close();

    if (lines.empty()) {
        c << "Файл порожній." << e;
        return;
    }

    lines.pop_back();  

    for (const string& l : lines) {
        output << l << e;
    }

    c << "Останній рядок видалено. Результат у файлі 'modified_text.txt'" << e;
    output.close();
}


void task4() {
    ifstream input("text.txt");

    if (!input.is_open()) {
        c << "Не вдалося відкрити файл text.txt" << e;
        return;
    }

    string line;
    size_t maxLength = 0;

    while (getline(input, line)) {
        if (line.length() > maxLength) {
            maxLength = line.length();
        }
    }

    c << "Довжина найдовшого рядка: " << maxLength << e;
    input.close();
}

int main() {
    system("chcp 1251>null");
    int choice;

    c << "Оберіть завдання:" << e;
    c << "1 - Порівняння рядків у двох файлах" << e;
    c << "2 - Статистика текстового файлу" << e;
    c << "3 - Видалення останнього рядка" << e;
    c << "4 - Довжина найдовшого рядка" << e;
    c << "Ваш вибір: ";
    cin >> choice;

    switch (choice) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    default:
        c << "Невірний вибір." << e;
    }

    return 0;
}
