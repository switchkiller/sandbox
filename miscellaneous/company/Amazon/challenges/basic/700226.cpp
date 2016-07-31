// Print Square root

#include<iostream>

using namespace std;

long long int floorSqrt(long long int x){
  if (x == 0 || x == 1)
    return x;

  int res = 1, i = 0;

  while (res < x){
    i++;
    res = i * i;
    if (res == x)
        return i;
  }
  return i-1;
}

int main(){
  long long int x = 15;
  cout << floorSqrt(x);

  return 0;
}
