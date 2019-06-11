//function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/* Should convert tree to its mirror */

void rotate(Node *node){
    if (node->left != NULL && node->right != NULL){
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
}

void mirrorUtil(Node *node){
    if (node == NULL) return;
    rotate(node);
    mirrorUtil(node->left);
    mirrorUtil(node->right);
}


void mirror(Node* node)
{
     // Your Code Here
     mirrorUtil(node);
     //inorder(node);

}
