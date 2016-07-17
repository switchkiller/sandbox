#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define inf 0x3f3f3f3f
string s;
void swap(int a, int b){
  char temp = s[a];
  s[a] = s[b];
  s[b] = temp;
}
int main(){
    cin >> s;
    int n = s.size() - 1, pos = -1, idx = n;
    string::iterator temp;
    for (string::iterator it = s.rbegin(); it != s.rend(); it++)
      if ( *it > s[n] ){
        idx--;
        continue;}
      else{
        pos = idx;
        temp = it;
        break;
      }
    swap(pos, n);
    sort(temp+1,s.end());
    cout << s;
    return 0;
}
