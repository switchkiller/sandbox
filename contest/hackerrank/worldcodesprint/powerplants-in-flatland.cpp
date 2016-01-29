#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define REP(a,b,i) for (int i = (a); i < (b); i++)
#define all(x) x.begin(), x.end()
#define TRvi(c, it) for (vi::iterator it = (c).begin(); it != (c).end(); it++)
int Maxflatland(vector<int> c, int n, int m){
  int dis[n], max;
  memset(dis, -1, sizeof dis);
  sort(all(c));
  TRvi(c, itr){
    max = 0;
    //cout << *itr << " ";
    REP(0,n,i){
      if (*itr == i)
        dis[i] = 0;
      else{
        if (dis[i] != -1)
          dis[i] = min(dis[i], abs(*itr - i));
        else
          dis[i] = abs(*itr - i);
      }
      //cout << dis[i] << " ";
      if (dis[i] > max)
        max = dis[i];
    }
    //cout << endl;
  }
  return max;
}
int main(){
  int n, m;
  cin >> n >> m;
  vi c(m);
  for(int c_i = 0;c_i < m;c_i++){
     cin >> c[c_i];
  }
  if (n == m)
    cout << "0";
  else
    cout << Maxflatland(c,n,m);
  return 0;
}

//   0 1 2 3 4
// 0 0 1 2 3 4
// 4 0 1 2 1 0

//   0 1 2 3 4 5
// 0 0 1 2 3 4 5
// 1 0 0 2 3 4 5
// 2 0 0 0 3 4 5
// 3 0 0 0 0 4 5
// 4 0 0 0 0 0 5
// 5 0 0 0 0 0 0
