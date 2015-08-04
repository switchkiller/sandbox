struct Vertex{
  int info;
  struct Vertex* nextVertex;
  struct Edge* firstEdge;
}*start=NULL;

struct Edge{
  struct Vertex* destVertex;
  struct Edge* nextEdge;
};

void insertVertex(int u){
  struct Vertex *tmp,*ptr;
  tmp=malloc(sizeof(struct Vertex));
  tmp->info=u;
  tmp->nextVertex=NULL;
  tmp->firstEdge=NULL;
  if (start==NULL)
  {
    start=tmp;
    return;
  }
  ptr=start;
  while(ptr->nextVertex!=NULL)
    ptr=ptr->nextVertex;
  ptr->nextVertex=tmp;
}

void insertEdge(int u, int v){
  struct Vertex *locu,*locv;
  struct Edge *ptr,*tmp;
  locu=findVertex(u);
  locv=findVertex(v);
  if (locu==NULL || locv==NULL);
    //Error.
  if (locu->firstEdge==NULL){
     locu->firstEdge=locv;
     return;
  }
  tmp->destVertex=locv;
  tmp->nextEdge=NULL;
  ptr=locu->firstEdge;
  while (ptr!=NULL)
    ptr=ptr->nextEdge;
  ptr->nextEdge=tmp;
}

void deleteVertex(int u){
  struct Vertex *tmp1, *tmp2;
  struct Edge *ptr, *tmp;
  tmp1=start;
  if (start->info==u){
    tmp2=start;
    start=start->nextVertex;
  }
  while (tmp1->nextVertex!=NULL){
    if (tmp1->nextVertex==u){
      tmp2=tmp1->nextVertex;
      tmp1->nextVertex=tmp1->nextVertex;
    }
    tmp1=tmp1->nextVertex;
  }
  if (tmp1->nextVertex==NULL){
    tmp2=tmp1->nextVertex;
    tmp1==NULL;
  }
  deleteEdge(tmp2);
  free (tmp2);
}

void deleteEdge(struct Vertex* vertex){
  
}


struct Vertex* findVertex(int x){
  struct Vertex *locx;
  locx=start;
  while(locx!=NULL)
  { if (locx->info==x)
      return locx;
    locx=locx->nextVertex;
  }
}
