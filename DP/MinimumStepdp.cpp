// Description - Minimum number of steps to divide a number upto 1 by perfoming some mathematical functions.
// On a positive integer, you can perform any one of the following 3 steps. 1.) Subtract 1 from it. ( n = n - 1 )  , 2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )  , 3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  ). Now the question is, given a positive integer n, find the minimum number of steps that takes n to 1.
//BU approach
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int lookup[MAX+1];
int minimumSteps(int n){
  lookup[1] = 0;
  for (int i = 2; i <= n; i++){
    lookup[i] = 1 + lookup[i-1];
    if (i%2 == 0) lookup[i] = min(lookup[i], 1 + lookup[i/2]);
    if (i%3 == 0) lookup[i] = min(lookup[i], 1 + lookup[i/3]);
    cout << i << " " << lookup[i] << endl;
  }
  return lookup[n];
}

int main(){
  int n;
  memset(lookup, -1, sizeof lookup);
  cin >> n;
  cout << minimumSteps(n);
  return 0;
}
