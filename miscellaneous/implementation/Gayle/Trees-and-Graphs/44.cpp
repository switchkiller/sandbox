// Given a binary tree, design an algorithm which creates a LL of each depth.
// Counter method 2 - Need a dfs solution.
// Solved using level order traversal 
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int data){
  node *temp = new node;
  temp->key = data;
  temp->left = temp->right = NULL;
  return temp;
}

// bfs
struct node *btdll(struct node *root){
  if (root == NULL)
    return NULL;
  node *dll = NULL;
  node *tmp = root;
  queue<struct node *> q;
  q.push(root);
  while(!q.empty()){
    node *temp = q.front();
    q.pop();
    if (temp->left != NULL)
      q.push(temp->left);
    if (temp->right != NULL)
      q.push(temp->right);

    temp->right = dll;
    if (dll != NULL)
      dll->left = temp;
    dll = temp;
  }
  dll->left = NULL;
  return dll;
}

int main(){
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->left->right = newNode(9);
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);

  node *dll = btdll(root);

  while (dll){
    printf("%d\n", dll->key);
    dll = dll->right;
  }

  return 0;
}
