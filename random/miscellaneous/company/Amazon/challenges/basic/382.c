// Permutation of string
// Need to order lexographically.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

void swap(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}

void permute(char *str, int low, int high){
  if (*str == '\0') return;

  if (low == high)
    printf("%s ", str);
  else{
    for (int i = low; i <= high; i++){
      swap((str+i), (str+low));
      permute(str, low + 1, high);
      swap((str+i), (str+low));
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while (t--){
      char s[N];
      scanf("%s", s);
      int n = strlen(s);
      permute(s, 0, n-1);
      printf("\n");
  }
  return 0;
}
