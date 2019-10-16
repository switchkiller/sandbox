#include<iostream>
#include<cstdio>
using namespace std;
struct ArrayQueue{
  int front, rear;
  int capacity;
  int *array;
}
struct ArrayQueue *Queue(int size){
  struct ArrayQueue *Q = (struct ArrayQueue) malloc(sizeof(struct ArrayQueue));
  if (!Q) return NULL;
  Q->capacity = size;
  Q->front = Q->rear = -1;
  Q->array = malloc (Q->capacity * sizeof(int));
  if (!Q->array)
    return NULL;
  return Q;
}
