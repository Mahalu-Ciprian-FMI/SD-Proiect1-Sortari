#include <iostream>
#include <fstream>
using namespace std;
ifstream f("algo.in");
ofstream g("algo.out");

void insertionsort(int v[], int n)
{
	int i, j, cheie;
	for (i = 1; i < n; i++)
	{
		cheie = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > cheie)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = cheie;
	}
}
int main()
{
	int v[500000], n;
	f >> n;
	for (int i = 0; i < n; i++)
		f >> v[i];
	insertionsort(v, n);
	for (int i = 0; i < n; i++)
		g << v[i] << " ";
	return 0;
}
