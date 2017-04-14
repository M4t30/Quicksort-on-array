#include <iostream>
#include <math.h>
#include <time.h>
#include <ctime>
using namespace std;

long partition(int *tab, long l, long r) {
	int x = tab[r];
	long i = l - 1;
	for (;l<r;l++)
	{	
		if (tab[l] <= x)
			swap(tab[++i], tab[l]);
	}
	swap(tab[i + 1], tab[r]);

	return i + 1;
}


void quick(int *tab, long l, long r) {
	long p;

	if (l<r) {
		p = partition(tab, l, r);
		quick(tab, l, p - 1);
		quick(tab, p + 1, r);
	}
}


void main()
{
	time_t start, stop;
	int n = 10;
	srand(time(NULL));
	for (int j = 10;j <= 10000; j *= 10) 
	{
		int *tab = new int[j];
		int *tab2 = new int[j];
		int *tab3 = new int[j];
		for (int i = 0; i<j; i++)
		{
			tab[i] = rand() % 100;
		}

		quick(tab, 0, j - 1);
	}
	system("PAUSE");
}