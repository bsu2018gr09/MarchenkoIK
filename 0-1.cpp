// 0-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

/*
	В массиве размера N, заполненного случ.числами от 0 до 10, подсчитать количество элементов, встречающихся более одного раза.
*/

#include "pch.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void initRandArr(int*, int);
int numberOfCopies(int*, int);
void bubbleSort(int*, int);
void outputArr(int*, int);

int main() {

	int N = 255;
	int* arr = new int[N];
	if (!arr) {
		cout << "Error with doing memory\n";
		exit(1);
	}
	initRandArr(arr, N);
	outputArr(arr, N);
	cout << '\n';
	cout << "The number of copies: " << numberOfCopies(arr, N);
	cout << '\n';
	delete[] arr;
	arr = nullptr;

	system("pause");
	return 0;
}

void initRandArr(int* arr, int N) {
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
		*(arr + i) = rand() % 10;
}

void bubbleSort(int* arr, int N) {
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		for (int b = i + 1; b < N; b++) {
			if (*(arr + i) > *(arr + b)) {
				tmp = *(arr + i);
				*(arr + i) = *(arr + b);
				*(arr + b) = tmp;
			}
		}
	}
}

int numberOfCopies(int* arr, int N) {
	bubbleSort(arr, N);
	int b = 0;
	int k = 0;
	for (int i = 0; i < N; ++i) {
		while (arr[i] == arr[i + 1]) {
			++b;
			++i;
		}
		if (b > 0) {
			++k;
			b = 0;
		}
	}
	return k;
}

void outputArr(int* arr, int N) {
	for (int i = 0; i < N; ++i)
		cout << *(arr + i) << ' ';
}
