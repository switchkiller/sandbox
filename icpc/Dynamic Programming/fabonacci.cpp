#include<iostream>
#include<cstdio>
using namespace std;
#define NIL -1
#define MAX 100
int lookup[MAX];
//Top Down
void initialise(){
  int i;
  for (i = 0; i < MAX; i++)
    lookup[i] = NIL;
}
int fib(int n){
  if (lookup[n] == NIL){
    if (n <= 1)
      lookup[n] = n;
    else
      lookup[n] = fib(n-1) + fib(n-2);
  }
  return lookup[n];
}

int main(){
  int n = 10;
  initialise();
  cout << fib(n);
  return 0;
}
