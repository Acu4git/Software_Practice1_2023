// Q2

#include <stdio.h>

#define NUMOFCHAR 10

void print_char(char *ptr);

int main(void)
{
     char string[NUMOFCHAR+1];

     for(int i=0; i<NUMOFCHAR+1;i++) string[i]='\0';

     printf("Input a sentence (# of letters <= %d): ", NUMOFCHAR);
     fflush(stdout);
     scanf("%s", string);
     string[NUMOFCHAR] = '\0';

     printf("Original string is <%s>\n", string);
     printf("Modified string is <");
     print_char(string);
     printf(">\n");

     return 0;
}


void print_char(char *ptr)
{

/*** Write the source code here ***/
  while(*ptr != '\0') {
    putchar(*ptr);
    if(*(++ptr) == '\0') break;
    putchar('-');
  }
}