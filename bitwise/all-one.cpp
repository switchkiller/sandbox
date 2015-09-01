#include<iostream>
using namespace std;
int count = 0;
int all_one(int x){
  if (x == 1)
    return 0;
  if (x % 2 != 0)
    count++;
  else
    all_one(x/2);
}
int main(){
  int x;
  cin>>x;
  x++;
  all_one(x);
  if (count == 0)
    cout<<"TRUE";
}
