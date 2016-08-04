/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

// Recursive function to print right view of a binary tree.
void printKdistance(struct Node *root, int k)
{
  // Your code here
  if (!root) return;
  if (k == 0)
    cout << root->data << " ";

  printKdistance(root->left, k-1);
  printKdistance(root->right, k-1);
}
