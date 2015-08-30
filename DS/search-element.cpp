#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node{
  int data;
  struct node* next;
};

void push(struct node** head_ref, int data){
  struct node* current;
  current = (struct node* ) malloc(sizeof(struct node));
  current -> data = data;
  current -> next = (*head_ref);
  (*head_ref) = current;
}

void search(struct node* head, int key){
  struct node* temp;
  int index = 0;
  temp = head;
  while (temp != NULL){
    if (temp -> data == key)
      cout<<index+1;
    index++;
    temp = temp -> next;
  }
}

int main(){
  struct node* head = NULL;
  int key = 10;
  push(&head,10);
  push(&head,20);
  push(&head,30);
  push(&head,40);
  push(&head,50);
  search(head,key);
  return 0;
}
