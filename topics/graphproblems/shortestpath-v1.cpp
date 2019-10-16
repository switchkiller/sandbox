#include<iostream>
#include<stdio.h>

using namespace std;

#define MAXV 100
#define infinity 9999
#define NIL -1
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAXV][MAXV];
int state[MAXV];
int distance[MAXV];
int predecessor[MAXV];
void create_graph();
void BF_Traversal();
void BFS(int v);
int queue[MAXV], front = -1, rear = -1;
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();

int main(){
  int v, count =0,
  create_graph();
  BF_Traversal();
  while(1){
    cout << "Enter the destination vertex (-1 to quit.)";
    cin >> v;
    if (v < -1 || v > n-1){
      cout<<"Does not exist.";
      continue;
    }
    if (v == -1)
      break;
    if (distance[v] == infinity){
      cout << "No path.";
      continue;
    }
    else
      cout << "Shortest Distance = " << distance[v];
    while (v != NIL){
      count++;
      path[count] = v;
      u = predecessor[v];
      v = u;
    }
    cout << "Shortest path : ";
    for (i = count; i > 1; i--)
      cout << "->" << path[i];
    cout << path[i];
    cout << endl;
  }
}

void BF_Traversal(){
  int v;
  for (v = 0; v <= n; v++){
    state[v] = initial;
    predecessor[v] = NIL;
    distance[v] = infinity;
  }
  cin >> v;
  BFS(v);
  cout << endl;
}

void BFS(int v){
  distance[v] = 0;
  predecessor[v] = NIL;
  insert_queue(v);
  state[v] = waiting;
  while (!isEmpty_queue()){
      v = delete_queue();
      state[v] = visited;
      for (int i = 0; i < n; i++){
        if (adj[v][i] == 1 && state[i] = initial){
          insert_queue(i);
          state = waiting;
          predecessor[i] = v;
          distance[i] = distance[v] + 1;
        }
      }
  }
}
