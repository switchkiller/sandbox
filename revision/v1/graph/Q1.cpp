/* Implementation of bfs */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
#define REP(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
typedef vector<int> vi;
typedef list<int> Queue;
vi AdjList[MAXN];
bool visited[MAXN];
int v,e;
int c = 0;
int bfs(int s){
  visited[s] = true;
  Queue Q;
  Q.pb(s);
  vector<int>::iterator itr;
  while (!Q.empty()){
    s = Q.front();
    Q.pop_front();
    cout << s <<" ";
    for(itr = AdjList[s].begin(); itr != AdjList[s].end(); ++itr){
      if (!visited[*itr]){
      visited[*itr] = true;
      Q.pb(*itr);
      }
    }
  }
  return ++c;
}
int main(){
  //ios_base::sync_with_studio(false);
  int n,x,y;
  cin >> n;
  REP(i,0,n){
    AdjList[MAXN].clear();
    cin >> v;       // Number of vertex
    cin >> e;       //Number of edges
    //Vertex can be resized.
    REP(j,0,e){
      cin >> x >> y;
      AdjList[x].pb(y);
      AdjList[y].pb(x);
    }
    REP(j,0,v){
      if (visited[j] == false)
        bfs(j);
    }
  }
  return 0;
}
