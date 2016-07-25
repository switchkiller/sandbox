// Given a sorted (increasing order) array with unique elements, write an algorithm to create binary search tree with minimal height.

/*-------------------------------------------------------
                      <Methodology>
Algorithm:
1. Make the middle element as the root of the tree.
2. Insert (into the left subtree) the left subarray element.
3. Insert (into the right subtree) the right subarray element.
4. Recurse.
O(N) time and O(logN) space.
---------------------------------------------------------*/


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

struct node *createMinBSTUtil(int arr[], int low, int high){
  if (low <= high){
    int mid = (low + high) / 2;
    struct node *root = newNode(arr[mid]);
    root->left = createMinBSTUtil(arr, low, mid-1);
    root->right = createMinBSTUtil(arr, mid+1, high);
    return root;
  }
  return NULL;
}

struct node *createMinBST(int arr[], int n){
  return createMinBSTUtil(arr, 0, n);
}

void inorder(struct node *root){
  if (root == NULL) return;

  inorder(root->left);
  printf("%d\n",root->data);
  inorder(root->right);
}

int main(){
  int arr[] = {1,2,3,4,5,6,7};
  int n = sizeof(arr)/sizeof(arr[0]);
  struct node *treenode = createMinBST(arr,n-1);
  inorder(treenode);
  return 0;
}
