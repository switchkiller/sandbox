// Insert into a binary tree.
void insert(node ** root, int val)
{
  // Your code here
    if (*root == NULL){
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        temp->data = val;
        temp->left = temp->right = NULL;
        *root = temp;
        return;
    }

    if (val < (*root)->data)
        insert(&((*root)->left), val);
    else if (val > (*root)->data)
        insert(&((*root)->right), val);
}
