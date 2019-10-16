//Problem Description: Find a higher N such that it has same 1's.
#include<iostream>
using namespace std;
int count(int x){
  int cnt=0, bit;
  while (x != 0){
    bit = x & 0x80000000;
    if (bit == -0x80000000)
      bit = 1;
    if (bit == 1)
      cnt++;
    x = x << 1;
  }
  return cnt;
}
int main(){
  int x, cnt;
  cin>>x;
  cnt = count(x);
  for (int k = x+1; ; k++){
    if (cnt == count(k))
    {  cout<<k;
       break;
    }
  }
}
