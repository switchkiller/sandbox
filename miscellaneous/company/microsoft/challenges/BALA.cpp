
/* A binary tree node structure
struct Node {
    int data;
    struct Node* left, * right;
}; */

// This function should return tree if passed  tree
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree

int isBalancedUtil(struct Node *root){
    if (root == NULL) return 0;

    int leftHeight, rightHeight;

    leftHeight = isBalancedUtil(root->left);

    if (leftHeight == -1)
        return -1;

    rightHeight = isBalancedUtil(root->right);

    if (rightHeight == -1)
        return -1;

    int diff = abs(leftHeight - rightHeight);

    if (diff > 1)
        return -1;
    else
        return max(leftHeight, rightHeight) + 1;
}



bool isBalanced(struct Node *root)
{
    //  Your Code here
    if (isBalancedUtil(root) == -1)
        return false;
    return true;
}
