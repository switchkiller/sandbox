#include<iostream>

using namespace std;

#define MAXV 1000

struct edgenode{
  int y;
  int weight;
  struct edgenode* next;
};

struct graph{
  edgenode* edges[MAXV];
  int degree[MAXV+1];
  int nvertices;
  int nedges;
  bool directed;
};

void intialize_graph(graph *g, bool directed){
  int i;
  g->nvertices = 0;
  g->edges = 0;
  g->directed = directed;
  for(i = 1; i <= MAXV; i++) g->degree[i] = 0;
  for(i = 1; i <= MAXV; i++) g->edges[i] = NULL;
}

void read_graph(graph *g, bool directed){
  int i;
  int m;
  int x,y;

  intialize_graph(g,directed);

  scanf("%d %d",&(g->directed),&m);

  for (i = 1; i <= m; i++){
    scanf("%d %d",&x,&y);
    insert_edge(g,x,y,directed);
  }
}

void insert_edge(graph *g,int x, int y, bool directed){
    edgenode *p;
    p = (struct edgenode) malloc(sizeof(struct edgenode));
    p->weight = 0;
    p->y = y;

    p->next = g->edges[x];  //g->edge[x] acts as a header, point to its present.
    g->edges[x] = p;        //make new edgenode as present.

    g->degree[x]++;         //count the number of edges x is linked with blah blah

    if (directed == FALSE)
      insert_edge(g,y,x,TRUE);
    else
      g->nedges++;
}

void print_graph(graph *g){
  int i;
  edgenode *p;

  for(i = 1; i <= g->nvertices; i++){
    printf("%d ",i);
    p = g->edges[i];
    while (p != NULL){
      printf("%d",p->y);
      p = p->next;
    }
    printf("\n", );
  }
}

dfs(graph* g, int v){
  edgenode *p;
  int y;

}
