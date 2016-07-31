#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define N 100

using namespace std;

char dict[] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};

char *findKey(char *str, int n){
  char *st = (char *) malloc(n * sizeof(char)); // Beware you dont declare it as a local variable
  for (int i = 0; i < n; i++)
    st[i] = dict[str[i] - 'a'];
  st[n] = '\0';
  return st;
}

int main(){
  int t;
  char str[N];
  cin >> t;
  while (t--){
    cin >> str;
    int n = strlen(str);
    cout << findKey(str,n) << endl;
  }
  return 0;
}
