// Problem Description: Tell if the number bit is alternate or not. 

#include<iostream>

using namespace std;

bool checkPow(int y){
  if (y / 2 != 0 )
  {  if (y % 2 != 0)
      return false;
    else
      return checkPow(y / 2);
  }
}
int main(){
  int num, x, y;
  cin>>num;
  x = num << 1;
  y = x ^ num;
  y = y + 1;
  if (checkPow(y))
    cout<<"TRUE";
  else
    cout<<"FALSE";
}
