#include<stdio.h>

int main()
{
	int c[11] = {0,9,1,4,3,5,8,10,7,6,2};
	int i,j,t;

	for(i=2;i<11;i++)
	{
		if(c[i]<c[i-1])
		{
			c[0] = c[i];
			for(j=i-1;c[j]>c[0];j--)
			{
				c[j+1] = c[j];
			}
			c[j+1] = c[0];
		}
	}
	printf("insert: ");
	for(i=1; i<11; i++)
		printf("%d ",c[i]);
	printf("\n");
	return 0;
}
