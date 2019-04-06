#define _CRT_SECURE_NO_WARNINGS//где условие?
#include "pch.h"
#include <iostream> 
#include <sstream> 
#include <cstring> 
#include <cctype> 

using namespace std;

const int MAX = 255;

int main()
{
	char Str[MAX];
	char Str1[] = ",.; \t"; 
	char temp[MAX];
	cout << "Enter a string " << MAX << "\n";
	cin.getline(Str, MAX);

	int k = 0; 
	char *p = Str;
	cout << "Words:\n";
	while (*p)
	{
		p += strspn(p, Str1); 
		int Len = strcspn(p, Str1); 
		if (Len == 0)
			break;
		if (Len == 4)// что за 4???? магическое число?
		{
			strncpy(temp, p, Len);
			temp[Len] = '\0';
			cout << temp << endl;
			k++;
		}
		p += Len;
	}

	cout << "quantity of words=" << k << endl;
	
*/ 	char *word = new char[MAX], *word2 = new char[MAX];//new есть, проверки нет????
	cin.getline(word, MAX);
	
	cin.getline(word2, MAX);
	char *text = new char[MAX]//new есть, проверки нет????
		cin.getline(text, MAX);
	while (char *p = strstr(text, word))
		while (*p++ = *word2++);


	cout << endl << text;
*/

	system("pause");
	return 0;
}

//Последний пунк задания не выполнен. Проблема с компилятором. Переделаю и закончу.
