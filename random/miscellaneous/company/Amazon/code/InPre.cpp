// Inorder and preoder given, construct the binary tree and the print leaves.

#include<iostream>
#include<stdio.h>
using namespace std;

struct node {
  int data;
  struct node *left, *right;
};

int getIndex(int *in, int val, int n){
  for (int i = 0; i < n; i++)
    if (in[i] == val)
      return i;
  return -1;
}

struct node* newNode(char data)
{
  node* newNode = new node;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

struct node *constructBtree(int *in, int *pre, int n){
  if (n == 0) return NULL;

  struct node * root = newNode(pre[0]);
  int idx = getIndex(in, pre[0], n);
  root->left = constructBtree(in, pre+1, idx);
  root->right = constructBtree(in+idx+1, pre+idx+1, n-idx-1);
  return root;
}

bool isLeaf(struct node *root){
  if (root->left == NULL && root->right == NULL)
    return true;
  return false;
}

void leafOrder(struct node *root){
  if (root == NULL) return;

  leafOrder(root->left);
  if (isLeaf(root))
    cout << root->data << " ";
  leafOrder(root->right);
}


int main(){
  int n;
  cin >> n;
  int *in = new int[n];
  int *pre = new int[n];

  for (int i = 0; i < n; i++)
    cin >> in[i];

  for (int i = 0; i < n; i++)
    cin >> pre[i];

  struct node *root = constructBtree(in, pre, n);

  leafOrder(root);
  return 0;
}
