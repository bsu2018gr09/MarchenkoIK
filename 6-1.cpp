// ConsoleApplication76.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Класс прямоугольник
// мы хотим, что бы этим классом пользовался кто-то посторонний. Например, чтобы хранить у себя в классе "обувь" размер коробки. А с твоими методами я ничего сделать не могу 
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class Rectangle
{
    int length;
    int height;

public:
    // Конструктор по умолчанию, инициализирует поля length и height значениями 0
    
    Rectangle() 
        :length(0), height(0) 
    {}

    // Конструктор с параметрами, инициализирует поля length и height значениями
    // _length и _height, переданными в качестве параметров, соответственно
    Rectangle(int _length, int _height):length(_length), height(_height)
    {}
    
    void setLength(int _length) { 
	    length = _length; 
    }
   
    void setHeight(int _height) { 
	    height = _height; 
    }

    // Функции получения значений полей, 
    int getLength() { 
	    return length;
	    }
    int getHeigth() { return height; }

     
    int sqare() { return length * height; }//Функция, рассчитывающая площадь фигуры.
    
    int perimetr() { return (length + height)*2; }
    
    double diagonal() { return (sqrt(length*length + height*height)); }
    
    friend istream& operator >>(istream& sstream, Rectangle& r1)
    { 
    int tmp;
    cout<<"Введите ширину: ";
    cin>>tmp;
    if (tmp<=0){
        cout << "Ошибка! Введите положительное значение!";
		exit(0);
    }
    r1.setLength(tmp);
    cout<<"Введите длинну: "; 
    cin>>tmp; 
    if (tmp<=0){
        cout << "Ошибка! Введите положительное значение!";
		exit(0);
    }
    r1.setHeight(tmp);
    return sstream; 
    }
    
    void printRectangle(){

    for(int i=1; i<=length; i++)
    {
    for(int j=1; j<=height; j++)
    {
    cout<<"*";
    }
    cout<<endl;
    }
    }

    void typeOfRectangle()
    {
        if (length == height)
        {
            cout<<"Это квадрат!"<<endl;
        }
        else
        {
            cout << "Это прямоугольник!"<< endl;
        }
    }
};

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    Rectangle r; // Вызывается конструктор по умолчанию.
    cout <<"Конструктор по умолчанию: "<< r.getLength(); 
    cout << " " << r.getHeigth() << endl; 
    r.setLength(10); // Устанавлием длину
    r.setHeight(4); // Устанавливаем высоту
    cout <<"Длина: "<< r.getLength()<< endl; 
    cout << "Ширина: " << r.getHeigth() << endl; 
    cout << "Площадь прямоугольника равна: " << r.sqare() << endl; 
   
    Rectangle r1(0,0);// Вызывается конструктор с параметрами
    cin >> r1; 
    cout << "Конструктор с параметрами: "<< r1.getLength();
    cout << " и " << r1.getHeigth() << endl;
    cout << "Возвращаемая площадь: "<< r1.sqare() << endl;
    cout << "Возвращаемый периметр: "<< r1.perimetr() << endl;
    cout<<"Диагональ прямоугольника равна: "<<r1.diagonal()<<endl;
    cout<<"Напечатаем получившийся прямоугольник"<<endl;
    r1.printRectangle();
    r1.typeOfRectangle();
}
