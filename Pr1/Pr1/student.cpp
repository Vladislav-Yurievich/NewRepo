#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "functions.h"
using namespace std;

// ������� ����� ���������

void Input_Student(Student stud[], int count) {
	
	for (int i = 0; i < count; i++)
	{
		cout << "\n";

		cout << "������� ���: ";
		cin.get();
		cin.get(stud[i].FIO, 30);
		cin.get();

		stud[i].average_score = 0;

		cout << "\n";

		cout << "����� �� ���������: " << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << "���� �� " << j << " ��������: ";
			cin >> stud[i].score[j];
			stud[i].average_score += stud[i].score[j];
		}

		stud[i].average_score /= 5;
	}
}

// ������� ����� ���������

void Output_Student(Student stud[], int count) {

	cout << endl << "������ ���������: " << "\n\n";

	for (int i = 0; i < count; i++)
	{
		cout << "�������: " << i + 1 << ": " << endl;

		cout << "���: " << stud[i].FIO << endl;

		int sum = 0;

		for (int j = 0; j < 5; j++)
		{
			cout << "������: " << j + 1 << ": " << stud[i].score[j] << endl;
			sum += stud[i].score[j];
		}

		double average = sum / 5.0;

		cout << "������� ���� = " << average << "\n\n";
	}

}

// ����� �������� �� ���

void Search_Student(Student stud[], int count, string FIO) {
	
	for (int i = 0; i < count; i++)
	{
		if (stud[i].FIO == FIO)
		{
			cout << "������ �������: " << FIO << ":" << endl;
			cout << "������: " << endl;

			for (int j = 0; j < 5; j++)
			{
				cout << stud[i].score[j] << " ";
			}
			cout << endl;
		}

	}
}


// ���������� ������� ��������� �� �������� �����

void SortAverageBall(Student stud[], int count) {

	Student tmp;

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (stud[i].average_score < stud[j].average_score)
			{
				tmp = stud[i];
				stud[i] = stud[j];
				stud[j] = tmp;
			}
		}
	}
}

// ������� ������ �������� � ������������ ������ �� ��������� ��������

void Search_Student_Max_Score(Student stud[], int count, int subject) {

	double max_score = -1.0;

	int max_score_student_index = -1;

	for (int i = 0; i < count; i++)
	{
		if (stud[i].score[subject] > max_score)
		{
			max_score = stud[i].score[subject];
			max_score_student_index = i;
		}
	}

	if (max_score_student_index != -1)
	{
		cout << "������� � ����. ������ �� ��������: " << subject + 1 << ": " << stud[max_score_student_index].FIO << endl;
		cout << "����: " << max_score << endl;
	}
	else {
		cout << "�� ������� ��������, ������� ����� ������ �� ��������: " << subject + 1 << endl;
	}

}


// ������� ������/������ ������� � �������� ����

int File_Input_Outputr_Binary(int arr[], int n, const int MAX_SIZE) {

	arr[MAX_SIZE];

	ofstream outFile("C:/Users/admin/Documents/data.bin", ios::binary);
	ifstream inFile("C:/Users/admin/Documents/data.bin", ios::binary);

	// input arr

	cout << "������� �������� �������: ";
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		outFile.write((char*)&arr[i], sizeof(arr[i]));
	}

	outFile.close();

	// ������ ��������� ������� �� ����� + �����

	cout << "�������� ������� �� �����: " << endl;

	for (int i = 0; i < n; i++)
	{
		inFile.read((char*)&arr[i], sizeof(arr[i]));
		cout << arr[i] << " ";
	}
	cout << endl;
	inFile.close();

	return 0;
}