#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

// ��������� ��� �������� ������ � ��������
using namespace std;

struct Student {

    string name;
    string surname;
    string patronymic;

    int marks[5]; // ������ �� 5 �����������

};

// ������� ��� ������ � �������� ���������
int input_students(Student students[], int count); //

int output_students(Student students[], int count);// ����� ������ � ���������

int search_student(Student students[], int count, string name, string surname, string patronymic); // ������� ������ �������� �� ���

void search_max_mark_student(Student students[], int count, int subject); //������� ������ �������� � ������������ ������ �� ��������� ��������; 

void sort_students_by_name(Student students[], int count); // ���������� ��������� �� ���

void sort_students_by_average(Student students[], int count); // ���������� ��������� �� �������� �����

int FileInputOutputBinary(int array[], int n, const int MAX_SIZE);//������� ������/������ ������� � �������� ����, �� ���� �������� ������ �� ������� ��������.
