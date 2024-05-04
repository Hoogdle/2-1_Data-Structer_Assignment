#include <stdio.h>
#define MAX 100

// 2024-05-04(토)
// 초기 top 이 -1이 되도록 구현 == top이 항상 data를 가리키도록 구현
// 대충 간단하게 만든 스택

int array[MAX];
int top = -1;

int isEmpty(){
    if(top==-1){return 1;}
    return 0;
}

int isFull(){
    if(top==MAX-1){return 1;}
    return 0;
}

void push(int data){
    if(isFull()==0){array[++top] = data;}
    else{printf("Stack is Full!\n");}
}

int pop(){
    if(isEmpty()==0){return array[top--];}
    else{printf("Stack is Empty!");}
}

void manual(){
    char c;
    while(1){
        printf("Command : ");
        scanf("%c",&c);
        if(c=='e'){
            int data;
            printf("Input data : ");
            scanf(" %d",&data);
            push(data);
        }
        else if(c=='d'){
            int data;
            data = pop();
            printf("Popped data : %d\n",data);
        }
        else if(c=='q'){
            printf("Exit the program");
            return;
        }

    }
}


int main(){
    manual();
}