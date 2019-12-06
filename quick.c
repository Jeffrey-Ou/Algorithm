#include<stdio.h>

void swap(int *p, int low, int high)
{
	int t = p[low];
	p[low] = p[high];
	p[high] = t;
}

int partition(int *p, int low, int high)
{
	int pivotkey;
	int m = low + (high - low) / 2;
	/*
	if (p[low] > p[high])
		swap(p, low, high);
	if (p[m] > p[high])
		swap(p, high, m);
	if (p[m] > p[low])
		swap(p, m, low);
*/
	pivotkey = p[low];

	p[0] = pivotkey;
	while (low < high)
	{
		while(low < high && p[high] >= pivotkey)
			high--;
		p[low] = p[high];
		while(low < high && p[low] <= pivotkey)
			low++;
		p[high] = p[low];
	}
	p[low] = p[0];
	return low;
}

void sort(int *p, int low, int high)
{
	int pivot;
	while (low < high)
	{
		pivot = partition(p, low, high);
		sort(p, low, pivot - 1);
		low = pivot + 1;
	}
}
int main()
{
	int b[11] = {0, 9, 1, 4, 3, 5, 8, 10, 7, 6, 2};
	int i;
	int low = 1;
	int high = 10;

	sort(b, low, high);
	printf("quick sort: ");
	for(i = 1; i < 11; i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}
