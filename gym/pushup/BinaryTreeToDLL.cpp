/* Using Pre-order traversal. It is not a onepass solution.
This is a function problem.You only need to complete the function given below*/
/* Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should convert a given Binary tree to Doubly
// Linked List
Node *bToDLLHelper(Node *root){
        // your code here
    if (!root) return NULL;
    Node *newNode = new Node(root->data);
    Node *left = bToDLL(root->left)
    Node *right = bToDLL(root->right);
    newNode->left = left;
    if (left)
        left->right = newNode;
    newNode->right = right;
    if (right)
        right->left = newNode;
    return newNode;
}

void bToDLL(Node *root, Node **head_ref)
{
    Node *newDLL = bToDLLHelper(root);
    while (newDLL->left) newDLL = newDLL->left;
    *head = newDLL;
}


/* Using BT inorder traversal and dummy node logic. But this is giving WA because pointer memory allocation is improper.

// This function should convert a given Binary tree to Doubly
// Linked List

void bToDLLHelper(Node* root, Node *prev){
    if (!root) return;
    bToDLLHelper(root->left,prev);
    Node *newNode = new Node(root->data);
    prev->right = newNode;
    newNode->left = prev;
    prev = prev->right;
    bToDLLHelper(root->right,prev);
}

void bToDLL(Node *root, Node **head_ref)
{
    // your code here
    *head_ref = new Node(0);
    Node *prev = *head_ref;
    bToDLLHelper(root,prev);
    prev = *head_ref;
    *head_ref = (*head_ref)->right;
    if (*head_ref)
        (*head_ref)->left = nullptr;
    delete prev;
}
*/
