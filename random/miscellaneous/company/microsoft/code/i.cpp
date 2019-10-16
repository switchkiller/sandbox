// same number of one bits
#include<iostream>

#define LSOne(x) x & (-x)
typedef unsigned int uint_t;
using namespace std;

uint_t findLargestOneBit(uint_t n){
  uint_t rightOne;
  uint_t nextHigherOneBit;
  uint_t rightOnesPattern;

  uint_t next = 0;

  if (n){
    rightOne = LSOne(n);
    nextHigherOneBit = rightOne + n;
    rightOnesPattern = n ^ nextHigherOneBit;
    rightOnesPattern = (rightOnesPattern) / rightOne;
    rightOnesPattern >>= 2;
    next = nextHigherOneBit | rightOnesPattern;
  }
  return next;
}

int main(){
  int n;
  cin >> n;
  cout << findLargestOneBit(n);
  return 0;
}
