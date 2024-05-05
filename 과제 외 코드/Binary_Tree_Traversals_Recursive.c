#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int data;
    Tree *left;
    Tree *right;
}Tree;



void LVR_Travel(Tree *ptr){
    if(ptr){
        LVR_Travel(ptr->left);
        printf("Data : %d\n",ptr->data);
        LVR_Travel(ptr->right);
    }
}

void VLR_Travel(Tree *ptr){
    if(ptr){
        printf("Data : %d\n",ptr->data);
        VLR_Travel(ptr->left);
        VLR_Travel(ptr->right);
    }
}

void LRV_Travel(Tree *ptr){
    if(ptr){
        LRV_Travel(ptr->left);
        LRV_Travel(ptr->right);
        printf("Data : %d\n",ptr->data);
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
    
    printf("Print Result of LRV =>\n");
    LVR_Travel(root);
    printf("\n");

    printf("Print Result of VLR =>\n");
    VLR_Travel(root);
    printf("\n");

    printf("Print Result of LRV =>\n");
    LRV_Travel(root);
    printf("\n");
}