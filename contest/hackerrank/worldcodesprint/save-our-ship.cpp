#include<bits/stdc++.h>
using namespace std;
#define REP(a,b,i) for (int i = (a); i < (b); i++)
int main(){
  int x = 0, cnt = 0;
  string com = "SOS", str;
  cin >> str;
  REP(0,str.size(),i){
    if (str[i] != com[x]){
      cnt++;
    }
    x = (x+1) % 3;
  }
  cout << cnt;
  return 0;
}
