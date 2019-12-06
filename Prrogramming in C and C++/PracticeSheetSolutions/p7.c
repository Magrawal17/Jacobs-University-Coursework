#include <stdio.h>
int substitute_vowels(char *s, char ch)
{
	int i = 0;
	for(; *s != '\0'; s++)
		if(*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u')
		{
			*s = ch;
			i++;
		}
	return i;
}

int main()
{
	int n;
	char s[] = "This is a sentence";
	printf("%s\n", s);
	n = substitute_vowels(s, 'o');
	printf("%s\n", s);
	printf("%d\n", n);
	return 0;
}
