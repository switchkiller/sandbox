// Description - Minimum number of steps to divide a number upto 1 by perfoming some mathematical functions.
// On a positive integer, you can perform any one of the following 3 steps. 1.) Subtract 1 from it. ( n = n - 1 )  , 2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )  , 3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  ). Now the question is, given a positive integer n, find the minimum number of steps that takes n to 1.
//TD approach
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int lookup[MAX+1];
int min_steps(int n){
  if (n == 1) return 0;
  if (lookup[n] != -1) return lookup[n];
  int r = 1 + min_steps(n-1);
  if (n % 2 == 0) r = min(r, 1 + min_steps(n/2));
  if (n % 3 == 0) r = min(r, 1 + min_steps(n/3));
  cout << n << "=" << r << endl;
  lookup[n] = r; // XXX min val
  return r;
}
int main(){
  int n;
  memset(lookup, -1, sizeof lookup);
  cin >> n;
  cout << min_steps(n);
  return 0;
}
