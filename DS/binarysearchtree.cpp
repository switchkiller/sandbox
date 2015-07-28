bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

void initiaze_graph(graph* g){
  int i;
  for(i=1;i<=g->nvertices;i++){
    processed[i]=discovered[i]=FALSE;
    parent[i]=-1;
  }
}

void bfs(graph *g, int start){
  queue q;    // queue of vertices to visit
  int v;      // current vertex
  int y;      // successor vertex
  edgenode *p;
  init_queue(&q);
  enqueue(&q,start);
  discovered[start]=TRUE;
  while (empty_queue(&q) == FALSE){
    v=dequeue(&q);
    process_vertex_early(v);
    processed[v]=TRUE;
    p=g->edge[v];
    while (p!=NULL){
      y=p->y;
      if ((processed[y] == FALSE) || g->directed)
        process_edge(v,y);
      if (discovered[y] == FALSE){
        enqueue(&q,y);
        discovered[y]=TRUE;
        parent[y]=v;
      }
      p=o->next;
    }
    process_vertex_late(v);
  }
}

void process_vertex_late(int v){

}

void process_vertex_early(int v){

}

process_edge(int x, int y){
  nedges=nedges+1;
}
