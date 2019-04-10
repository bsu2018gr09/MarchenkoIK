// transformbmp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// я что то не совсем понял зачем мне совершенно новая программа?????? Где исправление предыдущего варианта????

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


	int st;
	float r1, g1, b1;
	float r2, g2, b2;
	float st_r, st_g, st_b;
	float  tmp_r1, tmp_g1, tmp_b1;
	unsigned int w, h;

	cout << "Cin step: ";
	cin >> st;

	cout << "Cin start color: ";
	cin >> r1 >> g1 >> b1;

	cout << "Cin finish color: ";
	cin >> r2 >> g2 >> b2;

	c.r = r1;
	c.g = g1;
	c.b = b1;
	tmp_r1 = r1, tmp_g1 = g1, tmp_b1 = b1;
	char buf[30];
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

	st_r = abs((r2 - r1) / st);
	st_g = abs((g2 - g1) / st);
	st_b = abs((b1 - b1) / st);

	float Tmp_r1 = ((r2 - r1)*(st_r)) / w;
	float Tmp_b1 = ((g2 - g1)*(st_g)) / w;
	float Tmp_g1 = ((b2 - b1)*(st_b)) / w;

	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			tmp_r1 += Tmp_r1;
			tmp_g1 += Tmp_b1;
			tmp_b1 += Tmp_g1;
			c.r = (unsigned char)tmp_r1;
			c.g = (unsigned char)tmp_g1;
			c.b = (unsigned char)tmp_b1;
			g.write((char *)&c, 3);
		}
		tmp_r1 = r1;
		tmp_g1 = g1;
		tmp_b1 = b1;
	}
	/*char buf[30];
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
	}*/
	f.close();
	g.close();
	// system("pause"); 
	return 1;
}
