// First nonrepeating character in a string
#include<stdio.h>
#include<stdlib.h>
#define N 256

int *cntIndx(char *s){
  int *cnt = (int *) calloc(sizeof(int), N);
  for (int i = 0; *(s+i); i++)
    cnt[*(s+i)]++;
  return cnt;
}

int getIndex(char *s){
  int *cnt = cntIndx(s);
  for(int i = 0; *(s+i); i++){
    // printf("%d",cnt[*(s+i)] );
    if (cnt[*(s+i)] == 1)
      return i;
    }
  return -1;
}

int main(){
  char s[N];
  scanf("%s",s);
  int idx = getIndex(s);

  printf("%d\n", idx);

  return 0;
}
