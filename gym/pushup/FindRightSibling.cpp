Node *ans;

bool findSibling(Node *currNode, Node *prevNode, int level){
    if (currNode == nullptr) return false;

    if (currNode == prevNode)
    return false;

    if (level == 0) {
        ans = currNode;
        return true;
    }

    if (currNode->left){
        return findSibling(currNode->left, currNode, level-1);
    } else {
        return findSibling(currNode->right, currNode, level-1);
    }
}

Node* findRightSibling(Node* node)
{
    // Code here
    int level = 0;
    while(node->parent != nullptr){
        level++;
        bool res = findSibling(node->parent->right, node, level-1);
        if (res == true) return ans;
        node = node->parent;
    }
    return nullptr;
}
