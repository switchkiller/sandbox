/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
}; */

/* Computes the height of binary tree with given root.  */
int height(struct Node* node)
{
   // Your code here
   if (node == NULL) return 0;

   return max(height(node->left), height(node->right)) + 1;
}
