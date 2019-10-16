#include<stdio.h>
#define AND &&
#define ARRANGE (a>25 AND a<50)
int main()
{int a = 30;
if (ARRANGE)
printf("within range");
else
printf("out of range");
return 0;
}
