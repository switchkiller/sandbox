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
