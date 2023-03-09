#include <iostream>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Russian");
	const int COUNT = 3;
	const int MAX_SIZE = 11;
	Student students[COUNT];

	input_students(students, COUNT);// Ввод данных о студентах
	output_students(students, COUNT);// Вывод данных о студентах

	// Поиск студента по ФИО
	string name;
	string surname;
	string patronymic;
	cout << "Введите ФИО студента для поиска: ";
	getline(cin, name);

	search_student(students, COUNT, name, surname, patronymic);
	
	//поиск студента с максимальным баллом по заданному предмету; 
	search_max_mark_student(students, COUNT, 0);


	// Сортировка студентов по ФИО
	sort_students_by_name(students, COUNT);
	cout << "Студенты, отсортированные по ФИО:" << endl;
	output_students(students, COUNT);

	// Сортировка студентов по среднему баллу
	sort_students_by_average(students, COUNT);
	cout << "Студенты, отсортированные по среднему баллу:" << endl;
	output_students(students, COUNT);

	//функции чтения/записи массива в двоичный файл, то есть хранение данных на внешнем носителе.
	int n;
	int array[MAX_SIZE];
	cout << "Введите размер массива: ";
	cin >> n;
	FileInputOutputBinary(array, n, MAX_SIZE);

	
	return 0;
}