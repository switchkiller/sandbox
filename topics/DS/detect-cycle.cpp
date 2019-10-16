#include<iostream>
#include<stdlib.h>

using namespace std;

struct node{
  int data;
  struct node* next;
};

void push(struct node** head, int data){
  struct node* temp;
  temp = (struct node* ) malloc(sizeof(struct node));
  temp -> data = data;
  temp -> next = (*head);
  (*head) = temp;
}

int detectloop(struct node* head){
  struct node *slow = head, *fast = head;
  while (slow && fast && fast->next){
    slow = slow ->next;
    fast = fast -> next -> next;
    if (slow == fast){
      cout<<"Hello Loop.";
      return 1;
    }
  }
  return 0;
}

int main(){
  struct node* head = NULL;
  push(&head, 20);
  push(&head, 30);
  push(&head, 40);
  push(&head, 50);
  push(&head, 60);

  //Loop
  head -> next -> next -> next -> next -> next = head;
  detectloop(head);
  return 0;
}
