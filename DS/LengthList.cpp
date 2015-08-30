#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node{
  int data;
  struct node* next;
};

void push(struct node** head, int data){
  struct node* temp;
  temp = (struct node*) malloc(sizeof(struct node*));
  temp -> data= data;
  temp -> next = (*head);
  (*head) = temp;
}

int getCount(struct node* head){
  int count = 0;
  struct node* temp = head;
  while (temp != NULL){
    count++;
    temp = temp -> next;
  }
  return count;
}

int main()
{
  struct node* head = NULL;

  push(&head,1);
  push(&head,1);
  push(&head,1);
  push(&head,1);
  push(&head,1);
  cout<<getCount(head);
}
