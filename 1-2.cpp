// 1-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.//
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.//

#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

//Функции//
void giveMemory(int*&Arr, int n);
void randomInitArray(int *arr, int n, int min, int max);
//void sort(int *Arr, int n);
void printArr(int*  arr, int n);
void deleteMemory(int*Arr);

int main()
{
	int n;
	cin >> n;
	int *Arr = nullptr;
	int N{ 0 }, cnt{ 0 };

	printArr(Arr, N); cout << endl;
	for (int i = N - 1; i >= 0; --i) { //переставляет положительные элементы в конец не меняя порядок 
		if (*(Arr + i) > 0) {
			swap(*(Arr + i), *(Arr + N - 1 - cnt));
			cnt++;
		}
	}
	for (int j = 0; j < N; ++j) //расставляет отрицательные элементы в порядке убывания 
		for (int i = 0; i < N; ++i) {
			if (*(Arr + i) < *(Arr + i + 1))
				if (*(Arr + i + 1) <= 0)
					swap(*(Arr + i), *(Arr + i + 1));
		}
	cout<<endl;
	giveMemory(Arr, n);
	randomInitArray(Arr, n, -5, 5);
	printArr(Arr, n);
	printArr(Arr, n);
	deleteMemory(Arr);
}

//выделение памяти

void giveMemory(int*&arr, int n) {
	arr = new(nothrow)int[n];
	if (!arr) {
		cout << "error" << "\n";
	}
}

//инициализируем массив

void randomInitArray(int *arr, int n, int min, int max) { 
	srand(time(0));
	max++;
	int tmp = max - min;
	for (int i = 0; i < n; i++, ++arr)
	{
		*(arr) = rand() % tmp + min;
	}
}



//печать массива
void printArr(int*  arr, int n) {
	for (int i = 0; i < n; ++i) {
		cout << *(arr++) << "   ";
	}
	cout << '\n';
}



//освобождение памяти
void deleteMemory(int*Arr) {
	delete Arr;
}



//P.S. Функции инициализации и печати честно скоммуниждены из прошлых работ. Функция сортировки работала некорректно. Сделал так.
//P.P.S. Все на корявом (только в этом году начал учить) английском, т. к. компилятор на моем железе упорно не хочет работать с setlocale
