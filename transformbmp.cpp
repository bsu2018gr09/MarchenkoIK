// transformbmp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include<fstream> 

using namespace std;

struct color { unsigned char r; unsigned char g; unsigned char b; } c;

int main() {
	ifstream f("c:\\start.bmp", ios::binary);
	ofstream g("c:\\finish.bmp", ios::binary);
	if (!f) { cout << "No file c:\\start.bmp. Can't open\n"; exit(1); }
	if (!g) { cout << " file c:\\finish.bmp. Can't create\n"; exit(1); }

	char buf[30];
	c.r = 255, c.g = 255, c.b = 255;
	color c;
	unsigned int w, h;
	f.read((char *)&buf, 18);
	g.write((char *)&buf, 18);
	f.read((char *)&w, 4);
	cout << "w=" << w;
	f.read((char *)&h, 4);
	cout << ", h=" << h;
	g.write((char *)&w, 4);
	g.write((char *)&h, 4);
	f.read((char *)&buf, 28);
	g.write((char *)&buf, 28);
	c.r = 12;
	c.g = 65;
	c.b = 149;
	int k = 0;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			g.write((char *)&c, 3);
			c.g++;

		}
		c.r = 0; c.g = 0; c.b = 0;
	}
	f.close();
	g.close();
	// system("pause"); 
	return 1;
}