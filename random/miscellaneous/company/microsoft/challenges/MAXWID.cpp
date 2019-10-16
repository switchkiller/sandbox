// Pending
/*  Structure of a Binary Tree
struct Node
{
    int data;
    struct Node* left, *right;
}; */

/* Function to get the maximum width of a binary tree*/

void getMaxWidthUtil(struct Node *root, int *maxWidth, int *minWidth, int hd){
    if (!root) return;

    if (*maxWidth < hd)
        *maxWidth = hd;
    if (*minWidth > hd)
        *minWidth = hd;

    getMaxWidthUtil(root->left, maxWidth, minWidth, hd-1);
    getMaxWidthUtil(root->right, maxWidth, minWidth, hd+1);
}

int getMaxWidth(Node* root)
{
   // Your code here
   int maxWidth = 0, minWidth = 0;
   getMaxWidthUtil(root, &maxWidth, &minWidth, 0);
   cout << maxWidth;
}
