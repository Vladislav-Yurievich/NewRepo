#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

// ��������� ��� �������� ������ � ��������

const int NUM_STUDENTS = 25;

struct Student {
	char FIO[30];
	int score[5];

	float average_score; // ������� ����
};



void Input_Student(Student stud[], int count);

void Output_Student(Student stud[], int count);

void Search_Student(Student stud[], int count, string FIO);

void SortAverageBall(Student stud[], int count);

void Search_Student_Max_Score(Student stud[], int count);