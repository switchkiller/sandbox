#recursive
//
Node* recurInSubtree(Node *node, int count){
    if (node == NULL) return node;
    if (count == 0) return node;
    struct Node* left, *right;
    left = recurInSubtree(node->left, count-1);
    right = recurInSubtree(node->right, count-1);
    if (left != NULL) return left;
    return right;
}

Node* findRightSiblingUtil(Node* node, int count)
{
    // Code here
    struct Node* parent = node->parent;
    if (parent == NULL) return parent;
    struct Node* st;
    if (parent->left == node){
        st = recurInSubtree(parent->right,count);
        if (st != NULL) return st;
    }
    st = findRightSiblingUtil(parent, count+1);
    return st;
}

Node* findRightSibling(Node* node)
{
    // Code here
    return findRightSiblingUtil(node,0);
}
