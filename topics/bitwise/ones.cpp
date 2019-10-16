#include<iostream>
using namespace std;
int count(int x){
  int cnt, bit;
  while(x != 0){
    bit = x & 0x80000000;
    if (bit == -0x80000000)
    {
      bit = 1;
    }
    if (bit == 1)
      cnt++;
    x = x << 1;
  }
  return cnt;
}
int main(){
  int x;
  cin>>x;
  cout<<count(x);
}
