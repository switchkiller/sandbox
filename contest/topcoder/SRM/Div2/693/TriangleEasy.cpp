// Problem: TriangleEasy
// Level: One
// Tags: #graphs
// Platform: topcoder
// Solved by: switchkiller

#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for (int i = (a); i < (b); i++)
#define RREP(i,a,b) for (int i = (a); i > (b); i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define inf 0x3f3f3f3f
#define ll long long
#define mp make_pair
#define pb push_back
#define LSOne(x) x&(-x)
#define debug(x) cout << #x << " " << x << endl;
#define N 50
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class TriangleEasy{
  public:
      int find(int n, vector <int> x, vector <int> y){
          bool g[N][N] = {{}};
          if (x.size() == 0) return 3;
          REP(i,0,x.size())    // Mark in the adjacent matrix
            g[x[i]][y[i]] = g[y[i]][x[i]] = true;

          REP(i,0,n)
            REP(j,0,n)
                if (g[i][j])
                    REP(k,0,n)
                        if (g[i][k] && g[j][k]) return 0;

          REP(i,0,n){
              int sum = 0;
              REP(j,0,n){
                  sum += (int) g[i][j];
                  if (sum >= 2) return 1;
              }
          }

          return 2;
      }
};
