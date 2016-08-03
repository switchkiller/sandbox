/* A binary tree node
struct node
{
    int data;
    struct Node* left, * right;
}; */

void printBoundaryLeft(node *root){
    if (root == NULL)
        return;
    if (root->left){
        cout << root->data << " ";
        printBoundaryLeft(root->left);
    }
    else if (root->right){
        cout << root->data << " ";
        printBoundaryLeft(root->right);
    }
}

void printBoundaryRight(node *root){
    if (root == NULL)
        return;
    if (root->right){
        printBoundaryRight(root->right);
        cout << root->data << " "; // Because we have to print in reverse order for left
    }
    else if (root->left){
        printBoundaryRight(root->left);
        cout << root->data << " ";
    }

}

bool isLeaf(node *root){
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void printLeaves(node *root){
    if (root){
        printLeaves(root->left);
        if (isLeaf(root)) cout << root->data << " ";
        printLeaves(root->right);
    }
}


void printBoundary(node *root)
{
//Your code here
    if (root){
        cout << root->data << " ";

        printBoundaryLeft(root->left);
        printLeaves(root->left);
        printLeaves(root->right);
        printBoundaryRight(root->right);
    }
}
