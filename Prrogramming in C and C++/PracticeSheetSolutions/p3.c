#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int n, i, *num, *square;
	fp = fopen("squares.txt","w");
	if (fp == NULL)
		exit(1);
	scanf("%d", &n);
	if (n <= 0)
		return 1;
	// dynamically allocating
	num = (int*)malloc(sizeof(int) * n);
	if(num == NULL)
		exit(1);
	square = (int*)malloc(sizeof(int) * n);
	if(square == NULL)
		exit(1);
		
	// reading and writing	
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		square[i] = num[i] * num[i];
	}
	for(i = n - 1; i >= 0; i--)
		fprintf(fp, "%d %d\n", num[i], square[i]);
	
	// free and fclose
	free(num);
	free(square);
	fclose(fp);
	return 0;
}
