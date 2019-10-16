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

//Iterative Solution
int searchItr(struct node* head, int key){
  struct node* temp;
  int index = 0;
  temp = head;
  while (temp != NULL){
    if (temp -> data == key)
      return index+1;
    index++;
    temp = temp -> next;
  }
}

// Recursive Solution
int searchRec(struct node* head, int key, int plus){
  if (head == NULL )
    return -plus;
  if (head ->data == key)
    return 1;
  return 1 + searchRec(head -> next, key, plus+1);
}

int main(){
  struct node* head = NULL;
  int key = 00;
  push(&head,10);
  push(&head,20);
  push(&head,30);
  push(&head,40);
  push(&head,50);
  cout<<searchItr(head,key);
  cout<<searchRec(head,key,0);
  return 0;
}
