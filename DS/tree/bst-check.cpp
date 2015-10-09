#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

/*int isBST(struct node *root){  // wrong solution. Because the left or right subtree may have element greater than the root node.
 if (root  == NULL)
	return 1; 	// Boundary condition
 if (root->left != NULL && root->left->data > root->data)
	return 0;
 if (root->right != NULL && root->right->data < root->data)
	return 0;
 if (!isBST(root->left) || !isBST(root->right))
	return 0;
 return 1;
} // TEST : 3 2 5 1 4 */

/*int isBST(struct node *root) { // right solution but is not efficient. Many recursive calls to the subtree --> too slow. Using a  helper max value func and min val func.
  if (root == NULL)
	return 1;
  if (root->left != NULL && max(root->left) > root->data)
	return 0;
  if (root->right != NULL && min(root->right) < root->data)
	return 0;
  if (!isBST(root->left) || !isBST(root->right))
	return 0;
  return 1;
} */

int isBSTUtil(struct node *node, int min, int max){
	if (node == NULL)
		return 1;
	if (node->data < min || node->data > max)
		return 0;
	return isBSTUtil(node->left, min, node->data - 1) && isBSTUtil(node->right, node->data + 1, max);
}

int isBST(struct node *root, int min, int max)[
	return (isBSTUtil(struct node* root, INT_MIN, int INT_MAX));
}

struct node *newNode(int data){
	struct node *node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/* bool isBST(struct node *root){
	static struct node *prev = NULL;
	if (root){
	if (!isBST(root->left))
		return false;
	if (prev != NULL && root->data <= prev->data)
		return false;
	prev = root;
	return isBST(root->right);
	}
	return true;
}*/

int main(){
	struct node *root = neNode(4);
	root->left = newNode(2);
	root->right = newNode(5);
	root->left->right = newNode(1);
	root->left->right = newNode(3);

	if (isBST(root))
		// Is BST
	else
		// Not a BST
	return 0;
}
