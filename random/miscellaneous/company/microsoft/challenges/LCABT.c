// LCA of a Binary Tree
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

struct node *newNode(int data){
  struct node *root = (struct node*) malloc(sizeof(struct node));
  root->data = data;
  root->left = root->right = NULL;
}

struct node *LCA(struct node *root, int v1, int v2){
  if (!root) return root;

  if (root->data == v1 || root->data == v2) return root;

  struct node *left_tree = LCA(root->left, v1, v2);
  struct node *right_tree = LCA(root->right, v1, v2);

  if (left_tree && right_tree)
    return root;

  return (left_tree == NULL) ? right_tree : left_tree;

}




int main(){
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  printf("LCA(4, 5) = %d\n", LCA(root, 4, 5)->data );
  printf("LCA(4, 6) = %d\n", LCA(root, 4, 6)->data );
  printf("LCA(3, 4) = %d\n", LCA(root, 3, 4)->data );
  printf("LCA(2, 4) = %d\n", LCA(root, 2, 4)->data );

  // cout << "\nLCA(4, 6) = " << LCA(root, 4, 6)->data;
  // cout << "\nLCA(3, 4) = " << LCA(root, 3, 4)->data;
  // cout << "\nLCA(2, 4) = " << LCA(root, 2, 4)->data;
  return 0;
}
