#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 100

static int i = 0;
struct node{
  int data;
  struct node *left;
  struct node *right;
};

int swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

struct node *newNode(int data){
  struct node *tmp = (struct node*) malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

int partition(int arr[], int low, int high){
  int p = high;
  int pIndex = low;
  for (int i = low; i < high; i++)
    if (arr[i] < arr[p]){
      swap(&arr[i], &arr[pIndex]);
      pIndex++;
  }
  swap(&arr[p], &arr[pIndex]);
  return pIndex;
}

void quicksort(int arr[],int low, int high){
  if (low < high){
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
  }
}

void convertBT(struct node *root, int *arr, int p){
  if (root == NULL) return;
  convertBT(root->left, arr, p);
  if (p == 0)
    arr[i++] = root->data;
  else
    root->data = arr[i++];
  convertBT(root->right, arr, p);
}

struct node *convertBTUtil(struct node *root){
  if (root == NULL) return root;

  int arr[N];
  convertBT(root, arr, 0);
  // for (int x = 0; x < i; x++)
  // printf("%d ",arr[x]);
  printf("\n");
  quicksort(arr, 0, i-1);
  i = 0;
  struct node *tree = root;
  convertBT(tree,arr,1);
  return tree;
}

void print(struct node *root){
  if (root == NULL) return;

  print(root->left);
  printf("%d ", root->data);
  print(root->right);
}

int main(){
    struct node *root = newNode(10);
    root->left = newNode(2);
    root->left->left = newNode(8);
    root->right = newNode(7);
    root->left->right = newNode(4);

    struct node *tree = convertBTUtil(root);
    print(tree);
    return 0;
}
