// All the questions on linked list solved.

#include<stdio.h>
#include<stdlib.h>

#define REP(i,a,b) for (int i = (a); i < (b); i++)

struct node{
  int data;
  struct node *next;
};

void insertAtEnd(struct node **head, int data){
  struct node *tmp = (struct node*) malloc(sizeof(struct node)), *ptr = *head;
  tmp->data = data;
  tmp->next = NULL;
  if (*head == NULL){
    *head = tmp;
    return;
  }
  while(ptr->next != NULL)
    ptr = ptr->next;
  ptr->next = tmp;
}

void insertAtPos(struct node **head, int data, int p){
  struct node *tmp = (struct node*) malloc(sizeof(struct node)), *ptr = *head;
  struct node *prev = NULL;
  int pos = 0;
  tmp->data = data;
  tmp->next = NULL;
  if (p == 0){
    if (*head == NULL)
      *head = tmp;
    tmp->next = *head;
    *head = tmp;
    return;
  }
  else if (p > 0){
    while(ptr->next != NULL){
      prev = ptr;
      ptr = ptr->next;
       if ((++pos) == p)  break;
    }
    if (pos == p){
      tmp->next = prev->next;
      prev->next = tmp;
    }
    else printf("Overflow\n" );
  }
}

void deleteLL(struct node **head, int key){
  struct node *temp = *head, *prev;
  if (temp->data == key){
    *head = temp->next;
    return;
  }
  while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
    if (temp->data == key){
      prev->next = temp->next;
      free(temp);
      break;
    }
  }
}

void deleteLLPos(struct node **head, int pos){
  struct node *temp = *head, *prev;
  int p = 0;
  if (pos == 0){
    *head = temp->next;
    return;
  }
  while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
    p++;
    if (p == pos){
      prev->next = temp->next;
      free(temp);
      break;
    }
  }
}

void reverseLL(struct node **head){
  struct node *prev = NULL, *temp = *head, *nxt;
  while(temp){
    nxt = temp->next;
    temp->next = prev;
    prev = temp;
    temp = nxt;
  }
  *head = prev;
}

void swapLL(struct node **head, int a, int b){
  struct node *copy, *temp = *head;
  struct node *prev1, *prev2;
  int ap = 0, bp = 0;

  while(temp->next != NULL){
    if ((ap++) < a)
      prev1 = temp;
    if ((bp++) < b)
      prev2 = temp;
    temp = temp->next;
  }
  printf("%d\n",prev1->data );
  printf("%d\n",prev2->data );

  struct node *tmp1 = prev1->next, *tmp2 = prev2->next;
  prev1->next=tmp2;
  prev2->next=tmp1;   //a bit up and down
  copy=tmp2->next;    //Just Created a copy
  tmp2->next=tmp1->next;
  tmp1->next=copy;
}

void removeCycle(struct node *point, struct node **head){
  struct node *tmp = *head; int cnt = 0;
  if (point == *head) cnt++;
  while(tmp){
    if (tmp->next == point)
    cnt++;
    if (cnt == 2) tmp->next = NULL;
    tmp = tmp->next;
  }
}
// Floyd Cycle Detection
int detectCycle(struct node *head){
  struct node *slowptr = head, *fastptr = head;
  while(slowptr && fastptr && fastptr->next){
    slowptr = slowptr->next;
    fastptr = fastptr->next->next;
    if (slowptr == fastptr){
      removeCycle(slowptr,&head);
      return 1;
    }
  }
  return 0;
}

void rotateLL(struct node **head, int k){
  struct node *tmp = *head, *prev;
  int pos = 0;
  while(tmp->next != NULL){
    if (pos++ == k) break;
    prev = tmp;
    tmp = tmp->next;
  }
  struct node *temp = tmp->next;
  prev->next = NULL;

  while(temp->next != NULL)
    temp = temp->next;

  temp->next = *head;
  *head = tmp;
}


void printLL(struct node *head){
  while(head){
    printf("%d ",head->data );
    head = head->next;
  }
}

int main(){
  struct node *head = NULL;
  insertAtEnd(&head,1);
  insertAtEnd(&head,2);
  insertAtEnd(&head,3);
  insertAtEnd(&head,9);
  insertAtEnd(&head,10);
  insertAtEnd(&head,4);
  insertAtPos(&head,5,3);
  deleteLL(&head,2);
  deleteLLPos(&head,0);
  reverseLL(&head);
  swapLL(&head,1,3);  // (0<a<b<n)
  printLL(head);
  head->next->next->next = head;
  printf("\nCycle: %d\n",detectCycle(head));
  printLL(head);
  printf("\n");
  rotateLL(&head, 1); // (0<k<n)
  printLL(head);
  return 0;
}
