// Check if binary tree is a BST

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include<stdio.h>
#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

int i = 0;
struct node *newNode(int data){
        struct node *temp = (struct node *) malloc(sizeof (struct node));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
}

bool btisbst(struct node *root){
    if (root == NULL) return true;
    if (!btisbst(root->left))
        return false;
    if ( i != 0 && root->data <= i)
        return false;
    i = root->data;
    if (!btisbst(root->right))
        return false;
    return true;
}


int main(){
    node *root = newNode(50);
    root->left = newNode(30);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right = newNode(70);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    cout << btisbst(root);
    return 0;
}

}
