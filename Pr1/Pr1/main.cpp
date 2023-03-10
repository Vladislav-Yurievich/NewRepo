#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	const int MAX_SIZE = 10;
	const int COUNT = 5;
	int n;
	int arr[MAX_SIZE];

	Student stud[COUNT];

	Input_Student(stud, COUNT);

	Output_Student(stud, COUNT);

	// поиск студента по ФИО
	string FIO;
	
	cout << "Введите ФИО студента для поиска: ";
	cin >> FIO;

	Search_Student(stud, COUNT, FIO);

	// сортировка студентов по среднему баллу
	
	SortAverageBall(stud, COUNT);
	cout << "\n" << "Сортировка студентов по среднему баллу: " << "\n";
	Output_Student(stud, COUNT);

	// Поиск студента с максимальным баллом по заданному предмету

	Search_Student_Max_Score(stud, COUNT, 0);

	// Функция чтения/записи массива в двоичный файл

	cout << "Введите размер массива (не больше 10): ";
	cin >> n;

	File_Input_Outputr_Binary(arr, n, MAX_SIZE);
}