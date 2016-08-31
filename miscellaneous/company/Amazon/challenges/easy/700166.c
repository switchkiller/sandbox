// Check if the height is balanced or not

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
  int data;
  struct Node *left, *right;
};

struct Node *newNode(int key){
  struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = key;
  temp->left = temp->right = NULL;
  return temp;
}

int max(int a, int b){ return (a>b?a:b);}

int isBalancedUtil(struct Node *root){
  if (root == NULL) return 0;

  int leftHeight = isBalancedUtil(root->left);

  if (leftHeight == -1)
    return -1;

  int rightHeight = isBalancedUtil(root->right);

  if (rightHeight == -1)
    return -1;

  int diff = (leftHeight - rightHeight);

  if (diff > 1)
    return -1;

  return max(leftHeight, rightHeight) + 1;
}


bool isBalanced(struct Node *root){
    //  Your Code here
    if (isBalancedUtil(root) == -1)
      return false;
    return true;
}


int main(){
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);
  root->right->right->right = newNode(9);

  printf("%d\n",isBalanced(root));
  return 0;
}
