// Print the left view of the tree

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int key){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->data = key;
  temp->left = temp->right = NULL;
  return temp;
}

void leftView(struct node *root, int level, int *max_level){
  if (root == NULL) return;

  if (*max_level < level){ // Which means this level is now discovered. Once visited we wont visit it again
    *max_level = level;
    printf("%d ", root->data);
  }

  leftView(root->left, level + 1, max_level);
  leftView(root->right, level + 1, max_level);
}


void leftViewUtil(struct node *root){
    int max_level = 0;
    leftView(root, 1, &max_level);
}

int main(){
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->left->right = newNode(8);
  root->right->right->right = newNode(9);

  leftViewUtil(root);

  return 0;
}
