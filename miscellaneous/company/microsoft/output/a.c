#include<stdio.h>
int main(){
  typedef int *i;
  int j = 10;
  // i *a = &j;   Incorrect.
  int *k = &j;
  i *a = &k;
  printf("%d\n", **a);
  getchar();
  return 0;
}
