#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
struct stack
{
	int top;
	unsigned capacity;
	char* arr;
};

struct stack* createStack(unsigned capacity)
{
	stack* Stack=new stack();
	Stack->capacity=capacity;
	Stack->top=-1;
	Stack->arr=(char*)malloc(Stack->capacity* sizeof(int));
	return Stack;
}

int isEmptyStack(struct stack* Stack)
{
	return Stack->top==-1;
}

int isFullStack(struct stack* Stack)
{
	return Stack->top==Stack->capacity-1;
}

void push(struct stack* Stack, char item)
{
	if (isFullStack(Stack))
		return ;
	Stack->arr[++Stack->top]=item;
}

char pop(struct stack* Stack)
{
	if (isEmptyStack(Stack))
 		return 'a';
	return Stack->arr[Stack->top--];
}

void reverse(char str[])
{
	int n=strlen(str);
	struct stack* Stack=createStack(n);
	int i;
	for( i=0; i<n; i++)
		push(Stack, str[i]);
	for( i=0; i<n; i++)
		str[i]=pop(Stack);
}

int main()
{
	char str[]="Barun Singhania";
	reverse(str);
	printf("%s", str);
	return 0;
}

