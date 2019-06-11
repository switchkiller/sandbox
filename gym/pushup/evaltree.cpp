int evalTree(node* root)
{
    //Your code here
    if (root->left == NULL && root->right == NULL) return stoi(root->data);
    if (root->data == "+")
        return evalTree(root->left)+evalTree(root->right);
    else if (root->data == "-")
        return evalTree(root->left)-evalTree(root->right);
    else return evalTree(root->left)*evalTree(root->right);
}
