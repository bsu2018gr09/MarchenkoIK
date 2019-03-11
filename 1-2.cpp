﻿// 1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.//
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.//

#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

//Функции//
void givememory(int*&a, int n);
void randominitarray(int *a, int n, int min, int max);
void printarray(int *a, int n);
void deletememory(int*a);

//выделение памяти

void givememory(int*&a, int n)
{
	a = new(nothrow)int[n];
	if (!a) 
	{
		cout << "error" << "\n";
	}
}

//инициализируем массив

void randominitarray(int *a, int n, int min, int max)
{ 
	srand(time(0));
	max++;
	int tmp = max - min;
	for (int i = 0; i < n; i++; ++a)
	{
		*(a) = rand() % tmp + min;
	}
}



//печать массива
void printarray(int*  a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << *(a++) << " ";
	}
	cout << '\n';
}



//освобождение памяти
void deletememory(int*a)
{
	delete a;
}

int main()
{
	int n;
	cin >> n;
	int *a = nullptr;
	int N{0}, cnt{0};

	printarray(arr, N); 
	cout << endl;
	for (int i = N - 1; i >= 0; --i)
	{  
		if (*(a + i) > 0)
		{
			swap(*(a + i), *(a + N - 1 - cnt));
			cnt++;
		}
	}
	for (int j = 0; j < N; ++j) 
		for (int i = 0; i < N; ++i)
		{
		 	if (*(Arr + i) < *(Arr + i + 1))
				if (*(Arr + i + 1) <= 0)
					swap(*(Arr + i), *(Arr + i + 1));
		}
	cout << endl;
	givememory(a, n);
	randominitarray(a, n, -5, 5);
	printarray(a, n);
	printarray(a, n);
	deletememory(a);
}

//P.S. Функции инициализации и печати честно скоммуниждены из прошлых работ. Функция сортировки работала некорректно. Сделал так.
