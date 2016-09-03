// Find the sum of path from root to leaf.
bool hasPathSum(Node *node, int sum)
{
   //Your code here
   if (node == NULL) return (sum == 0);

   int subSum = sum - node->data;
   bool ans = 0;

   if (subSum == 0 && (node->left == NULL) && (node->right == NULL))
    return true;

   if (node->left)
    ans = ans || hasPathSum(node->left, subSum);

   if (node->right)
    ans = ans || hasPathSum(node->right, subSum);

   return ans;
}
