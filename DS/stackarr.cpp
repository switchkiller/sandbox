#include<stdio.h>
#include<stdio.h>

struct Stack
{
  int top;
  unsigned capacity;
  int* arr;
}

struct Stack* create(unsigned capacity)
{
  Stack* stack=new Stack();
  stack->capacity=capacity;
  stack->top=-1;
  stack->arr=(int*) malloc(stack->capacity* sizeof(int));
  return stack;
}

int isFull()
