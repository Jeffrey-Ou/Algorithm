#include<stdio.h>
#include<stdbool.h>

#define MAX 10

int main()
{
	int a[10] = {9,1,4,3,5,8,10,7,6,2};
	int i, j;
	int t;
	bool flag = true;
	for(i=0; i<10 && flag; i++)
	{
		flag = false;
		for(j=10-2; j>=i; j--)
		{
			if(a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				flag = true;
			}
		}
	}
	printf("bubble: ");
	for(i=0; i<10; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
