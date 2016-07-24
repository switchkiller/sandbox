// Add leaves of Binary tree to DLL
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int data){
  struct node *Node = (struct node *)malloc(sizeof(struct node));
  Node->data = data;
  Node->left = NULL;
  Node->right =NULL;
  return Node;
}

bool isLeaf(struct node *root){
  if (root->left == NULL && root->right == NULL) return true;
  return false;
}

void leaftoDLL(struct node *root, struct node **prev){
  if (root == NULL) return;
  leaftoDLL(root->right, prev);
  if (isLeaf(root)){

    root->right = *prev;
    if (*prev != NULL)
      (*prev)->left = root;
    (*prev) = root;
  }
  leaftoDLL(root->left, prev);
}

int main(){

  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  struct node *head = NULL;
  leaftoDLL(root, &head);
  head->left = NULL;

  while(head){
    printf("%d ", head->data);
    head = head->right;
  }

  return 0;
}
