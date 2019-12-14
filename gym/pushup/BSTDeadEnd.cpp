// Trees - ***
/*This is a function problem.You only need to complete the function given below*/
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */

Node* isDeadEndUtil(Node *root, int min, int max){
    if (!root) return nullptr;

    if (root->data+1 == max && root->data-1 == min) return root;

    Node *left = isDeadEndUtil(root->left, min, root->data);
    Node *right = isDeadEndUtil(root->right, root->data, max);

    return left ? left : right;


}
bool isDeadEnd(Node *root)
{
    //Your code here
    Node *deadEnd = isDeadEndUtil(root,0,INT_MAX);
    if (deadEnd) return true;
    return false;
}
