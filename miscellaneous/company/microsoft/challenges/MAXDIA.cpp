/* Tree node structure  used in the program
struct Node
{
 int data;
 struct Node* left, *right;
}; */

/* Computes the diameter of binary tree with given root.  */

int diameterUtil(struct Node *node){
if (!node)
    return 0;
return max(diameterUtil(node->left), diameterUtil(node->right)) + 1;
}

int diameter(struct Node* node)
{
// Your code here
if (node == NULL) return 0;

return diameterUtil(node->left) + diameterUtil(node->right) + 1;
}
