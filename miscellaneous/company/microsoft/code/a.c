// Display nth element from last

#include<stdio.h>
#include<stdlib.h>
struct node{
  int val;
  struct node* next;
};

void insert(struct node **head,int val){
  struct node *temp = (struct node*) malloc(sizeof(struct node));
  struct node *ptr = *head;
  temp->val = val;
  temp->next = NULL;
  if (*head == NULL){
    *head = temp;
  }
  else{
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

int nthfromlast(struct node **head,int n){
  int len = 0;
  struct node *temp = *head;
  while (temp != NULL ){
    temp = temp->next;
    len++;
  }

  temp = *head;

  for(int i = 0; i < (n-len+1); i++)
    temp = temp->next;

  return temp->val;
}
