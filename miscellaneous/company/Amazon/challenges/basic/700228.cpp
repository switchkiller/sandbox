// Print Sibling
#include<iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};

/* Prints the Nodes having no siblings.  */
void printSibling(struct Node* node)
{
  // Your code here
  if (node == NULL) return;

  if (node->left != NULL && node->right != NULL){
    printSibling(node->left);
    printSibling(node->right);
  }
  else if (node->left != NULL){
    cout << node->left->data << endl;
    printSibling(node->left);
  }

  else if (node->right != NULL){
    cout << node->right->data << endl;
    printSibling(node->right);
  }
}

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);
    printSibling(root);
    return 0;
}
