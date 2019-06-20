// Not correct solution - Bipartite method wont work
int LISSUtil(struct Node *root, bool color){
    if (root == NULL) return 0;
    int ans = 0;
    cout << root->data << " " << color<< endl;
    ans = LISSUtil(root->left, !color) + LISSUtil(root->right, !color);
    if (color)
        ans += 1;
    return ans;
}

int LISS(struct Node *root)
{
    //Code here
    cout << LISSUtil(root, true) << " " << LISSUtil(root, false);
    return 0;
}
