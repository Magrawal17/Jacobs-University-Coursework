#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int n, i, *num;
	scanf("%d", &n);
	num = (int*)malloc(sizeof(int) * n);
	if(num == NULL)
		exit(1);
	fp = fopen("squares.txt","w");
	if (fp == NULL)
		exit(1);

	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	for(i = n - 1; i >= 0; i--)
		fprintf(fp, "%d %d\n", num[i], num[i]*num[i]);
	
	// free and fclose
	free(num);
	fclose(fp);
	return 0;
}
