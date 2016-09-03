/* Link list Node
struct Node
{
    int data;
    struct Node* next;
}; */

// Deletes middle of linked list and returns head of the modified list
struct Node* deleteMid(struct Node *head)
{
     // Your Code Here
     struct Node *slow = head, *fast = head;
     struct Node *prev;
     while (slow && fast && fast->next){
         prev = slow;
         slow = slow->next;
         fast = fast->next->next;
     }
     prev->next = slow->next;
     free(slow);
     return head;
}
