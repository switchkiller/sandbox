#include<iostream>
#include<cstdio>
int recfunc(char *a, char b, int i){
    if (a[i] == '\n')
      return 0;
    if (a[i] == b)
      return 1 + recfunc(a, b, i+1);
    return recfunc(a, b, i+1);
}
int main(){
  char a[] = "HELLLLLLLLO";
  printf("%d",recfunc(a,'L',0));
  return 0;
}
