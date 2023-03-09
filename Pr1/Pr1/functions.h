#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

// Структура для хранения данных о студенте
using namespace std;

struct Student {

    string name;
    string surname;
    string patronymic;

    int marks[5]; // Оценки по 5 дисциплинам

};

// Функции для работы с массивом студентов
int input_students(Student students[], int count); //

int output_students(Student students[], int count);// Вывод данных о студентах

int search_student(Student students[], int count, string name, string surname, string patronymic); // Функция поиска студента по ФИО

void search_max_mark_student(Student students[], int count, int subject); //функцию поиска студента с максимальным баллом по заданному предмету; 

void sort_students_by_name(Student students[], int count); // Сортировка студентов по ФИО

void sort_students_by_average(Student students[], int count); // Сортировка студентов по среднему баллу

int FileInputOutputBinary(int array[], int n, const int MAX_SIZE);//функции чтения/записи массива в двоичный файл, то есть хранение данных на внешнем носителе.
