// Implement a function to check if a binary tree is balanced

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data){
  struct node *tmp = (struct node*) malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

int max(int a, int b){ return a > b ? a : b;}

// Returns the height of the tree for comparision O(N) time and O(logN) space
int isBalancedUtil(struct node *root){
  if (root == NULL)
    return 0;

  int leftHeight = isBalancedUtil(root->left);
  // Means any lower subtree is not balanced. Hence whole tree is not balanced.
  // Max space in stack is O(logN)
  if (leftHeight == -1)
    return -1;

  int rightHeight = isBalancedUtil(root->right);

  if (rightHeight == -1)
    return -1;

  int diff = leftHeight - rightHeight;

  if (diff > 1)
    return -1;
  return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(struct node *root){
  if (isBalancedUtil(root) == -1)
    return false;
  return true;
}

int main(){
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->left->left->left = newNode(7);

  printf("%d\n",isBalanced(root));

  return 0;
}
