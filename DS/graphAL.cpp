#include<iostream>
#include<stdio.h>

using namespace std;

#define MAXV 1000

typedef struct{
  int weight;
  int y;
  struct edgenode *next;
}edgenode;

typedef struct{
  edgenode* edge[MAX+1];
  int degree[MAX+1];
  int nvertices;
  int nedges;
  bool directed;
}graph;

void initiaze_graph(graph* g, bool directed){
  int i;
  g->nvertices=0;
  g->nedges=0;
  g->directed=directed;
  for (i=1; i<=MAXV; i++) g->degree[i]=0;
  for (i=1; i<=MAXV; i++) g->edges[i]=NULL;
}

void read_graph(graph* g, bool directed){
  int i;
  int m;  //no of edges in graph
  int x,y;

  initiaze_graph(g, directed);
  cin>>g->nvertices>>m;

  for(i=1;i<=m;i++){
    cin>>x>>y;
    insert_edge(g,x,y,directed);
  }
}

void insert_edge(graph* g, int x, int y, bool directed){
  edgenode *p;
  p=(edgenode*) malloc(sizeof(edgenode));
  p->weight=NULL;
  p->y=y;
  p->next=g->edge[x];
  g->edge[x]=p;
  g->degree[x]++;
  if (directed == FALSE)
    insert_edge(g,y,x, TRUE);
  else
    g->nedges++;
}

void print_graph(graph* g);
