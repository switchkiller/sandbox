#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int key){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

int max(int a, int b){
  return (a>b?a:b);
}

int height(struct node *root){
  if (root == NULL) return 0;
  return max(height(root->left),height(root->right))+1;
}

void printSpiral(struct node *root,int level, bool ltr){
  if (root == NULL) return;
  if (level == 1)
    printf("%d ", root->key );
  else if (level > 1){
    if (ltr){
      printSpiral(root->left, level-1, ltr);
      printSpiral(root->right, level-1, ltr);
    }
    else{
      printSpiral(root->right, level-1, ltr);
      printSpiral(root->left, level-1, ltr);
    }
  }
}

void printSpiralUtil(struct node *root){
  int h = height(root);
  bool ltr = false;
  for (int i = 1; i <= h; i++){
    printSpiral(root, i, ltr);
    ltr = !ltr;
  }
}

int main(){
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(7);
  root->left->right = newNode(6);
  root->right->left  = newNode(5);
  root->right->right = newNode(4);
  printf("Spiral Order traversal of binary tree is \n");
  printSpiralUtil(root);

  return 0;
}
