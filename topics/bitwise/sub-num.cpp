// Sutraction of two numbers :p
#include<iostream>
using namespace std;
int subtractItr(int x, int y)
{
  while (y != 0){
    int borrow = (~x) & y;
    x = x ^ y;
    y = borrow << 1;
  }
  return x;
}

int subtractRec(int x, int y){
  if (y == 0)
    return x;
  return subtractRec(x^y, ((~x) & y) << 1);
}

int main(){
  int x = 29, y= 12;
  cout<<subtractItr(x,y);
  cout<<subtractRec(x,y);
  return 0;
}
