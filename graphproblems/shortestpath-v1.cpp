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
