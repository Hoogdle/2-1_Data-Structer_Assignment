#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int node_num;
    struct Node* next;
}Node;

int flag[10];
int activate[10];

Node* Initialize_graph(){
    Node* array;
    array = (Node*)malloc(sizeof(Node)*10);
    for(int i=0;i<10;++i){
        array[i].next = NULL;
        flag[i] = 0;
        activate[i] = 0;
    }
    return array;
}

void Insert_vertex(int num){
    activate[num] = 1;
}

void Insert_edge(int head,int tail,Node *array){
    if(activate[head]==0||activate[tail]==0){
        printf("Node doesn't exit!\n");
        return;
    }

    // 삽입 되는 노드 만들어주기
    Node* data = (Node*)malloc(sizeof(Node));
    data -> node_num = tail;
    data -> next = NULL;

    Node *temp = array[head].next;

    if(temp==NULL){ // 해당 노드에 아직 그래프가 생성되지 않은 경우
        array[head].next = data;
        return;
    }
    else{
        Node* follwer = NULL;
        while(1){
            if(temp && temp->node_num<tail){
                follwer = temp;
                temp = temp->next;
            }
            else{break;}
        } // 삽입 해야하는 위치까지 이동
        
        if(follwer==NULL){ // follower가 이동하지 않은 경우 == 첫 번째 위치에 삽입하는 경우
            array[head].next = data;
            data -> next = temp;
        }
        else{
            follwer->next = data;
            data->next = temp;
        }

    }

}

void Print_graph(Node *array){
    printf("==============Print Graph==============\n");
    Node *ptr = NULL;
    for(int i=0;i<10;++i){
        if(activate[i]==1){
            printf("[%d]'s link : ",i);
            for(ptr=array[i].next;ptr;ptr=ptr->next){
                printf(" -> [%d] ",ptr->node_num);
            }
            printf("\n");
        }
        else{continue;}
    }
}

void Breath_First_Search(Node* array,int key){

}

int main(){
    Node* head;
    char command;
    while(1){
        printf("============================================\n");
        printf("                 Graph Search               \n");
        printf("============================================\n");
        printf("Initialize Graph   : z\n");
        printf("Insert Vertex      : v\t Insert Edge         : e\n");
        printf("Depth First Search : d\t Breath First Search : b\n");
        printf("Print Graph        : p\t Quit                : q\n");
        
        printf("Command : ");
        scanf(" %c", &command);
        if(command=='z'){
            head = Initialize_graph();
            continue;
        }
        if(command=='v'){
            int num;
            printf("Vertex num : ");
            scanf("%d",&num);
            Insert_vertex(num);
            continue;
        }
        if(command=='e'){
            int p1,p2;
            printf("Head and Tail : ");
            scanf("%d %d",&p1,&p2);
            Insert_edge(p1,p2,head);
            Insert_edge(p2,p1,head);
            continue;
        }
        if(command=='d'){
            continue;
        }
        if(command=='b'){
            continue;
        }
        if(command=='p'){
            Print_graph(head);
            continue;
        }
        if(command=='q'){
            return 0;
        }
    }
}

// void Depth_First_Search(Node* array,int key){
//     Node* ptr = &array[key];
//     flag[key] = 1;
//     printf("data : %5d\n",key);
    
//     ptr = ptr->next;
//     while(1){
//         if(flag[ptr->node_num]==0){
//             flag[ptr->node_num]=1;
//             printf("data : %5d\n",ptr->node_num);
//             ptr = &array[ptr->node_num];
//             ptr = ptr->next;
//         }
//         else{
//             ptr = ptr->next;
//             if(ptr==NULL){
//                 return;
//             }
//         }
//     }
// }
