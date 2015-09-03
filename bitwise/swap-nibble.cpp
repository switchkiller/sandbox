// Swap the nibble of a byte.
#include<iostream>
#include<stdio.h>

using namespace std;

unsigned char swap(unsigned char x){
  return ((x & 0x0F)<<4 | (x & 0xF0)>>4);
}

int main(){
  unsigned char x = 100;
  cout<<(int)swap(x);
  return 0;
}
