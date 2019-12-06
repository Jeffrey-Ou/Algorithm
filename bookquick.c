#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LEN 100
#define LIMIT 1000
int patend(int *a, int low, int high)
{
	int key = a[low];
	a[0] = key;

	while (low < high)
	{
		while (low < high && a[high] >= key)
			high--;
		a[low] = a[high];
		while (low < high && a[low] <= key)
			low++;
		a[high] = a[low];
	}
	a[low] = a[0];

	return low;
}
void sort(int *a, int low, int high)
{
	int pivot;
	while (low < high)
	{
		pivot = patend(a, low ,high);
		sort(a, low, pivot -1);
		low = pivot + 1;
	}
}

int main()
{
	int begin, end;
	srand((unsigned)time(0));
	int test[LEN + 1];
	int i = 0;
	int low = 1, high = LEN;
	printf("\n==========乱序数组==========\n");
	for (i = 1; i < LEN + 1; i++)
	{
		test[i] = rand() % LIMIT;
		printf("%10d%c", test[i], (i + 1) % 10 ? ' ' : '\n');
	}
	begin = clock();
	for(i = 0; i < 100; i++)
		sort(test, low, high);
	end = clock();
	printf("\n==========快速排序后==========\n");
	for (i = 1; i < 100 + 1; i++)
		printf("%10d%c", test[i], (i + 1) % 10 ? ' ' : '\n');
	printf("run time is %dms\n", end - begin);
	return 0;
}
