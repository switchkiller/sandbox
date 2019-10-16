#include<iostream>
#include<list>
using namespace std;

class Graph{
  int V;
  list<int> *adj;
public:
  Graph(int V);
  ~Graph();

  void addEdge(int v, int w){ //Undirected
      adj[v].push_back(w);
      adj[w].push_back(v);
  }

  void greedyColoring();
};

void Graph::greedyColoring(){
  int result[V];
  result[0] = 0;
  for (int u = 1; u < V; u++) //Assign no color.
    result[u] = -1;
  bool avialable[V];
  for (int cr = 0; cr < V; cr++)
    avialable[cr] = false;
  for (int u =1; u < V; u++){
    list<int>>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
      if (result[*i] != -1)
        avialable[result[*i]] = true;
    int cr;
    for (cr = 0; cr < V; cr++)
      if (avialable[cr] == false)
        break;
      result[u] = cr;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
      if (result[*i] != -1)
        avialable[result[*i]] = false;
  }

  for (int u = 0; u < V; u++)
    cout << "Vertex " << u << "---> Color " << result[u] <<endl;
}

//main()
