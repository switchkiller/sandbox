
#include<iostream>

using namespace std;

int convertFive(int n)
{
//Your code here
    int temp = 0, rem;
    while (n){
        rem = n % 10;
        if (rem == 0)
            rem = 5;
        n /= 10;
        temp = temp*10 + rem;
    }
    while (temp){
        rem = temp % 10;
        temp /= 10;
        n = n*10 + rem;
    }
    return n;
}

int main(){
  cout << convertFive(80);
  return 0;
}
