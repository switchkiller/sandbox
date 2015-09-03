//Turn the even bits to odd, and odd bits to even -> 1 bit shift -> even swap adj left bit and for odd swap adj. right bit.
#include<iostream>
using namespace std;
unsigned int oddeven(unsigned int x){
  unsigned int a = x & 0xAAAAAAAA;
  unsigned int b = x & 0x55555555;
  a >>= 1;
  b <<= 1;
  return (a | b);
}
int main(){
  unsigned int x = 23;
  cout<<(int) oddeven(x);
  return 0;
}
