//C program for linked list implementation of stack

#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
  int data;
  struct Node* next;
};

struct Node* newNode(int data)
{
  Node* node= new Node();
  node->data=data;
  node->next=NULL;
  return node;
}

int isEmpty(struct Node* root)
{
  return !root;
}

void push(struct Node** root, int data)
{
  Node* node=newNode(data);
  node->next=*root;
  *root=node;
  cout<<data;
}

int pop(struct Node** root)
{
  if (isEmpty(*root))
    return 0;
  Node* node=*root;
  *root=(*root)->next;
  int pop=node->data;
  free(node);
}

int peek(struct Node* root)
{
  if(isEmpty(*root))
    return 0;
  return root->data;
}

int main()
{
  Node* root=new Node();
  push(&root,10);
  push(&root,20);
  push(&root,30);
  printf("%d\n",pop(&root));
  printf("%d\n",peek(root));
  return 0;
}
