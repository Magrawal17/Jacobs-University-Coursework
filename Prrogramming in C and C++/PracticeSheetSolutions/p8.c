#include <stdio.h>
void total_time(int mins[], int secs[], int n, int *sum_min, int *sum_sec)
{
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += mins[i] * 60 + secs[i];
	}
	*sum_sec = sum % 60;
	*sum_min = sum / 60;
}

int main()
{
	int mins[2] = {1, 3};
	int secs[2] = {1, 2};
	int n = 2;
	int *sum_min, min;
	int *sum_sec, sec;
	sum_min = &min;
	sum_sec = &sec;
	total_time(mins, secs, n, sum_min, sum_sec);
	printf("%d %d\n", min, sec);
	return 0;
}