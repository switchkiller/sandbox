// Middle element

/*struct Node {
    int data;
    struct Node* next;
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(struct Node *head)
{
   //Linked List is empty!!.
   if (!head)
     return -1;

   struct Node *slow, *fast;
   slow = head;
   fast = head;

   while (fast && fast->next)
   {
       slow = slow->next;
       fast = fast->next->next;
   }
   return slow->data;
}


// This also works
int getMiddle(struct Node *head)
{
   // Your code here
    struct Node *slow = head;
    struct Node *fast = head->next;

    if (head == NULL)
        return -1;


    while(fast && fast->next){
        fast = fast->next;
        if (fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow->next->data;
}
