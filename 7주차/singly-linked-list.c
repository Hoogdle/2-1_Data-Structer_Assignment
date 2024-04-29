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
        free(temp);
        free(mover);
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
    free(temp);
    free(mover);
    
}

int insertFirst(Node ** node,int data){
    Node* temp;
    Node* messenger;
    temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;
    messenger = (*node)->next;
    (*node)->next = temp;
    temp ->next = messenger;
    free(temp);
    free(messenger);
}

int insertLast(Node ** node,int data){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));

    Node* mover = *node;
    while(mover->next != NULL){
        mover = mover->next;
    }
    mover->next = temp;
    temp->next = NULL;
    free(temp);
    free(mover);
}

int inverList(Node ** node){
    Node* b_head;
    Node* s_head;

    b_head = (*node);
    s_head = NULL;

    s_head = b_head;
    b_head = b_head->next;
    s_head -> next = NULL;
    *node = b_head;
    (*node)->next = s_head;

    while(b_head->next != NULL){
        s_head = b_head;
        b_head = b_head->next;
        
        *node = b_head;
        (*node)->next = s_head;
    }
    free(b_head);
    free(s_head);
    return 0;
}

void deleteNode(Node **node,int data){

    Node* mover = *node;
    Node* b_mover = NULL;

   
    while(mover->next != NULL && mover->data != data){ // mover 움직이기
        b_mover = mover;
        mover = mover->next;
    }
    if(mover->next != NULL){ // 마지막인경우
        if(mover->data != data){
            free(mover);
            free (b_mover);
            return;
        }
    }
    else{ // 마지막이 아닌 경우, 찾는 data를 찾은 경우
        b_mover->next = mover->next;
        mover -> next = NULL;
        free(mover);
        free (b_mover);
    }
}

void deleteLast(Node **node){
    Node* mover = *node;
    Node* b_mover = NULL;
    while(mover->next != NULL){
        b_mover = mover;
        mover = mover->next;
    }
    b_mover->next = NULL;
    free(mover);
    free(b_mover);
}

void deleteFirst(Node **node){
    Node *temp = (*node);
    (*node) = (*node)->next;
    temp->next = NULL;

    free(temp);
}


void Print(Node *node){
    int count = 0;
    while(node != NULL){
        printf("[ [%d] = %d ]\n",count,node->data);
        ++count;
        node = node->next;
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
        scanf("%c",&c);

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
            inverList(&Head);
            continue;
        }
        else if(c=='P'){
            
        }
    }while(c != 'q');
 
}