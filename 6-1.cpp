// ConsoleApplication76.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Класс прямоугольник
// мы хотим, что бы этим классом пользовался кто-то посторонний. Например, чтобы хранить у себя в классе "обувь" размер коробки. А с твоими методами я ничего сделать не могу 
#include "pch.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Rectangle {
private:
	double x1, x2, y1, y2, dx, dy, r;
public:
	Rectangle(double a, double b, double c, double d) : x1(a), x2(b), y1(c), y2(d) {	}// Конструктор с 4 параметрами А остальные поля - мусор?????
	Rectangle() : x1(2), x2(5), y1(2), y2(0) {	}// Встроенный конструктор !!! уже НЕ встроенный. Ты эе его писал )))) и ОЧЕНЬ странные числа по умолчанию А остальные поля - мусор?????
	~Rectangle() { } // Деструктор
	void Input(); // метод ввода с клавиатуры
	void Result(); // метод вывода на экран
	void Peremeshenie(); // перемещение. Без параметра???????? Бред!!!!!
	void Size(); // изменение размера Без параметра???????? Бред!!!!!
	void Minimal(); // построение минимального чего??????
	void Сross(); // пересечение 2 прямоугольников Без параметров???????? Реально???? Бред!!!!!
};

void Rectangle::Input() {
	cout << "Enter the x coordinate of the left points" << endl; // вообще не понял!!!
	cin >> x1;
	cout << "Enter the y coordinate of the top points" << endl;// вообще не понял!!!
	cin >> y1;
	cout << "Enter the x coordinate of the right points" << endl;// вообще не понял!
	cin >> x2;
	cout << "Enter the y coordinate of the lower points" << endl;// вообще не понял!
	cin >> y2;
}

void Rectangle::Result() {
	cout << "You have entered the following rectangle coordinates::" << endl;
	cout << "A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << "B:" << "(" << x2 << "," << y1 << ")" << endl;
	cout << "C:" << "(" << x2 << "," << y2 << ")" << endl;
	cout << "D:" << "(" << x1 << "," << y2 << ")" << endl;
}
void Rectangle::Peremeshenie() {
	cout << "Enter the offset along the X-axis" << endl;
	cin >> dx;
	cout << "Enter the offset along the Y-axis" << endl;
	cin >> dy;
	cout << "Final coordinates of the rectangle:" << endl;
	cout << "A:" << "(" << x1 + dx << "," << y1 + dy << ")" << endl;
	cout << "B:" << "(" << x2 + dx << "," << y1 + dy << ")" << endl;
	cout << "C:" << "(" << x2 + dx << "," << y2 + dy << ")" << endl;
	cout << "D:" << "(" << x1 + dx << "," << y2 + dy << ")" << endl;
}

