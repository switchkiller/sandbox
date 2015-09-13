#include<iostream>
#include<stdio.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

using namespace std;

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_Traversal();
void BFS(int v);
int queue[MAX], front = -1, rear =-1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void main(){
  create_graph();
  BF_Traversal();
  return 0;
}

void create_graph(){

}

void BF_Traversal(){
  int v;
  for (v = 0; v < n; v++)
    state[v] = initial;
  cin >> v;
  BFS(v);
  for (v = 0; v < n; v++)
    if (state[v] == initial)
      BFS(v);
}

void BFS(int v){
  int i;
  insert_queue(v);
  state[v] = waiting;
  while (!isEmpty_queue()){
    v = delete_queue();
    state[v] = visited;
    cout<<v;
    for (i = 0; i < n; i++){
      if (adj[v][i] == 1 && state[i] == initial){
        insert_queue(i);
        state[i] = waiting;
      }
    }
  }
  cout << endl;
}

void insert_queue(int v){
    if (rear == MAX -1)
      cout << "Queue Overflow.";
    else{
      if (front == -1)
        front = 0;
    }
      queue[++rear] = v;
}

void isEmpty_queue(){
  if (front == -1 || front > rear)
    return 1;
  else
    return 0;
}
