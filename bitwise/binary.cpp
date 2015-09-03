//Print the binary of a given integer
#include<iostream>
using namespace std;
void binary(unsigned x){
  for (unsigned i = 1 << 31; i > 0; i /= 2)
    (x & i) ? cout<<"1" : cout<<"0";
}
int main(){
  unsigned k = 157;
  binary(k);
  return 0;
}
