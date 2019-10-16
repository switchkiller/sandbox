//Problem Description: Count the number of trailing zeros in an integer.
#include<iostream>
using namespace std;
int main(){
  int x, cnt=0;
  cin>>x;
  while (x != 0){
    if (x & 1 == 1)
      break;
    else{
      cnt++;
      x = x >> 1;
    }
  }
  cout<<cnt;
}
