#include<cstddef>
#include<iostream>
#include<string.h>
#include<bitset>
using namespace std;
int main(){
  bitset<32> bitvec;
  bool is_set = bitvec.any();
  bool not_set = bitvec.none();
  cout << "bitvec: " << bitvec <<endl;
  size_t sz = bitvec.size();
  size_t bit_set = bitvec.count();
  for (int i = 0; i != 32; i += 2)
    bitvec[i] = 1;    //**.
  // **. using set operation.
  for (int i =0; i != 32; i += 2)
    bitvec.set(i);
  unsigned i;
  //bitvec loop using set operation.
  for (int i = 0; i != 32; i++)
    if (bitvec[i])
      cout << i << " ";
    cout << endl;

  bitvec.reset(0); // Turn off the first bit.
  bitvec[0] = 0; //same as above.

  bitvec.reset();  // set all the bits to 0;
  bitvec.set();    // set all the bits to 1;

  bitvec.flip(0);   // reverse value of the first bit.
  bitvec[0].flip(); // also reverse the first bit.

  bitvec.flip();

  bitvec = ~bitvec;

  bitset<16> bitvec1(0xffff); // bits 0 to 15 are set to 1;
  bitset<32> bitvec2(0xffff); // bits 0 .. 15 are set to 1; 16 .. 31 are set 0
  // on a 32 bit system, bits 0 to 31 initialized from 0xffff;
  bitset<128> bitvec3(0xffff); // bits 32 ... 127 initialized to 0;

   return 0;
 }
