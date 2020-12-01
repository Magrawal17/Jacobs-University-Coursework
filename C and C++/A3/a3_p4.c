/*
 CH-230-A
 a3_p4.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int position(char str[], char c){
    int idx;
    /* Loop until end of string */
    for (idx = 0; str[idx] != c && str[idx] != '\0'; idx++){   // bracket was not specified
    /* do nothing */ 
    }                                                          // bracket was not specified
    return idx;
    }

int main() {
    char line[80];                                                    
    printf("Enter string:\n");                              // loop taken out due to infinte loop taking place
    fgets(line, sizeof(line), stdin);
    printf("The first occurrence of 'g'; is: %d\n", position(line, 'g'));              
}
