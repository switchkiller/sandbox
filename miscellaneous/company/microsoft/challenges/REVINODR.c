// Reverse Level Order Traversal
/* A tree node has data, pointer to left child
   and a pointer to right child
struct node
{
    int data;
    struct node* left;
    struct node* right;
}; */

int maxHeight(struct node *root){
    if (!root) return 0;
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

void levelOrderUtil(struct node *root, int level){
    if (!root) return;

    if (level == 1)
        cout << root->data << " ";

    else{
        levelOrderUtil(root->left, level-1);
        levelOrderUtil(root->right, level-1);
    }
}

void reversePrint(struct node *root)
{
    int h = maxHeight(root);
    for (int i = h; i >= 0; i--)
        levelOrderUtil(root, i);

}
