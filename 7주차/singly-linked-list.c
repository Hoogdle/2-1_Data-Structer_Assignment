#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initialize(){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    return temp;
}

int insertNode(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    if(!node){ // node가 비어있는 경우
        node = temp;
        return 0;
    }
    while((*node)->next != NULL && (*node)->data < data){
        (*node) = (*node)->next;
    }
    if((*node)->next != NULL){ // 마지막인경우
        (*node)->next = temp;
        temp = NULL;
    }
    else{ // 중간인경우
        Node* messenger;
        messenger = (*node)->next;
        (*node)->next = temp;
        temp->next = messenger;
    }
    
}

int insertFirst(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    (*node) = temp;
}

int insertLast

int main(){
    Node* Head;
    Head = (Node*)malloc(sizeof(Node));
}