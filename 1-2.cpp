// 1-2
//

//Положительные элементы массива А(N) переставить в конец массива, сохраняя порядок следования.//
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.//

#include <iostream>
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
void TotalSort(int* Arr, int N) {
	int cnt = 0;
	int flag = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (*(Arr + i) > 0) {
			swap(*(Arr + i), *(Arr + N - 1 - cnt));
			cnt++;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (*(Arr + j) < *(Arr + j + 1)) {
				if (*(Arr + j + 1) <= 0) {
					swap(*(Arr + j), *(Arr + j + 1));
					flag++;
				}
			}
		}
		if (!flag) {break;}
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
	cout << '\n';
	TotalSort(Arr, N);
	cout << '\n';
	cout << "Sorting array: \n";
	PrintArr(Arr, N);
	FreeMemory(Arr);
	system("pause");
	return 0;
}
