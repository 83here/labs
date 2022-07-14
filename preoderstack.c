#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int top=-1;

struct node {
  int item;
  struct node* left;
  struct node* right;
}*root,*a,*stack[MAX];

void push(struct node *y){

    stack[++top]=y;
}

void pop()
{

    if(top==-1)
    {}

    else
    {
    a=stack[top];
    --top;
    }

}

void preorder(struct node* root)
{

printf("%d",root->item);
push(root);
root=root->left;
if(root==NULL)
{
    while(root==NULL)
    {
        if (top==-1)
        {
         return;
        }
        else 
        {
        pop();
        printf("popped this %d\n",a->item);
        root=a;
        root=root->right;
        }
    }
    preorder(root);
}
else
 preorder(root);
}

struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void insertLeft(struct node* root, int value) {
  root->left = createNode(value);

}

void insertRight(struct node* root, int value) {
  root->right = createNode(value);

}


int main() 
{

  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);

  insertLeft(root->left, 4);
  insertRight(root->left, 5);

  preorder(root);

}