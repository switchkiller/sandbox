//Swap numbers without using arithematic operators.

#include<iostream>
using namespace std;
void swap(int *a, int *b){
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}
int main(){
  int a = 123456789, b = 234567891;
  swap(&a,&b);
  cout<<a<<" "<<b;
  return 0;
}
