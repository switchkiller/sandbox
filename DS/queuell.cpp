/*---------------------
| Author: switchkiller |
----------------------*/
#include<iostream>
using namespace std;
class LinkedList
{
  node *head;
  node *tail;
public:
  LinkedList();
  LinkedList(int val);
  ~LinkedList();
  void traverse();
}
void LinkedList::traverse()
{
  node *temp = head;
  if (temp == NULL){
    cout<<"List Empty"<<endl;
    return;
  }
  cout<<"Elements: ";
  while (p!=NULL){
    cout<<temp->key;
    temp = temp->next;
  }
  cout<<endl;
}

}
LinkedList::LinkedList(){
  head = tail = NULL;
}

LinkedList::LinkedList(val){
  head = new node(val);
  tail = head;
}

class node
{
  int key;
  qnode *next;
private:
  node();
  node(int val);
  ~node();
};
node::node():next(NULL)
{}

node::node(int val){
  key = val;
  next = NULL;
}

node::~node()
{
}

class queue: public node
{
  qnode *front, *rear;
private:
  void enqueue(int k);
  void

};

queue::queue()
{
  q->front = q->rear = NULL;
  return q;
}

int main()
{

  return 0;
}
