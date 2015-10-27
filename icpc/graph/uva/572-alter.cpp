/*---------------------
| Author: switchkiller |
| Problem: UVa 572     |
| Tags: flood_fill, dfs|
----------------------*/
#include<bits/stdc++.h>
using namespace std;
#define ssi(a,b) scanf("%d %d", &a, &b)
#define REP(i,a,b) for(int i = a; i < b; i++)
int r, c;
char s[110][110];
int dx[] = {-1,0,1,0,-1,-1,1,1}, dy[] = {0,1,0,-1,-1,1,1,-1};
void floodfill(int i, int j){
  if (i < 0 || i > r-1 || j < 0 || j > c-1 || s[i][j] != '@') return;
  s[i][j] = '*';
  REP(x,0,8)
    floodfill(i+dx[x],j+dy[x]);
}
int main(){
  int x = 0, cnt;
  while(ssi(r,c) == 2){
    getchar();
    if (r == 0 && c == 0)
      break;
      cnt = 0;
      REP(i,0,r)
        cin >> s[i];
      x = 0;
      while (x < r){
        int y = 0;
        while (y < c){
          if (s[x][y] == '@'){
            cnt++;
            floodfill(x,y);
          }
          y++;
        }
        x++;
      }
      printf("%d\n", cnt);
  }
  return 0;
}
