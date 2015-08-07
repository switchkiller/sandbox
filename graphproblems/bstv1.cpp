/*---------------------
| Author: switchkiller |
----------------------*/
#include<iostream>
#include<stdio.h>
#include<list>
#include<algorithm>
using namespace std;
class Graph{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  void addEdge(int V, int w);
  void bfs(int s);
};

Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void addEdge(int V, int w){
  adj[V].push_back(w);
}

void bfs(int s){
  bool *visited = new visited[V];
  for (int i=0; i < V; i++)
    visited[i] = FALSE;
  list<int> queue;
  visited[s] = TRUE;
  queue.push_back(s);
  list<int>::iterator itr;
  while(!queue.empty){
    s = queue.front();
    cout<<s<<" ";
    queue.pop_front();
    for(itr=adj[s].begin();itr!=adj[s].end();++itr){
      if (!visited[*itr]){
        visited[*itr]=TRUE;
        queue.push_back(*itr);
      }
    }
  }
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
