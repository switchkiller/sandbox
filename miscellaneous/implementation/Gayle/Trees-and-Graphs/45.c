// Check if binary tree is a BST

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int data){
  struct node *tmp = (struct node*) malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

void inorder(struct node *root){
  if (root == NULL) return;

  inorder(root->left);
  printf("%d\n",root->data);
  inorder(root->right);
}

static int i = 0;

bool isbst(struct node *root){
  if (root = NULL) return true;

  if (!isbst(root->left))
    return false;

  if (i != 0  && root->data <= i){
    return false;
  }
  i = root->data;

  if (!isbst(root->right))
    return false;

  return true;
}

int main(){
  struct node *root = NULL;
  root = newNode(50);
  root->left = newNode(30);
  root->left->left = newNode(20);
  root->left->right = newNode(40);
  root->right = newNode(70);
  root->right->left = newNode(60);
  root->right->right = newNode(80);

  // inorder(root);
  printf("%d\n",isbst(root) );


  return 0;
}