void Rectangle::Size() {
	cout << "Enter changes the size of the rectangle" << endl;
	cin >> r;
	cout << "Final coordinates of the rectangle:" << endl;
	cout << "A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << "B:" << "(" << x2 * r << "," << y1 << ")" << endl;
	cout << "C:" << "(" << x2 * r << "," << y2 << ")" << endl;
	cout << "D:" << "(" << x1 << "," << y2 << ")" << endl;

}
void Rectangle::Minimal() {// вс1, что ниже - БРЕД!!!!
	double x3, x4, y3, y4, x_min = x1, x_max = x1, y_min = y1, y_max = y1;
	cout << "The second rectangle:" << endl;
	cout << "Enter the x coordinate of the left points" << endl;
	cin >> x3;
	cout << "Enter the y coordinate of the top points" << endl;
	cin >> y3;
	cout << "Enter the x coordinate of the right points" << endl;
	cin >> x4;
	cout << "Enter the y coordinate of the lower points" << endl;
	cin >> y4;
	cout << endl;
	cout << "Coordinate of the first rectangle: " << endl;
	cout << "A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << "B:" << "(" << x2 << "," << y1 << ")" << endl;
	cout << "C:" << "(" << x2 << "," << y2 << ")" << endl;
	cout << "D:" << "(" << x1 << "," << y2 << ")" << endl;
	cout << endl;
	cout << "Coordinate of the second rectangle:" << endl;
	cout << "A:" << "(" << x3 << "," << y3 << ")" << endl;
	cout << "B:" << "(" << x4 << "," << y3 << ")" << endl;
	cout << "C:" << "(" << x4 << "," << y4 << ")" << endl;
	cout << "D:" << "(" << x3 << "," << y4 << ")" << endl;
	cout << endl;
	double A[4] = { x1,x2,x3,x4 }, B[4] = { y1,y2,y3,y4 };
	for (int i = 0; i < 4; i++)
	{
		if (x_max < A[i])
		{
			x_max = A[i];
		}
		if (y_max < B[i])
		{
			y_max = B[i];
		}
		if (x_min > A[i])
		{
			x_min = A[i];
		}
		if (y_min > B[i])
		{
			y_min = B[i];
		}
	}
	cout << "Rectangle containing the two previous: " << endl;
	cout << " A:" << "(" << x_min << "," << y_max << ")" << endl;
	cout << " B:" << "(" << x_max << "," << y_max << ")" << endl;
	cout << " C:" << "(" << x_max << "," << y_min << ")" << endl;
	cout << " D:" << "(" << x_min << "," << y_min << ")" << endl;
}
void Rectangle::Сross() {
	double x3, x4, y3, y4, x_min = x1, x_max = x1, y_min = y1, y_max = y1, x1_sred, x2_sred, y1_sred, y2_sred;
	cout << "The second rectangle:" << endl;
	cout << "Enter the x coordinate of the left points" << endl;
	cin >> x3;
	cout << "Enter the y coordinate of the top points" << endl;
	cin >> y3;
	cout << "Enter the x coordinate of the right points" << endl;
	cin >> x4;
	cout << "Enter the y coordinate of the lower points" << endl;
	cin >> y4;
	cout << endl;
	cout << "Coordinate of the first rectangle: " << endl;
	cout << " A:" << "(" << x1 << "," << y1 << ")" << endl;
	cout << " B:" << "(" << x2 << "," << y1 << ")" << endl;
	cout << " C:" << "(" << x2 << "," << y2 << ")" << endl;
	cout << " D:" << "(" << x1 << "," << y2 << ")" << endl;
	cout << endl;
	cout << "Coordinate of the second rectangle: " << endl;
	cout << "A:" << "(" << x3 << "," << y3 << ")" << endl;
	cout << "B:" << "(" << x4 << "," << y3 << ")" << endl;
	cout << "C:" << "(" << x4 << "," << y4 << ")" << endl;
	cout << "D:" << "(" << x3 << "," << y4 << ")" << endl;
	cout << endl;
	double A[4] = { x1,x2,x3,x4 }, B[4] = { y1,y2,y3,y4 };
	for (int i = 0; i < 4; i++)
	{
		if (x_max < A[i])
		{
			x_max = A[i];
		}
		if (y_max < B[i])
		{
			y_max = B[i];
		}
		if (x_min > A[i])
		{
			x_min = A[i];
		}
		if (y_min > B[i])
		{
			y_min = B[i];
		}
	}


	for (int i = 0; i < 4; i++)
	{
		if ((A[i] != x_max) && (A[i] != x_min))
		{
			x1_sred = A[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((A[i] != x_max) && (A[i] != x_min) && (A[i] != x1_sred))
		{
			x2_sred = A[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((B[i] != y_max) && (B[i] != y_min))
		{
			y1_sred = B[i];
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if ((B[i] != y_max) && (B[i] != y_min) && (B[i] != y1_sred))
		{
			y2_sred = B[i];
			break;
		}
	}
	cout << "The rectangle formed by the intersection of the previous 2 has the following coordinates: " << endl;
	cout << "A:" << "(" << x1_sred << "," << y2_sred << ")" << endl;
	cout << "B:" << "(" << x2_sred << "," << y2_sred << ")" << endl;
	cout << "C:" << "(" << x2_sred << "," << y1_sred << ")" << endl;
	cout << "D:" << "(" << x1_sred << "," << y1_sred << ")" << endl;

}
int main()
{
	cout << "Selected actions: \n 1 - Input \n 2 - Output \n 3 - Movement(peremeshenie) \n 4 - Transform size\n" << endl;
	cout << " 5 - Rectangle containing the two previous\n 6 - The rectangle formed by the intersection of the previous 2\n 0 - Exit\n" << endl;
		Rectangle ObjectA; // Создаем объект без параметров, то есть будет использован конструктор по умолчанию
	char Control;
	cout << "->";
	cin >> Control;


	switch (Control)
	{

	case '1':
		ObjectA.Input();
		cout << "->";
		cin >> Control;
	case '2':
		ObjectA.Result();
		cout << "->";
		cin >> Control;
	case '3':
		ObjectA.Peremeshenie();
		cout << "->";
		cin >> Control;
	case '4':
		ObjectA.Size();
		cout << "->";
		cin >> Control;
	case '5':
		ObjectA.Minimal();
		cout << "->";
		cin >> Control;
	case '6':
		ObjectA.Сross();
		cout << "->";
		cin >> Control;
	case '0': break;
	}

	return 0;
}
//Идею с построением пересечения честно скоммуниздил. 
//По вводу команды 0 выход может не выполняться. Проверил в разных компиляторах, почему так, не знаю.
