// Problems on binary trees solved
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<queue>
using namespace std;
struct node{
  int data;
  struct node *left;
  struct node *right;
};

int max(int a,int b){ return (a > b) ? a : b;}

struct node *newNode(int data){
  struct node *tmp = (struct node*) malloc(sizeof(struct node));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
// Calculate the maximum depth of the tree
int maxDepth(struct node *root){
  if (root->left == NULL || root->right == NULL) return 0;
  return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}

// print node at k distance
void printKth(struct node *root, int k, int _depth){
  if (root== NULL) return;
  printKth(root->left, k, _depth+1);
  printKth(root->right, k, _depth+1);
  if (_depth == k) printf("%d\n",root->data);
}

// print the ancestor of given node

bool printAncestor(struct node *root, int key){
  if (root == NULL) return false;
  if (root->data == key) return true;
  if (printAncestor(root->left, key) || printAncestor(root->right, key)){
    printf("%d\n", root->data );
    return true;
  }
  return false;
}

// check if the binary tree is subtree of another tree

bool identical(struct node *root1, struct node *root2){
  if (root1 == NULL && root2 == NULL) return true;
  if (root1 == NULL || root2 == NULL) return false;

  return (root1->data == root2->data && identical(root1->left, root2->left) &&
            identical(root1->right, root2->right));
}

bool checkSubtree(struct node *root1, struct node *root2){
  if (root1 == NULL) return false;
  if (root2 == NULL) return true;

  if (identical(root1,root2))
    return true;

  return checkSubtree(root1->left, root2) || checkSubtree(root1->right, root2);
}

//  Find sum of data of all leaves of a binary tree on same level and then multiply sums obtained of all levels.

bool isLeaf(struct node *root){
  if (root->left == NULL && root->right == NULL)
    return true;
  return false;
}

int sumnmultiply(struct node *root){
  if (root == NULL) return 0;
  int prod = 1;
  queue<struct node *> q;
  q.push(root);

  while(1){
    int nodeCnt = q.size();
    if (nodeCnt == 0)
      break;
    int leafSum = 0;
    bool leafFound = false;

    while (nodeCnt > 0){
      struct node *Node = q.front();

      if (isLeaf(Node)){
        leafFound = true;
        leafSum += Node->data;
      }
      q.pop();
      if (Node->left != NULL) q.push(Node->left);
      if (Node->right != NULL) q.push(Node->right);
      nodeCnt--;
    }

    if (leafFound == true)
    prod *= leafSum;
  }

  return prod;
}

int main(){
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  printf("%d\n",maxDepth(root));
  printKth(root, 1, 0);
  printAncestor(root, 5);
  printf("%d\n",sumnmultiply(root));

  // Test case for identical trees
  // struct node *T        = newNode(26);
  // T->right              = newNode(3);
  // T->right->right       = newNode(3);
  // T->left               = newNode(10);
  // T->left->left         = newNode(4);
  // T->left->left->right  = newNode(30);
  // T->left->right        = newNode(6);
  //
  //
  // struct node *S    = newNode(10);
  // S->right          = newNode(6);
  // S->left           = newNode(4);
  // S->left->right    = newNode(30);
  //
  //
  // if (checkSubtree(T, S))
  //     printf("Tree 2 is subtree of Tree 1");
  // else
  //     printf("Tree 2 is not a subtree of Tree 1");

  return 0;
}
