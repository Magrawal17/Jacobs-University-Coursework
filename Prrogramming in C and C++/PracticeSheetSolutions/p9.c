#include <stdio.h>

int main()
{
	int i, j, n;
	char ch;
	scanf("%d",&n);
	getchar();
	scanf("%c",&ch);
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < i+1; j++){
			printf("%c",ch);
		}
		printf("\n");
	}
	return 0;
}