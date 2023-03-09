#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "functions.h"
using namespace std;

// Ввод данных о студентах


int input_students(Student students[], int count) {

    for (int i = 0; i < count; ++i) {


        cout << "Введите ФИО студента " << i + 1 << ": ";
        getline(cin, students[i].name);
        getline(cin, students[i].surname);
        getline(cin, students[i].patronymic);


        for (int j = 0; j < 5; ++j)  
        {
            while (true) // буду проверять на корректность вводимых данных  что введенные оценки являются числами в диапазоне от 1 до 5).
            {
                cout << "Введите оценку для предмета " << j + 1 << ": ";
                if (cin >> students[i].marks[j] && students[i].marks[j] >= 1 && students[i].marks[j] <= 5) {
                    break;
                }
                cout << "Ошибка ввода. Оценка должна быть числом в диапазоне от 1 до 5." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}

// Вывод данных о студентах
int output_students(Student students[], int count) {

    setlocale(LC_ALL, "0");

    for (int i = 0; i < count; ++i) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Имя: " << students[i].name << endl;
        cout << "Фамилия: " << students[i].surname << endl;
        cout << "Отчество: " << students[i].patronymic << endl;

        int sum = 0;
        for (int j = 0; j < 5; ++j) {
            cout << "Оценка " << j + 1 << ": " << students[i].marks[j] << endl;
            sum += students[i].marks[j];
        }
        double average = sum / 5.0;
        cout << "Средний балл: " << average << endl;

        cout << endl;

    }
    return 0;
}
// Функция поиска студента по ФИО
int search_student(Student students[], int count, string name, string surname, string patronymic) {

    for (int i = 0; i < count; ++i) {
        if (students[i].name == name && students[i].surname == surname && students[i].patronymic == patronymic) {

            cout << "Найден студент " << name << "\n" << surname << "\n" << patronymic << ":" << endl;

            cout << "Оценки: ";
            for (int j = 0; j < 5; ++j) {
                cout << students[i].marks[j] << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "Студент " << name << " не найден." << endl;
    return 1;
}

void search_max_mark_student(Student students[], int count, int subject) //функцию поиска студента с максимальным баллом по заданному предмету; 
{
    double max_mark = -1.0;
    int max_mark_student_index = -1;
        for (int i = 0; i < count; ++i){
            if (students[i].marks[subject] > max_mark){
                max_mark = students[i].marks[subject];
                max_mark_student_index = i;
            }
        }

        if (max_mark_student_index != -1){
            cout << "Студент с максимальным баллом по предмету " << subject + 1 << ": " << students[max_mark_student_index].name << endl;
            cout << "Балл: " << max_mark << endl;
        }
        else{
            cout << "Нет студентов, имеющих оценки по предмету " << subject + 1 << endl;
        }
}
// Сортировка студентов по ФИО
void sort_students_by_name(Student students[], int count) {
    sort(students, students + count, [](const Student& a, const Student& b) {
        return a.name < b.name;
        });
}

// Сортировка студентов по среднему баллу
void sort_students_by_average(Student students[], int count) {
    sort(students, students + count, [](const Student& a, const Student& b) {
        double average_a = 0.0;
        double average_b = 0.0;
        for (int i = 0; i < 5; ++i) {
            average_a += a.marks[i];
            average_b += b.marks[i];
        }
        average_a /= 5.0;
        average_b /= 5.0;
        return average_a > average_b;
        });
}

//функции чтения/записи массива в двоичный файл, то есть хранение данных на внешнем носителе.
int FileInputOutputBinary(int array[], int n, const int MAX_SIZE) {

    array[MAX_SIZE];

    ofstream outFile("C:/Users/admin/Documents/data.bin", ios::binary);
    ifstream inFile("C:/Users/admin/Documents/data.bin", ios::binary);

    // Ввод элементов массива и запись в файл
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        outFile.write((char*)&array[i], sizeof(array[i]));
    }
    outFile.close();

    // Чтение элементов массива из файла и вывод
    cout << "Элементы массива из файла: ";
    for (int i = 0; i < n; i++) {
        inFile.read((char*)&array[i], sizeof(array[i]));
        cout << array[i] << " ";
    }
    cout << endl;
    inFile.close();

    return 0;

}



