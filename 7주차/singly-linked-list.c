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

void insertNode(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    if(!node){ // node가 비어있는 경우
        node = temp;
        return;
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

int main(){
    Node* Head;
    Head = (Node*)malloc(sizeof(Node));
}