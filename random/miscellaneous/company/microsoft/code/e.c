#include<stdio.h>
#include<stdlib.h>
#define REP(i,a,b) for (int i = (a); i < (b); i++)
struct AdjNode{
  int dest;
  struct AdjNode *next;
};

struct AdjList{
  struct AdjNode *head;
};

struct Graph{
  int v;
  struct AdjList *arr;
};

struct AdjNode *newAdjListNode(int dest){
  struct AdjNode *newAdjNode = (struct AdjNode *) malloc(sizeof (struct AdjNode));
  newAdjNode->dest = dest;
  newAdjNode->next = NULL;
  return newAdjNode;
}

struct Graph *createGraph(int v){
  struct Graph *graph = (struct Graph*) malloc(sizeof (struct Graph));
  graph->v = v;
  graph->arr = (struct AdjList*) malloc(v * sizeof (struct AdjList));
  REP(i,0,v)
    graph->arr[i].head = NULL;
  return graph;
}

void addEdge(struct Graph *g, int a, int b){
  struct AdjNode *newNode = newAdjListNode(b);
  newNode->next = g->arr[a].head; // Insertion at beginning
  g->arr[a].head = newNode;

  // Undirected graph

  newNode = newAdjListNode(a);
  newNode->next = g->arr[b].head;
  g->arr[b].head = newNode;
}

void printGraph(struct Graph *graph){
  int v = 0;
  for (v = 0; v < graph->v; v++){
    struct AdjNode *pcrawl = graph->arr[v].head;
    printf("\n Adjacency list of vertex %d\n head ", v);
    while (pcrawl){
      printf("-> %d", pcrawl->dest);
      pcrawl = pcrawl->next;
    }
    printf("\n");
  }
}

int main(){
  int V = 5;
  struct Graph *graph = createGraph(V);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  printGraph(graph);

  return 0;
}
// Description
// Pros: Saves space O(|V|+|E|) . In the worst case, there can be C(V, 2) number of edges in a graph thus consuming O(V^2) space. Adding a vertex is easier.
//
// Cons: Queries like whether there is an edge from vertex u to vertex v are not efficient and can be done O(V).
