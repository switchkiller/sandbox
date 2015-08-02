/*---------------------
| Author: switchkiller |
----------------------*/

#include<iostream>
#include<stdio.h>

#define MAX 100

using namespace std;

int adj[MAX][MAX]
int num;

void create(){
  int i,max_edges,origin,destin;
  printf("%d",&num); //Number of vertices
  max_edges=num*(num-1);
  for (int i=0;i<=max_edges;i++){
    cout<<i<<":";
    cin>>origin>>destin;
    if ((origin==-1) && (destin==-1))   //-1 -1 to quit
      break;
    if ((origin<0) || (origin>=n) || (destin<0) || (destin>=n))
      i--;                                  //Incase of invalid re-insert edge at ith pos.
    else
      adj[origin][destin]=1;
  }
}

void insert_edge(int insert, int destin){
  if (origin<0 || origin>=n)
    //origin doesnot exist
    return;
  if (destin<0 || destin>=n)
    //destination doesnot exist
    return;
  adj[origin][destin]=0;
}

void del_edge(int ins, int des){
  if ((ins<0) || (ins>=n) || (dis<0) || (dis>=n) || adj[ins][des]==0)
  {
    //Invalid deletion
    return;
  }
  adj[ins][des]=0;
}
