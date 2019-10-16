// Practice on BST
#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data){
  struct node *tmp = (struct node*) malloc(sizeof (struct node ));
  tmp->data = data;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

struct node *insert(struct node *root, int key){
  if (root == NULL) return newNode(key);

  if (key < root->data)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

void inorder(struct node *root){
  if (root == NULL) return;

  inorder(root->left);
  printf("%d\n",root->data);
  inorder(root->right);
}

struct node *minValueNode(struct node *root){
  struct node *current = root;
  while (current->left != NULL)
    current = current->left;

  return current;
}

struct node *deleteit(struct node *root, int key){
  if (root == NULL) return root;

  if (key < root->data)
    root->left = deleteit(root->left, key);
  else if (key > root->data)
    root->right = deleteit(root->right, key);
  // if key is equal to the data
  else{
    if (root->left == NULL){
      struct node *tmp = root->right;
      free(root);
      return tmp;
    }
    else if (root->right == NULL){
      struct node *tmp = root->left;
      free(root);
      return tmp;
    }

    struct node *tmp = minValueNode(root->right);
    root->data = tmp->data;
    root->right = deleteit(root->right, tmp->data);
  }
  return root;
}

void findPreSuc(struct node *root, struct node **pre, struct node **suc, int key){
  if (root == NULL) return;

  if (root->data == key){
    if (root->left != NULL){
      struct node *tmp = root->left;
      while (tmp->right != NULL)
        tmp = tmp->right;
      *pre = tmp;
    }
    if (root->right != NULL){
      struct node *tmp = root->right;
      while (tmp->left != NULL)
        tmp = tmp->left;
      *suc = tmp;
    }
  }

  if (key < root->data){
    *pre = root;
    findPreSuc(root->left, pre, suc, key);
  }
  else if (key > root->data){
      *suc = root;
      findPreSuc(root->right, pre, suc, key);
  }
}

struct node *lca(struct node *root, int n1, int n2){
  if (root == NULL) return NULL;
  if (root->data > n1 && root->data > n2 )
    return lca(root->left, n1, n2);
  else if (root->data < n1 && root->data < n2)
    return lca(root->right, n1, n2);
  return root;
}

// Convert BST to DLL

// Reverse Inorder Traversal

// void bstdllUtil(struct node *root, struct node **prev){
//   if (root->right)
//     bstdllUtil(root->right, prev);
//
//   root->right = (*prev);
//
//   if (*prev != NULL)
//     (*prev)->left = root;
//
//   (*prev) = root;
//
//   if (root->left)
//     bstdllUtil(root->right, prev);
// }

// Ordinary Method
void bstdllUtil(struct node *root, struct node **temp){
  if (root == NULL) return;
  bstdllUtil(root->left, temp);
  if (*temp == NULL)
    *temp = root;
  else{
    struct node *tmp = *temp;
    (*temp)->right = root;
    (*temp) = root;
    (*temp)->left = tmp;
  }
  bstdllUtil(root->right, temp);
}

struct node *bstdll(struct node *root){
  if (root == NULL) return root;

  struct node *tmp = NULL;
  bstdllUtil(root, &tmp);
  tmp->right = NULL;

  while (tmp->left != NULL)
    tmp = tmp->left;
  // tmp->left = NULL;
  return tmp;
}

int main(){
  struct node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  inorder(root);
  root = deleteit(root, 20);

  inorder(root);
  node* pre = NULL, *suc = NULL;

  findPreSuc(root, &pre, &suc, 65);
  if (pre != NULL)
    printf("Predecessor is %d\n", pre->data);
  else
    printf("No Predecessor");

  if (suc != NULL)
    printf("Successor is %d\n", suc->data);
  else
    printf("No Successor");

  printf("%d\n",lca(root, 20, 30)->data);

  root = bstdll(root);
  while(root){
    printf("%d ",root->data);
    root = root->right;
  }
  return 0;
}
