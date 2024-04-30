#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initialize(){
    Node* temp;
    temp = NULL;
    return temp;
}

int insertNode(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    temp -> next = NULL;

    Node* mover = *node;
    Node* tail = NULL;

    if(!(*node)){ // node가 비어있는 경우
        *node = temp;
        return 0;
    }

    while(mover->next != NULL && mover->data < data){
        tail = mover;
        mover = mover->next;
    }
    if(mover->data >= data){
        if(tail==NULL){ // 첫 번째에 삽입
            tail = (*node);
            (*node) = temp;
            temp->next = tail;
        }
        else{ // 중간에 삽입
            tail->next = temp;
            temp->next = mover;
        }
    }
    else if(mover->next == NULL){ // 마지막인경우
        mover->next = temp;
    }
}

int insertFirst(Node ** node,int data){

    
    Node* temp;
    Node* messenger;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    temp -> next = NULL;

    if(!(*node)){ // node가 비어있는 경우
        *node = temp;
        return 0;
    }


    messenger = (*node);
    (*node) = temp;
    temp ->next = messenger;
}

int insertLast(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = data;

    Node* mover = *node;
    while(mover->next != NULL){
        mover = mover->next;
    }
    mover->next = temp;
    temp->next = NULL;
}

int invertList(Node ** node){
    Node* b_head;
    Node* s_head;
    Node* temp;

    s_head = *node;
    b_head = (*node)->next;
    if(s_head==NULL || b_head==NULL){
        printf("Cannot Reverse!\n");
        return 0;
    }
    temp = b_head->next;

    s_head -> next = NULL;
    b_head->next = s_head;

    while(1){
        s_head = b_head;
        b_head = temp;
        if(!(b_head)){
            break;
        }
        temp = temp->next;
        
        b_head->next = s_head;
    }
    *node = s_head;

    return 0;
}

void deleteNode(Node **node,int data){

    Node* mover = *node;
    Node* b_mover = NULL;

    while(mover->next != NULL && mover->data != data){ // mover 움직이기
        b_mover = mover;
        mover = mover->next;
    }
    if(mover->next == NULL){ // 마지막인경우
        if(mover->data == data){
            b_mover->next = NULL;
            free(mover);
            return;
        }
        else{
            return;
        }
    }
    else{ // 마지막이 아닌 경우, 찾는 data를 찾은 경우
        if(b_mover==NULL){
            mover = (*node)->next;
            free(*node);
            (*node) = mover;
        }
        else{
            b_mover->next = mover->next;
            mover -> next = NULL;
            free(mover);
        }
    }
}

void deleteLast(Node **node){
    Node* mover = *node;
    Node* b_mover = NULL;
    while(mover->next != NULL){
        b_mover = mover;
        mover = mover->next;
    }
    mover->next = NULL;
    free(mover);
    b_mover->next = NULL;
}

void deleteFirst(Node **node){
    Node *temp = (*node);
    (*node) = (*node)->next;
    temp->next = NULL;

    free(temp);
}


void Print(Node *node){
    int count = 0;

    if(!(node)){
        printf("No Data!\n");
        return;
    }
    while(1){
        printf("[ [%d] = %d ]\n",count,node->data);
        ++count;
        node = node->next;
        if(node==NULL){
            return;
        }
    }
}




int main(){
    Node* Head;
    char c;
    do{
        printf("        Please Input Command        \n");
        printf("====================================\n");
        printf("I : Initialize      P : Print\n");
        printf("i : Insert Node     d : Delete Node\n");
        printf("l : Insert Last     e : Delete Last\n");
        printf("f : Insert First    x : Delete First\n");
        printf("r : Invert List     q : Quit\n");
        printf("====================================\n");
        printf("Command : ");
        scanf(" %c",&c);

        if(c=='I'){
            Head = initialize();
            continue;
        }
        else if(c=='i'){
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertNode(&Head,data);
            continue;
        }
        else if(c=='l'){
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertLast(&Head,data);
            continue;
        }
        else if(c=='f'){
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertFirst(&Head,data);
            continue;
        }
        else if(c=='r'){
            invertList(&Head);
            continue;
        }
        else if(c=='P'){
            Print(Head);
            continue;
        }
        else if(c=='d'){
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            deleteNode(&Head,data);
            continue;
        }
        else if(c=='e'){
            deleteLast(&Head);
            continue;
        }
        else if(c=='x'){
            deleteFirst(&Head);
            continue;
        }
        else if(c=='q'){
            printf("프로그램을 종료합니다.");
            return 0;
        }
    }while(1);
 
}