#include <stdio.h>
#include <string.h>

struct coffee 
{
    int id;
    char property;
};

char re[] = "regular";
char ex[] = "expresso";
char dex[] = "double expresso";
char milk[] = "milk";
char cream[] = "cream";
char soy[] = "soy milk";
char sugar[] = "sugar";
char arts[] = "artificial sweetener";
int property(char *str)
{
	if (strcmp(str, re) == 0)
		return 0;
	else if (strcmp(str, ex) == 0)
		return 1;
	else if (strcmp(str, dex) == 0)
		return 2;
	else if (strcmp(str, milk) == 0)
		return 3;
	else if (strcmp(str, cream) == 0)
		return 4;
	else if (strcmp(str, soy) == 0)
		return 5;
	else if (strcmp(str, sugar) == 0)
		return 6;
	else
		return 7;
}

void printcoffee(struct coffee* c)
{
	char i = c -> property;
	const unsigned char regular = 1<<0;
	const unsigned char espresso = 1<<1;
	const unsigned char double_espresso = 1<<2;
	const unsigned char milkk = 1<<3;
	const unsigned char creamm = 1<<4;
	const unsigned char soy_milk = 1<<5;
	const unsigned char sugarr = 1<<6;
	const unsigned char sweetener = 1<<7;
	if (i & regular)
		printf("%s ", re);
	if (i & espresso) 
		printf("%s ", ex);
	if (i & double_espresso)
		printf("%s ", dex);
	if (i & milkk)
		printf("%s ", milk);
	if (i & creamm)
		printf("%s ", cream);
	if (i & soy_milk)
		printf("%s ", soy);
	if (i & sugarr)
		printf("%s ", sugar);
	if (i & sweetener)
		printf("%s ", arts);
	printf("\n");
}

void set_coffee_property(struct coffee* c, int property_)
{
	c -> property = c -> property | 1 << property_;
}

void unset_coffee_property(struct coffee* c, int property_)
{
	if ((c -> property & 1 << property_ ) != 0)
		c -> property = c -> property ^ 1 << property_;
}

int main()
{
	char set[25], unset[25];
	struct coffee cof;
	struct coffee* c = &cof;
	cof.property = 0;
	int property1, property2;
	set_coffee_property(c, 0);
	set_coffee_property(c, 3);
	set_coffee_property(c, 6);
	printcoffee(c);
	fgets(set, sizeof(set), stdin);
	set[strlen(set) - 1] = '\0';
	fgets(unset, sizeof(unset), stdin);
	unset[strlen(unset) - 1] = '\0';
	property1 = property(set);
	property2 = property(unset);
	set_coffee_property(c, property1);
	unset_coffee_property(c, property2);
	printcoffee(c);
	return 0;
}
	
	
