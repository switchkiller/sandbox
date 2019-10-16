#include<stdio.h>
char *getString()
{
   char *str = "Nice test for strings";
   return str;
}
char getStringc()
{
  char *str = "Nice test for strings";
  return *str;
}

int main()
{
   printf("%s", getString());
   printf("%c", getStringc());
   getchar();
   return 0;
}

// If we were to print only the first letter.
