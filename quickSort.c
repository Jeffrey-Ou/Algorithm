#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 100			//测试数组长度
#define LIMIT 10000		//随机数范围[0, LIMIT)


void quickSort(int *a, int left, int right) {
	if (left > right)
		return;
	int i = left;
	int j = right;
	int temp = a[left];
	while (i != j) {
		while (i < j && temp <= a[j])
			j--;
		while (i < j && temp >= a[i])
			i++;
		if (i < j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}

int main() {
	srand((unsigned)time(0));
	int test[LEN];
	printf("\n==========乱序数组==========");
	for (int i = 0; i < LEN; i++) {
		test[i] = rand() % LIMIT;
		printf("%d%c", test[i], (i + 1) % 10 ? ' ' : '\n');
	}
	quicksort(test, 0, LEN - 1);
	printf("\n==========快速排序后==========\n");
	for (int i = 0; i < 100; i++)
		printf("%d%c", test[i], (i + 1) % 10 ? ' ' : '\n');
	return 0;
}
