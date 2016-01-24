#include<bits/stdc++.h>
#define REP(a,b) for (int i = (a); i < (b); i++)
#define MAX 1000
#define pb push_back
#define TRvvi(c, it) for (vvi::iterator it = (c).begin(); it != (c).end(); it++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int main(){
  int N, Q, k, val, cnt = 0;
  int a, b;
  cin >> N >> Q;
  vi arr[N];
  while (N--){
    cin >> k;
    REP(0, k){
      cin >> val;
      arr[cnt].pb(val);
    }
    cnt++;
  }
  while (Q--){
    cin >> a >> b;
    cout << arr[a][b] << endl;
  }
  return 0;
}
