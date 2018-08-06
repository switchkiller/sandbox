#include <iostream>
#include <set>
using namespace std;

struct node
{
  int n;
  struct node* next;
};

int main(void)
{
    node* l1 = (node*) malloc(sizeof(node));
    l1->n = 1;
    l1->next = (node*) malloc(sizeof(node));
    l1->next->n = 2;
    l1->next->next = (node*) malloc(sizeof(node));
    l1->next->next->n = 3;
    l1->next->next->next = NULL;

    node* l2 = (node*) malloc(sizeof(node));
    l2->n = 4;
    l2->next = (node*) malloc(sizeof(node));
    l2->next->n = 5;
    l2->next->next = l1->next->next;

    // Checking the intersection
    set<node*> s;
    node* ptr = l1;

    while(ptr != NULL)
    {
      s.insert(ptr);
      ptr = ptr->next;
    }

    ptr = l2;
    while(ptr != NULL)
    {
      if(s.find(ptr) != s.end())
        return !printf("%d\n", ptr->n);
      else
        ptr = ptr->next;
    }
}
