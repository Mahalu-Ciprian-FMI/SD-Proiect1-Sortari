#include <iostream>
#include <fstream>
using namespace std;
ifstream f("algo.in");
ofstream g("algo.out");

 //SHELLSORT
void shellsort(int v[], int n)
{
	int i, j, k, temporar;
	for (i = n / 2; i > 0; i /= 2)
	{
		for (j = i; j < n; j++)
		{
			temporar = v[j];
			k;
			for (k = j; k >= i && v[k - i] > temporar; k = k - i)
				v[k] = v[k - i];
			v[k] = temporar;
		}
	}
}

int main()
{
	int v[500000], n;
	f >> n;
	for (int i = 0; i < n; i++)
		f >> v[i];
	shellsort(v, n);
	for (int i = 0; i < n; i++)
		g << v[i] << " ";
	return 0;
}

