// Solve the maze.
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int V, E, a, b, counter, s;
vector<vii> AdjList;
map<int, int> mapper, reverseMapper;
vi p;
void printPath(int u) {
  if (u == s) { printf("%d", reverseMapper[u]); return; }
  printPath(p[u]);
  printf(" %d", reverseMapper[u]); }
  
int main() {
  scanf("%d %d", &V, &E);
  counter = 0;
  AdjList.assign(V, vii());
  for (int i = 0; i < E; i++) {
    scanf("%d %d", &a, &b);
    if (mapper.find(a) == mapper.end()) { // mapping trick
      mapper[a] = counter++;
      reverseMapper[mapper[a]] = a;
    }
    if (mapper.find(b) == mapper.end()) {
      mapper[b] = counter++;
      reverseMapper[mapper[b]] = b;
    }
    AdjList[mapper[a]].push_back(ii(mapper[b], 0));
    AdjList[mapper[b]].push_back(ii(mapper[a], 0));
  }
  s = mapper[1];
  // BFS routine
  map<int, int> dist; dist[s] = 0;
  queue<int> q; q.push(s);
  p.assign(V, -1);
  int layer = -1;
  bool isBipartite = true;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (dist[u] != layer) printf("\nLayer %d:", dist[u]);
    layer = dist[u];
    printf(", visit %d", reverseMapper[u]);
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
      ii v = AdjList[u][j];
      if (!dist.count(v.first)) {
        dist[v.first] = dist[u] + 1;
        p[v.first] = u;
        q.push(v.first);
      }
      else if ((dist[v.first] % 2) == (dist[u] % 2))
              isBipartite = false;
  } }
  printf("\nShortest path: ");
  printPath(mapper[23]), printf("\n");
  printf("isBipartite? %d\n", isBipartite);
  return 0;
}
