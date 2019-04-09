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

	unsigned char r , g , b;
	unsigned int w , h;
	char buf[ 30 ];
	int r1=255 , g1=255 , b1=255;
	int r2=0, g2=0 , b2=0;
	int step=80;
	color c;
	
	f.read((char * )&buf, 18);   
	g.write((char * )&buf, 18);    
	f.read((char * )&w, 4); 
	cout << "w=" << w;  
	f.read((char * )&w, 4); 
	cout << ", h=" << w; 
	w = 128;
	g.write((char * )&w, 4);    
	h = 100;
	g.write(( char * )&h, 4);    
	f.read((char * )&buf, 28);   
	g.write((char * )&buf, 28);    
	c.r = r1; 
	c.g = g1; 
	c.b = b1;
	double dr = abs(r2 - r1)/step;
	double dg = abs(g2 - g1)/step;
	double db = abs(b2 - b1)/step;
	int l = 0;
	for(int i=1;i<=h;++i){
		for ( int j = 1; j <= w; ++j ) {
			if ( l < step ) {
				c.b = c.b + db;
				c.g = c.g + dg;
				c.r = c.r + dr;
				l++;
			}
			g.write( ( char * )&c , 3 );
		}
		c.r = r1; 
		c.g = g1; 
		c.b = b1;
		l = 0;
	}
	f.close();
	g.close();
	// system("pause"); 
	return 1;
}
