#include<iostream>
using namespace std;
void emit_answer(int n);
void f(int index, int bits, int number) {
    if (index == 0) {
        if (bits == 0) {   // all required bits have been used
            emit_answer(number); // chuck number into an array, print it, whatever.
        }
        return;
    }

    if (index-1 >= bits) {  // If we can afford to put a 0 here
        f(index-1, bits, number);
    }

    if (bits > 0) {  // If we have any 1s left to place
        f(index-1, bits-1, number | (1 << (index-1)));
    }
}

void emit_answer(int number){
  cout<<number<<endl;
}

// to call:
int main(){
  f(6, 3, 0);
  return 0;
}
