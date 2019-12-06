#include <stdio.h>
#include <string.h>


int passcheck(char* pass){
	int i, digit = 0;
	if (strlen(pass) >= 8) // min len of 8
	{
		for(i = 0; i < strlen(pass); i++){
			if (pass[i] >= '0' && pass[i] <= '9')
				digit++;
		}
		if(digit >= 3){ // min 3 digits
			return 1; // good
		}
		else{
			return 0; // bad
		}
	}
	else{
		return 0; // bad
	}
}


int main()
{
	char password[40];
	printf("Write a password:\n");
	fgets(password, sizeof(password), stdin);
	printf("Is the password safe? %d\n", passcheck(password));

	return 0;
}