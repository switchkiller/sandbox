#include<iostream>
using namespace std;
int bitoff(int x, int k){
  if (k<=0) return x;
  return (x & ~(1<<(k-1)));
}
int main(){
  int x = 19, k = 5;
  cout<<bitoff(x,k);
  return 0;
}
