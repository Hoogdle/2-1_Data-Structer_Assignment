#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int data;
    Tree *left;
    Tree *right;
}Tree;


int rear = -1;
int front = -1;
Tree* queue[100];

void Enqueue(Tree *ptr){
    queue[++rear] = ptr;
}

Tree* Dequeue(){
    if(rear==front){return NULL;}
    return queue[++front];
}

void Level_order_Traversal(Tree *ptr){

    Enqueue(ptr);
    while(1){
        Tree* value = Dequeue();
        if(value==NULL){break;}
        printf("Result of Traversal : %d\n",value->data);
        if(value->left){Enqueue(value->left);}
        if(value->right){Enqueue(value->right);}
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

    Tree *ll_temp = (Tree*)malloc(sizeof(Tree));
    Tree *lr_temp = (Tree*)malloc(sizeof(Tree));
    Tree *rl_temp = (Tree*)malloc(sizeof(Tree));
    Tree *rr_temp = (Tree*)malloc(sizeof(Tree));

    l_temp -> left = ll_temp;
    l_temp -> right = lr_temp;
    r_temp -> left = rl_temp;
    r_temp -> right = rr_temp;

    ll_temp->data = 1;
    lr_temp->data = 2;
    rl_temp->data = 3;
    rr_temp->data = 4;

    ll_temp->left = NULL;
    ll_temp->right = NULL;
    lr_temp->left = NULL;
    lr_temp->right = NULL;
    rl_temp->left = NULL;
    rl_temp->right = NULL;
    rr_temp->left = NULL;
    rr_temp->right = NULL;

   

    printf("root's data : %d\n",root->data);
    printf("root's left data : %d\n",root->left->data);
    printf("root's right data : %d\n",root->right->data);
    ////////////////////////////////////////////////////////////////
    Level_order_Traversal(root);
}