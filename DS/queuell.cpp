/*---------------------
| Author: switchkiller |
----------------------*/
#include<iostream>
using namespace std;
class LinkedList
{
  node *head;
public:
  LinkedList();
  LinkedList(int val);
  ~LinkedList();
  //void traverse();
  void Print();
  void Append(int data);
  void Delete(int data);
}
/*void LinkedList::traverse()
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
*/
}
LinkedList::LinkedList(){
  head = NULL;
}

LinkedList::LinkedList(val){
  head = new node(val);
  tail = head;
}

void LinkedList::Print(){
  node *tmp = head;
  if (tmp == NULL){
    cout<<"LIST EMPTY"<<endl;
    return;
  }
  if ( tmp != NULL){
    cout<<tmp->Data()<<"-->";
    tmp = tmp->Next();
  }
  if (tmp->Next() == NULL) cout<<"NULL";
  return;
}
void LinkedList::Append(int data){
  //create a new node
  node* newNode = new node();
  newNode->node_data(data);
  newNode->node_next(NULL);

  node *tmp = head;

  if (tmp != NULL){
    while(tmp->Next() != NULL)
    {
      tmp = tmp->Next();
    }
  tmp->node_next(newNode);
  }
  else{
    head = newNode;
  }
}

void LinkedList::Delete(int data){
    node *tmp = head;
    if (tmp == NULL)
      return;
    if (tmp->Next() == NULL){
      delete tmp;
      head = NULL;
    }
    else{
      node *prev;
      do{
        if (tmp->Data() == data) break;
        prev=tmp;
        tmp=tmp->Next();
      }while (tmp != NULL);
      prev->node_next(tmp->Next());
      delete tmp;
    }
}

class node
{
  int key;
  node *next;
private:
  node();
  void node_data(int val);
  void node_next(node* anext);
  int Data();
  node* Next();
  ~node();
};
int node::Data(){
  return key;
}
node::node()
{}
void node::node_data(int val){
  key = val;
}
void node_next(node* anext){
  next=anext;
}
node *node::Next(){
  return next;
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
