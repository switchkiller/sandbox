#include<stdio.h>
#include<stdlib.h>
int main(){
  int *a = (int *) malloc(sizeof(int));
  *a = 5;
  printf("%d\n",*a );
  return 0;
}
