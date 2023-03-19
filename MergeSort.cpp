#include <iostream>
#include <fstream>
using namespace std;
ifstream f("algo.in");
ofstream g("algo.out");

void merge(int v[], int st, int dr, int mij)
{
	int k =0, i = st, j = mij+1, temp[101] = { 0 };
	while (i <= mij && j <= dr)
	{
		if (v[i] < v[j])
		{
			temp[k] = v[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = v[j];
			k++;
			j++;
		}
	}
	while (i <= mij)
	{
		temp[k] = v[i];
		k++;
		i++;
	}
	while (j <= dr)
	{
		temp[k] = v[j];
		k++;
		j++;
	}
	for (int l = st; l <= dr; l++)
	{
		v[l] = temp[l - st];
	}
}
void mergesort(int v[], int st, int dr)
{
	if (st < dr)
	{
		int mij = (st + dr) / 2;
		mergesort(v, st, mij);
		mergesort(v, mij + 1, dr);
		merge(v, st, dr, mij);
	}
}
int main()
{
	int v[50000], n;
	f >> n;
	for (int i = 0; i < n; i++)
		f >> v[i];
	mergesort(v, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		g << v[i] << " ";
	}

	return 0;
}
