// Sum of all the bits from 1 to N
//Brian Kernighan’s Algorithm
#include<stdio.h>
#include<stdlib.h>

int countBit(int n){
  int cnt = 0; // Count the no. of set bits in n
  while(n){
    n = n & (n-1);
    cnt++;
  }
  return cnt;
}

int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    int n, i, cnt = 0;
    scanf("%d", &n);

    for (i = 1; i <= n; i++ )
      cnt += countBit(i);
    printf("%d\n", cnt);
  }
  return 0;
}
