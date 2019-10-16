#include<bits/stdc++.h>
//std::ios_base::sync_with_studio(false);
using namespace std;
typedef vector<int> vi;
#define scf1s(a) scanf("%s",a)
#define scf2d(a,b) scanf("%d %d",&a, &b)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define all(X) X.begin(),X.end()
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char board[50 + 5][50 + 5];
int cnt, h, w;
void dfs1(int x, int y){                          // For inner connected components
if (x < 0 || y < 0 || x == h || y == w || board[x][y] != 'X') return;
board[x][y] = '*';
REP(i,0,4)
  dfs1(x+dx[i],y+dy[i]);
}
void dfs(int x, int y){                           // For outer connected components
  if (x < 0 || y < 0 || x == h || y == w || board[x][y] == '.') return;
  if (board[x][y] == 'X'){
    cnt++;
    dfs1(x, y);
  }
  board[x][y] = '.';
  REP(i,0,4)
    dfs(x+dx[i], y+dy[i]);
}
int main(){
  int cases = 0;
  while(scf2d(w,h)){
    if (w == 0 && h == 0) break;
    REP(i,0,h)
      scf1s(board[i]);
    vi output;
    REP(i,0,h){
      REP(j,0,w){
        if (board[i][j] != '.'){
          cnt = 0;
          dfs(i,j);
          output.push_back(cnt);
        }
      }
    }
    sort(all(output));
    printf ("Throw %d\n", ++cases);
    printf ("%d", output [0]);
    for ( size_t i = 1; i < output.size(); i++ ) printf (" %d", output [i]);
    printf ("\n\n");
  }
  return 0;
}
