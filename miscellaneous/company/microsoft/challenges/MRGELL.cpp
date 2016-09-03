// Sorted Merge on Linked Lists

/* Link list Node
struct Node {
    int data;
    struct Node* next;
}; */

struct Node* SortedMerge(struct Node* head1,  struct Node* head2)
{
    struct Node *result = NULL;

    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data <= head2->data){
        result = head1;
        result->next = SortedMerge(head1->next, head2);
    }
    else{
        result = head2;
        result->next = SortedMerge(head1, head2->next);
    }

    return result;
}
