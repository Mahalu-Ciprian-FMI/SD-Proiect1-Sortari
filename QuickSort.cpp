#include <iostream>
#include <fstream>
using namespace std;
ifstream f("algo.in");
ofstream g("algo.out");

int partition_process(int st, int dr, int v[])
{
	int pivot = v[dr];
	int i, j;
	i = st - 1;
	for (int j = st; j < dr; j++)
	{
		if (v[j] < pivot)
		{
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[dr]);
	return i + 1;
}
void quicksort(int st, int dr, int v[])
{
	if (st < dr)
	{
		int pivot = partition_process(st, dr, v);
		quicksort(st,pivot - 1,v);
		quicksort(pivot + 1, dr, v);
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
}
