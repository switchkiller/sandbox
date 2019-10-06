Node *lca(Node *root, int a, int b){
    if (!root) return NULL;

    if (root->data == a || root->data == b) return root;

    Node *left = lca(root->left,a,b);
    Node *right = lca(root->right,a,b);

    if (left && right) return root;
    return (left) ? left : right;
}

int findDistance(Node *root, int x){
    if (!root) return 0;

    if (root->data == x) return 1;
    int left = findDistance(root->left,x);
    int right = findDistance(root->right, x);

    if (left || right) return (left+right+1);

    return 0;
}

int findDist(Node* root, int a, int b)
{
    // Your code here
    Node *ancestor = lca(root,a,b);

    int left = max(findDistance(ancestor->left,a),findDistance(ancestor->left,b));
    int right = max(findDistance(ancestor->right,a),findDistance(ancestor->right,b));

    return (left+right);
}
