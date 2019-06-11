Node* cloneTree(Node* tree)
{
   Node *temp = newNode(tree->data);
   if (tree->left == NULL && tree->right == NULL) return temp;
   temp->left = cloneTree(tree->left);
   temp->right = cloneTree(tree->right);
   return temp;
}
