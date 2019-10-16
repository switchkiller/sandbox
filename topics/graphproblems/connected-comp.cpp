#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;

#define DFS_WHITE -1
#define DFS_BLACK 1
#define V 10
#define REP(i,a,b) for (int i = (a); i <= (b); i++)

int main(){
  numComponent = 0;
  REP(i,0,V-1) {  if (dfs_num[i] == DFS_WHITE)
    printf("Connected component %d :",++numComponent);
    dfs(i);
  }
}
