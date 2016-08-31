// Vertical order in a tree
// Find the horizontal distance, minimum to max. Now we create partitions acc and print which lie on the same horizontal distance.

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int data){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void findMinMax(struct node *root, int *min, int *max, int hd){
  if (root == NULL) return;

  if (hd < *min) *min = hd;
  if (hd > *max) *max = hd;

  findMinMax(root->left, min, max, hd-1);
  findMinMax(root->left, min, max, hd+1);
}

void printVertical(struct node *root, int i, int hd){
  if (root == NULL) return;

  if (i == hd) printf("%d ", root->data);

  printVertical(root->left, i, hd - 1);
  printVertical(root->right, i, hd + 1);
}


void printVerticalUtil(struct node *root){
  if (root == NULL) return;
  int max = 0, min = 0;
  findMinMax(root,&min,&max,0);

  for (int i = min; i <= max; i++){
    printVertical(root,i,0);
    printf("\n");
  }
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

  printVerticalUtil(root);
  return 0;
}
