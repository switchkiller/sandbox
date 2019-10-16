/* The structure of the Linked list Node is as follows:
struct node {
    int val;
    struct node* next;
}; */

void insert(struct node **head, int data){
    struct node *tmp = *head;
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->val = data;
    temp->next = NULL;

    if (*head == NULL)
        *head = temp;
    else{
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = temp;
    }
}

void intersection(struct node **head1, struct node **head2, struct node **head3)
{
    // Your Code Here
    struct node *temp1 = (*head1), *temp2 = (*head2);

    if (!temp1 || !temp2) return;

    while (true){
        while (temp1 && (temp1->val < temp2->val))
            temp1 = temp1->next;

        if (temp1 == NULL)
            break;

        while (temp2 && (temp2->val < temp1->val))
            temp2 = temp2->next;

        if (temp2 == NULL)
            break;

        while (temp1 && temp2 &&(temp1->val == temp2->val)){
            insert(head3, temp1->val);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if (temp1 == NULL || temp2 == NULL)
            break;
    }

}
