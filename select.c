#include<stdio.h>

int main()
{
	int b[10] = {9,1,4,3,5,8,10,7,6,2};
	int i, j, min, t;

	for(i=0; i<10-1; i++)
	{
		min=i;
		for(j=i+1; j < 10; j++)
		{
			if(b[min] > b[j])
				min=j;
		}
		if(min != i)
		{
			t = b[min];
			b[min] = b[i];
			b[i] = t;
		}

	}
	printf("select :");
	for(i=0; i<10; i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}
