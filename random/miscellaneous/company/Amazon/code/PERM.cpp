#include<stdio.h>
#include<string.h>

void swap(char *x, char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int low, int high){
  if (str == '\0') return;

  if (low == high) printf("%s\n", str);

  else{
    for (int i = low; i <= high; i++){
      swap((str+low),(str+i));
      permute(str, low+1, high);
      swap((str+low),(str+i));
    }
  }
}

int main(){
  char str[] = "ABC";
  permute(str, 0, strlen(str)-1);

  return 0;
}
