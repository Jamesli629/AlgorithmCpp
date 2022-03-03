#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *p=(int*)malloc(sizeof(int)*10);
	int i;
	for(i=0;i<10;i++)
		p[i]=10*i;
	for(i=0;i<10;i++)
		printf("%d\t",p[i]);
	printf("\n");
	free(p);
	return 0;
}