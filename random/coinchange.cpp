//Recursive solution to the minimum coin change problem
#include<bits/stdc++.h>
using namespace std;
#define REP(a,b) for (int i = (a); i < (b); i++)
int minimumcoin(int amt, int dom[], int size){
  if (amt <= 0) return 0;
  int min_coin = (int) INT_MAX;
  REP(0,size)
    if (dom[i] <= amt)
      min_coin = min(min_coin, minimumcoin(amt - dom[i], dom, size) + 1);
  return min_coin;
}
int main(){
  int dom[] = {1, 5, 8};
  int amt = 0;
  cin >> amt;
  int size = sizeof(dom) / sizeof(dom[0]);
  cout << minimumcoin(amt, dom, size);
  return 0;
}

////////////////////////////
//  0 1 2 3 4 5 6 7 8 9 10 /
//1 0 1 2 3 4 5 6 7 8 9 10 /
//5 0 1 2 3 4 1 2 3 4 5 2  /
//8 0 1 2 3 4 5 6 7 1 2 3  /
////////////////////////////
