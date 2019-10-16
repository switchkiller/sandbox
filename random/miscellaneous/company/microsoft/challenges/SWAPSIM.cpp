/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as
  struct node
  {
     int data;
     struct node *next;
  }
*/

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwap(struct node *head)
{
   // The task is to complete this method
   struct node *temp = head;
   while (temp && temp->next){
       swap(&temp->data, &temp->next->data);
       temp = temp->next->next;
   }
}
