#include <iostream>
#include <fstream>
using namespace std;
ifstream f("algo.in");
ofstream g("algo.out");

int maxim(int v[], int n) //functie auxiliara pentru a afla valoarea maxima din array
{
	int mx = v[0];
	for (int i = 1; i < n; i++)
		if (v[i] > mx)
			mx = v[i];
	return mx;
}
void countsort(int v[], int n, int k)//functie auxiliara de sortare prin numarare
{
	int temp[500000];
	int i, count[65536] = { 0 }; //vectorul de frecventa count, 65536=2^16;
	for (i = 0; i < n; i++)
		count[(v[i] / k) % 65536]++;
	for (i = 1; i < 65536; i++)
		count[i] = count[i] + count[i - 1];
	for (i = n - 1; i >= 0; i--)
	{
		temp[count[(v[i] / k) % 65536] - 1] = v[i];
		count[(v[i] / k) % 65536]--;
	}
	for (i = 0; i < n; i++)
		v[i] = temp[i];
}
void radixsort(int v[], int n)
{
	int m = maxim(v, n);
	for (int i = 1; m / i > 0; i *= 65536)
		countsort(v, n, i);
}
int main()
{
	int v[500000], n;
	f >> n;
	for (int i = 0; i < n; i++)
		f >> v[i];
	radixsort(v, n);
	for (int i = 0; i < n; i++)
	{
		g << v[i] << " ";
	}
	return 0;
}
