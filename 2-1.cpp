//В массиве А(N, М) сменить знаки минимальных элементов и удалить строку с минимальным произведением элементов.
#include <pch.h>
#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
   setlocale(LC_ALL,"Russian");
   srand(time(0));
   int n, m, mmin, imin, minproizv;
   cout << "INPUT:\n";
   cin >> n >> m;

   int **a = new int*[n];
   for (int i = 0; i < n; i++)
      a[i] = new int[m];

   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         a[i][j] = rand() % 19 - 9;
         cout << setw(2) << a[i][j] << " ";
      }
      cout << endl;
   }

   mmin=a[0][0];
   for (int i = 0; i < n; i++)
   {
	   for (int j = 0; j < m; j++)
	   {
		   mmin = min(a[i][j], mmin);
	   }
   }
   for (int i = 0; i < n; i++)
   {
	   for (int j = 0; j < m; j++) 
	   {
		   if (a[i][j] == mmin)
			   a[i][j] = -a[i][j];
	   }
   }

   imin=0;
   minproizv=1;
   for (int i = 1; i < n; i++)
   {
	   minproizv *= a[0][i];
   }
   for (int i = 1; i < n; i++)
   {
	   int proizv = 1;
	   for (int j = 0; j < m; j++)
	   {
		   proizv *= a[i][j];
	   }
	   if (minproizv > proizv)
		   minproizv = proizv;
	   imin = i;
   }
   for (int i = imin; i < (n - 1); i++)
   {
	   a[i] = a[i + 1];
   }
   delete[] a[n-1];
   a[n-1]=nullptr;
   n--;

   cout << "OUTPUT:\n";
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
         cout << setw(2) << a[i][j] << " ";
      cout << endl;
   }

   for (int i = 0; i < n; i++)
   {
      delete[] a[i];
      a[i]=nullptr;
   }
   delete[] a;
   a=nullptr;
   system("pause");
   return 0;
}
//Первая часть кода работает нормально, вторая компилируется, но выполнение не происходит. Буду доделывать.