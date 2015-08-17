/*---------------------
| Author: switchkiller |
----------------------*/
#include<iostream>
using namespace std;
struct QNode{
  int key;
  QNode *next;
};
struct queue{
  QNode *front, *rear;
};
QNode* newNode(int k){
  QNode *temp = new QNode;
  temp->key = k;
  temp->next = NULL;
  return temp;
}
queue *createQueue()
{
  queue *q = new queue;
  q->front = q->rear = NULL;
  return q;
}

void enqueue(queue *q, int k){
  QNode *temp = newNode(k);
  if (q->rear == NULL){
    q->front = q->rear =temp;
    return;
  }
  q->rear->next = temp;
  q->rear =temp;
}

QNode *deQueue(queue *q){
  if (q->front == NULL)
    return NULL;
  QNode *temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL)
    q->rear = NULL;
  return temp;
}

int main(){
  queue *q = createQueue();
  enqueue(q,10);
  enqueue(q,20);
  deQueue(q);
  deQueue(q);
  enqueue(q,30);
  QNode *n = deQueue(q);
  cout<<n->key;
  return 0;
}
