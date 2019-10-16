//Problem Description: To find the position of the MSB in the given key.
#include<iostream>
#define NUM_BIT 32
using namespace std;
int MSBPOS(int n){
  int i = 0, bit;
  while (i < NUM_BIT){
    bit = n & 0x80000000;
    if (bit == -0x80000000){
      bit == 1;
    }
    if (bit == 1)
      break;
    n = n << 1;
    i++;
  }
  return i;
}

int main(){
  int n;
  cin>>n;
  cout<<MSBPOS(n);
}
