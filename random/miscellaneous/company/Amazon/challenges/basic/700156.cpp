/* Node structure
struct Node
{
    int data;
    struct Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */

// Better use preoder or postorder instead of inorder if possible

// Correct
bool checkMirror(Node *a, Node *b){
   if (a == NULL && b == NULL) return true;
   if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
    return false;
  return (a->data == b->data) && checkMirror(a->left, b->right) && checkMirror(a->right, b->left);
}

// Little Buggy
bool checkMirror(Node *a, Node *b){
    if (a == NULL && b == NULL) return true;

    if ((a == NULL && b != NULL) || (a != NULL && b == NULL))
        return false;
    if (!checkMirror(a->left, b->right))
        return false;
    if (a->data == b->data)
        return true;
    else
        return false;
    if (!checkMirror(a->right, b->left))
        return false;
}

int areMirror(Node* a, Node* b)
{
   // Your code here
    if (checkMirror(a,b))
        return 1;
    return 0;

}
