#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int data;
    Tree *left;
    Tree *right;
}Tree;

// Non-Recursive LVR를 위한 Stack(간단히) 생성
int top = -1;
Tree* Stack[100];
////////////////////////////////////////////////////////////////

void push(Tree* ptr){
    Stack[++top] = ptr;
}

Tree* pop(){
    if(top==-1){
        return NULL;
    }
    return Stack[top--];
}


void Non_Recursive_LVR(Tree *ptr){
    if(!ptr){
        printf("Tree is Empty!\n");
        return;
    }
    Tree *temp = ptr;
    while(1){
        for(;temp;temp=temp->left){
            push(temp);
        }

        temp = pop();
        if(!temp){break;}
        printf("Tree's data : %d\n",temp->data);
        temp = temp->right;
    }
    
}

int main(){
        //////////////// 바이너리 Tree 생성 ////////////////
    Tree *root = (Tree*)malloc(sizeof(Tree));
    root->data = 10;
    Tree *l_temp = (Tree*)malloc(sizeof(Tree));
    Tree *r_temp = (Tree*)malloc(sizeof(Tree));
    l_temp->data = 5;
    l_temp->left = NULL;
    l_temp->right = NULL;

    r_temp->data = 15;
    r_temp->left = NULL;
    r_temp->right = NULL;

    root->left = l_temp;
    root->right = r_temp;

    printf("root's data : %d\n",root->data);
    printf("root's left data : %d\n",root->left->data);
    printf("root's right data : %d\n",root->right->data);
    ////////////////////////////////////////////////////////////////
    Non_Recursive_LVR(root);

}