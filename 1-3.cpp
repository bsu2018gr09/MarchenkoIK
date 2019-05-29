// третья задача на 27.02.2019.cpp
//Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, не нарушая порядка следования других элементов.
#include <iostream>
#include <clocale>
#include <ctime>
#include <iomanip>

using namespace std;

int* GiveMemory(int N) {
	int* Arr = new(nothrow) int[N];
	if (!Arr) {
		cout << "Error!" << "\n";
		system("pause");
		exit(0);
	}
	return Arr;
}

void FreeMemory(int*& Arr) {
	delete[]Arr;
	Arr = nullptr;
	return;
}

void RandomInitArr(int* Arr, int N) {
	int a, b;
	cout << "Con 2 positive integers for create array:\n";
	cout << "first number: ";
	cin >> a;
	cout << "second number: ";
	cin >> b;
	if (a <= 0 || b <= 0) {
		cout << "It's not positive integer!\n";
		system("pause");
		exit(0);
	}
	else
		for (int i = 0; i < N; ++i) {
			*(Arr + i) = rand() % a - rand() % b;
		}
	return;
}

void PrintArr(int* Arr, int N) {
	for (int i = 0; i < N; ++i) {
		cout << *(Arr + i);
	}
	return;
}

bool PrimeNumber(int N)
{
	if (N <= 1)
	{
		return false;
	}
	bool isPrime = true;
	for (int i = 2; i <= sqrt(N); ++i)
	{
		if (N%i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}

void TotalSort(int *Arr, int N) {
	char flag{ 0 };
	for (int i = 0; i < N; ++i) {
		if (PrimeNumber(*(Arr + i))) {
			flag = 0;
			for (int j = 0; j < N; ++j) {
				if (PrimeNumber(*(Arr + j)) && *(Arr + i) < *(Arr + j)) {
					swap(*(Arr + i), *(Arr + j));
					flag++;
				}
			}
			if (!flag) {break;}
		}
	}
	return;
}

int main() {
	srand(time(0));
	int N;
	cout << "Cout the positive integer size of array: ";
	cin >> N;
	if (N <= 0) {
		cout << "It's not positive integer!\n";
		system("pause");
		exit(0);
	}
	int*Arr = GiveMemory(N);
	RandomInitArr(Arr, N);
	cout << "Starting array: \n";
	PrintArr(Arr, N);
	TotalSort(Arr, N);
	cout << "\n";
	cout <<  "Sorting array: \n";
	PrintArr(Arr, N);
	cout << "\n";
	FreeMemory(Arr);
	system("pause");
	return 0;
}

