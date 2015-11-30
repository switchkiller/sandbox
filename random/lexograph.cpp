#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = 0; i < b; i++)
#define TRmap(c, itr) for (map<string, int>::iterator itr = (c).begin(); itr != (c).end(); itr++)
// Basic usage.
int main(){
  int val = 0;
  map<string, int> hello;
  string a;
  REP(i,0,10){
    cin >> a;
    hello[a] = val++;
  }
  TRmap(hello, itr)
    cout << itr->first << endl;
  return 0;
}
