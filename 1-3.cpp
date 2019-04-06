﻿// третья задача на 27.02.2019.cpp
//Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.
#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;

void RandomArray(int *arr, int n)
{
	cout << "\n Array of prime nubers in [1;100]:\n\n";
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << "  " << arr[i];
	}
}

void SortPrimes(int *arr, int n)
{
	int *primes = new int[n], k = 0;

	for (int i = 0; i < n; i++)      // Поиск в arr простых чисел и их запись в primes
	{
		int a = arr[i];
		if (a % 2 != 0 || a == 2)
		{
			float root = sqrt((float)a);
			int j = 2;
			while (j <= root && a % j != 0) j++;
			if (j > root) primes[k++] = a;
		}
	}

	if (k == 0) cout << "\n\nArray have not prime numbers.\n";
	else
	{
		for (int i = 0; i < k; i++)      // Сортировка "пузырьком" primes
		{
			for (int j = 0; j < k - i - 1; j++)
			{
				if (primes[j] > primes[j + 1])
				{
					int t = primes[j];
					primes[j] = primes[j + 1];
					primes[j + 1] = t;
				}
			}
		}
		cout << "\n\nPrime numbers of array in vozrastanie:\n\n";// а зачем мне это???? Мне надо было ИСХОДНЫЙ массив "пересортировать"
		for (int i = 0; i < k; i++) cout << "  " << primes[i];
	}

}

int main()
{

	cout << "Size of array:\n  ";
	int n; cin >> n;

	int *arr = new int[n];//где проверка

	RandomArray(arr, n);
	SortPrimes(arr, n);

	system("pause > null");
	return 0;
}
