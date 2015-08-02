/*---------------------
| Author: switchkiller |
----------------------*/

#include<iostream>
#include<stdio.h>

#define MAX 100

using namespace std;

int adj[MAX][MAX];
int num;

void create(){
  int i,max_edges,origin,destin;
  printf("Number of vertices: %d\n",num); //Number of vertices
  max_edges=num*(num-1);
  for (int i=0;i<=max_edges;i++){
    cout<<i<<":";
    cin>>origin>>destin;
    //cout<<origin<<"--"<<destin<<endl;
    if ((origin==-1) && (destin==-1))   //-1 -1 to quit
      break;
    if ((origin<0) || (origin>=num) || (destin<0) || (destin>=num))
      i--;                                  //Incase of invalid re-insert edge at ith pos.
    else
      adj[origin][destin]=1;
  }
}

void insert_edge(int insert, int destin){
  if (insert<0 || insert>=num)
    //origin doesnot exist
    return;
  if (destin<0 || destin>=num)
    //destination doesnot exist
    return;
  adj[insert][destin]=1;
  //cout<<insert<<"--"<<destin<<endl;
}

void del_edge(int ins, int des){
  if ((ins<0) || (ins>=num) || (des<0) || (des>=num) || adj[ins][des]==0)
  {
    //Invalid deletion
    return;
  }
  adj[ins][des]=0;
}

void display(){
  int i,j;
  for(i=0;i<MAX;i++){
    for(j=0;j<MAX;j++){
        if (adj[i][j]==1)
          cout<<i<<"--"<<j<<endl;
      }
  }
}


int main(int argc, char *argv[]){
  int x,y;
  cin>>num;   //No. of vertices
  create();
  cin>>x>>y; //Node to insert
  insert_edge(x,y);
  cin>>x>>y; //Node to delete
  del_edge(x,y);
  cout<<"Graph Display: \n";
  display();
  return 0;
}
