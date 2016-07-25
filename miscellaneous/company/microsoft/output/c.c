#include<stdio.h>
int main(){
  char *ptr = "geeksforgeeks";
  printf("%c\n", *(&*(&*ptr+1)+2));
  printf("%s\n", ptr);
  // getchar();
  return 0;
}
