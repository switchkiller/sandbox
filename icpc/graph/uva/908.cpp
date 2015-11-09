#include<bits/stdc++.h>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi pset(1000);
void initSet(int N){
  REP(i,0,N)
    pset[i] = i;
}
int findSet(int i){
  return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
}
void unionSet(int i, int j){
  pset[findSet(i)] = findSet(j);
}
int isSameSet(int i, int j){
  return findSet(i) == findSet(j);
}
vector< pair<int, ii > > EdgeList;
int N, T, K, M, a, b, w, c  = 0;

int Kruskal(){
  sort(all(EdgeList));
  int mst = 0;
  initSet(N);
  REP(i,0,EdgeList.size()){
      pair< int, ii > front = EdgeList[i];
      if (!isSameSet(front.second.first, front.second.second)){
        unionSet(front.second.first, front.second.second);
        mst += front.first;
      }
      return mst;
  }
}
int main(){
    while(scanf("%d\n", &N) == 1){
      EdgeList.clear();
      c++;
      REP(i,0,N-1){
        scanf("%d %d %d\n",&a, &b, &w);
        EdgeList.pb(make_pair(w,ii(a-1, b-1)));
      }
      if (c > 1) printf("\n");
      printf("%d\n", Kruskal());
      EdgeList.clear();
      scanf("%d\n", &k);
      REP(i,0,K){
        scanf("%d %d %d\n",&a, &b, &w);
        EdgeList.pb(make_pair(w,ii(a-1, b-1)));
      }
      scanf("%d\n", &M);
      REP(i,0,M){
        scanf("%d %d %d\n",&a, &b, &w);
        EdgeList.pb(make_pair(w,ii(a-1, b-1)));
      }
      printf("%d\n",Kruskal());
    }
    return 0;
}
