// 0-4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*
Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
*/
#include "pch.h"
#include <iostream>
#include <clocale>
#include <ctime>
#include <algorithm>

using namespace std;

int getCntOfArr();
void initRandArr(int*, int);
void sortArrElement(int*, int, int);
void sortArrElementMain(int*, int);
void printArr(int*, int);


void initRandArr(int *Arr, int n)
{
	for (int i{ 0 }; i < n; ++i)
		for (int i = 0; i < n; ++i) {
			*(Arr + i) = rand() % 100;
		}
	return;
}

void printArr(int* Arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << *(Arr + i) << ",";
	}
	cout << "\n";
	return;
}

int main()
{
	srand(time(0));
	int n{ getCntOfArr() };
	int *Arr = new (nothrow) int[n];
	if (!Arr)
	{
		cout << "Error with doing memory\n";
		system("pause");
		return 0;
	}
	initRandArr(Arr, n);
	sortArrElementMain(Arr, n);
	delete[] Arr;
	Arr = nullptr;
	system("pause");
	return 0;
}

int getCntOfArr()
{
	int cnt{ 0 };
	do {
		cout << "Input the positive integer size of array ";
		cin >> cnt;
		if (cnt <= 0)
			cout << "Error!It is not positive integer!\n";
		else
			break;
	} while (1);
	return cnt;
}

void sortArrElement(int *Array, int n, int k)
{
	char flag{ 0 };
	for (int i{ k }; i < (n - 1); ++i)
	{
		flag = 0;
		for (int j{ k }; j < (n - 1 - (i - k)); ++j)
			if (*(Array + j) > *(Array + (j + 1)))
			{
				flag = 1;
				swap(*(Array + j), *(Array + (j + 1)));
			}
		if (!flag)
			break;
	}
}

void sortArrElementMain(int *Array, int n)
{
	int k{ 0 };
	do {
		cout << "Start to element with number: ";
		cin >> k;
		if ((k < 0) || (k >= n))
			cout << "Error!\n";
		else
			break;
	} while (1);
	sortArrElement(Array, n, k);
}