//Performed in 2D grid coloring.
#include<iostream>

typedef vector< ii > vii;
typedef pair<int, int> ii;

using namespace std;

#define V 10
#define REP(i,a,b) for (int i = int(a); i <= int(b); i++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define TRvii(c,it) for(vii::iterator it = (c).begin(); it != (c).end(); it++)

int dfs_num[V];

void floodfill(int u, int color){
  dfs_num[u] = color;
  TRvii(AdjList[u],v)
    if (dfs_num[v->first] == DFS_WHITE)
      floodfill(v->first,color);
}

int main(){
    int numComponent = 0;
    REP(i,0,V-1)
      if (dfs_num[i] == DFS_WHITE)
        floodfill(i, ++component);
  REP(i,0,V-1)
    cout << "Vertex " << i <<" has colour "<<dfs_num;
    return 0;
}
