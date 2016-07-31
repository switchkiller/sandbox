// Sum Tree

/*  Tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
bool isLeaf(struct node *root){
  if (root == NULL) return false;
  if (root->left == NULL && root->right == NULL)
    return true;
  return false;
}
// Bottom-Up
bool isSumTree(struct Node* root)
{
  // Your code here
  int left_sum = right_sum = 0;

  if (root == NULL || (root->left == NULL && root->right == NULL)) return true;

  if (isSumTree(root->left) && isSumTree(root->right)){
    if (root->left)
      left_sum = isLeaf(root->left) ? root->left->data : 2 * (root->left->data);
    if (root->right)
      right_sum = isLeaf(root->right) ? root->right->data : 2 * (root->right->data);

    if (root->data = (left_sum + right_sum))
      return true;
  }
  return false;
}
