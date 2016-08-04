/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/

struct Node * mergeResultUtil(Node *node1,Node *node2)
{
    // your code goes here
    struct Node *root = NULL;
    if (!node1)
        return node2;
    if (!node2)
        return node1;

    if (node1->data <= node2->data){
        root = node1;
        root->next = mergeResultUtil(node1->next, node2);
    }
    else{
        root = node2;
        root->next = mergeResultUtil(node1, node2->next);
    }

    return root;
}

struct Node * mergeResult(Node *node1,Node *node2){
    struct Node *head = mergeResultUtil(node1, node2);
    struct Node *prev = NULL;
    struct Node *temp = head, *next;
    while (temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
