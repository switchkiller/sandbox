#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#define MAX 26

using namespace std;
struct node
{
  char data;
  node *left;
  node *right;
};

struct node* newTreeNode(char data)
{
  node* newNode = new node;
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}


int getIndex(char* arr, char val, int size)
{
  for(int i=0; i<size;i++) {
    if(arr[i] == val)
    return i;
  }
  return -1;
}

struct node* create_bintree(char* parray, char* iarray, int size)
{
  if(size == 0) return NULL;

  char rootVal = parray[0];
  struct node* root  = newTreeNode(rootVal);
  int newIdx = getIndex(iarray, rootVal, size);
  root->left = create_bintree(parray+1, iarray, newIdx);
  root->right = create_bintree(parray+newIdx+1, iarray+newIdx+1, size-newIdx-1);
  return root;
}

void postorder(struct node *root){
  if (root == NULL) return;

  postorder(root->left);
  postorder(root->right);
  cout << root->data;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("536-in.txt" , "r" , stdin);
   freopen("536-out.txt" , "w" , stdout);
  #endif
  string line;
  while(getline(std::cin, line)){
    stringstream ss(line);
    char pre[MAX], in[MAX];
    ss >> pre >> in;
    int n = strlen(pre);
    // cout << pre;
     node* tree = create_bintree(pre, in, n);
     postorder(tree);
     cout << endl;
  }

  return 0;
}
