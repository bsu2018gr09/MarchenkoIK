/*1-1
Даны точки плоскости своими координатами в виде двух одномерных массивов (случайные числа).
Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
*/

#include <iostream> 
#include <time.h> 
#include <iomanip>
#include "windows.h"

using namespace std;

void randArr(int*A, int N, int l, int r);
void freeMemory(int*A);
void Dist(int*X, int*Y, int*D, int N, int a, int b, int c);
void Sort(int*X, int*Y, int*D, int N);
void printArr(int*A, int*B, int*D, int N);

int *InitArr(int N) {
	int *A = new int[N];
	return A;
}

int main()
{
	int N, a, b, c;
	cout << "Input N ";
	cin >> N;
	cout << "Input a, b, c for ax+by+c=0" << '\n';
	cin >> a >> b >> c;
	int *X = InitArr(N);
	int *Y = InitArr(N);
	/**void giveMemory(int*&A, int N)*/
	randArr(X, N, -N / 2, N / 2);
	randArr(Y, N, -N / 2, N / 2);
	cout << "The array is filled with random numbers" << '\n';
	Sleep(1000);
	int *D = InitArr(N);
	Dist(X, Y, D, N, a, b, c);
	Sort(X, Y, D, N);
	printArr(X, Y, D, N);
	freeMemory(X);
	freeMemory(Y);
	freeMemory(D);
	system("pause");
}

/*void giveMemory(int*&A, int N)
{
	A = new(nothrow)int[N];
	if (!A) 
	{
		cout << "error" << "\n";
	}
}*/

void randArr(int*A, int N, int l, int r) {
	if (!A) {
		cout << "error";
		system("pause");
	}
	srand(time(0));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % (l - r) + l;
	}
}



void Dist(int*X, int*Y, int*D, int N, int a, int b, int c)
{
	for (int i = 0; i < N; i++)
	{
		*(D + i) = abs(a**(X + i) + b * *(Y + i) + c) / sqrt(a*a + b * b);
	}
}

void Sort(int*X, int*Y, int*D, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (*(D + j) > *(D + j + 1))
			{
				swap(*(X + j), *(X + j + 1));
				swap(*(Y + j), *(Y + j + 1));
				swap(*(D + j), *(D + j + 1));
			}
		}
	}
}

void printArr(int*A, int*B, int*D, int N) {
	for (int i = 0; i < N; i++)
		cout << '(' << *(A + i) << ' ' << *(B + i) << ')' << " " << *(D + i) << '\n';
}

void freeMemory(int*A)
{
	delete[]A;
}
