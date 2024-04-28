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

    Node* mover = *node;

    if(!(*node)){ // node가 비어있는 경우
        *node = temp;
        return 0;
    }
    while(mover->next != NULL && mover->data < data){
        mover = mover->next;
    }
    if(mover->next != NULL){ // 마지막인경우
        mover->next = temp;
        temp->next = NULL;
    }
    else{ // 중간인경우
        Node* messenger;
        messenger = mover->next;
        mover->next = temp;
        temp->next = messenger;
    }
    
}

int insertFirst(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    (*node) = temp;
}

int insertLast(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));

    Node* mover = *node;
    while(mover->next != NULL){
        mover = mover->next;
    }
    mover->next = temp;
}

int inverList(Node ** node){
    Node* b_head;
    Node* s_head;

    b_head = (*node);
    s_head = NULL;

    s_head = b_head;
    s_head -> next = NULL;
    b_head = b_head->next;
    *node = b_head;
    (*node)->next = s_head;

    while(b_head->next != NULL){
        s_head = b_head;
        b_head = b_head->next;
        
        *node = b_head;
        (*node)->next = s_head;
    }
    return 0;
}

void deleteNode(Node **node,int data){
    Node* mover = *node;
    Node* b_mover = NULL;

    if(!(*node)){ // node가 비어있는 경우
        *node = temp;
        return 0;
    }
    while(mover->next != NULL && mover->data != data){
        b_mover = mover;
        mover = mover->next;
    }
    if(mover->next != NULL){ // 마지막인경우
        return;
    }
    else{
        
    }
}

void deleteLast(Node **node,int data){

}

void deleteFirst(Node **node,int data){

}


void Print(Node *node){

}


int main(){
    Node* Head;
    Head = (Node*)malloc(sizeof(Node));
}