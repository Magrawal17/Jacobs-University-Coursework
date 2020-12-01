#include <stdio.h>


int odd(unsigned char data) {
	return data&1;
}


int main() {
	printf("Is 'a' odd? %d\n", odd('a')); // check corresponding asc2
	printf("Is 'd' odd? %d\n", odd('d'));
	return 0;
}