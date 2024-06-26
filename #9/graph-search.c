// 자료구조 #9 과제
// 이름 : 김태영
// 학과 : 소프트웨어학부
// 학번 : 2023041012

#include <stdio.h>
#include <stdlib.h>

// 인접 리스트의 기본 형식을 아래와 같이 만들었습니다
// '노드 번호'와 다음 노드를 가리키는 '포인터'를 가지는 구조체입니다.
typedef struct Node{
    int node_num; // 노드번호
    struct Node* next; // 다음 노드의 포인터
}Node;

int flag[10]; // 탐색을 할 때, 이미 탐색한 노드를 표시할 flag입니다.(이미 탐색한 노드가 다시 탐색하는 것을 막아줍니다.)
int activate[10]; // Vertex 삽입에서 사용할 배열입니다. InserVertex를 하면 해당 노드의 해당하는 activate의 값이 1로 변경되며
                    // activate의 값이 1인 노드의 한해서 InsertEdge를 허용해줍니다.

// DFS를 위한 스택

// DFS를 Iterative방식으로 구현하기 위해서는 스택이 필요합니다. 스택을 아래와 같이 정의했습니다.
// stack의 크기는 과제 메뉴얼에서 노드의 갯수를 10개로 제한했기에 크기를 10으로 지정했습니다.
// stack에는 node의 번호가 들어갑니다.
int stack[10]; 
int top = -1; // top이 항상 node_num을 가리킬 수 있게 초기 값을 -1로 설정했습니다.

// 스택에는 push와 pop의 기능이 존재하며 각각 top을 기준으로 데이터를 넣고 빼내는 기능입니다.

// push 함수 : top이 가리키는 위치에 데이터를 집어 넣습니다.
void push(int node){
    stack[++top] = node; // top은 항상 최근의 데이터를 가리키므로 ++로 인덱스 업을 한 후 값을 넣어줍니다.
}

int pop(){
    return stack[top--]; // top이 가리키는 아이템을 리턴한 후, top의 인덱스 값을 하나 줄여줍니다.
}

// BFS를 위한 큐

// BFS를 Iteratvie 방식으로 구현하려면 queue가 필요하기 때문에 queue를 아래와 같이 정의했습니다.
// 노드가 최대 10개이기 때문에 queue의 크기를 10으로 설정하였으며 front는 항상 아이템을 가리키도록 rear는 
// 아이템을 가리키지 않도록 구현했습니다.
// (rear은 이동 후 삭제하기때문에 rear가 가리키는 인덱스는 항상 데이터가 비어있습니다.)
int queue[10];
// front와 rear의 초기 인덱스를 각각 -1로 설정
int front = -1;
int rear = -1;

// queue에는 enqueue와 dequeue 2가지 기능이 있습니다. enqueue는 데이터가 들어오면 rear가 하나씩 증가하며
// rear의 위치에 데이터가 들어오고 dequeue를 하면 front가 하나씩 증가하며 front 위치의 데이터가 반환되는 구조입니다.

void enqueue(int node){
    queue[++rear] = node; // rear가 하나씩 증가하며 데이터가 들어온다
}
int dequeue(){
    return queue[++front]; // front가 하나씩 증가하며 front 위치의 데이터가 반환된다.
}


// graph 초기 설정을 위한 함수입니다.
// 인접리스트의 주소를 반환해주며 flag와 acitivate(활성화 노드)의 모든 값을 0으로 설정해줍니다.
// 또한 인접리스트의 원소들의 next를 NULL로 초기화 해줍니다.
// 인접리스트는 구조체 배열로 동적할당하였으며 크기는 노드 최대 크기인 10으로 설정하였습니다.
Node* Initialize_graph(){
    Node* array; // 인접리스트 배열을 가리키는 포인터
    array = (Node*)malloc(sizeof(Node)*10); // 인접리스트를 노드의 최대 갯수 10개 만큼 동적메모리 할당
    for(int i=0;i<10;++i){ // graph 초기 설정
        array[i].next = NULL; // 인접 리스트 모든 원소들의 next 값을 NULL로 설정
        flag[i] = 0; // flag를 모두 0으로 초기화
        activate[i] = 0; // 아직 활성화 노드가 없으므로 모두 0으로 초기화
    }
    return array; // 인접리스트 배열의 주소를 리턴
}

// 노드를 삽입하는 함수
// 노드를 삽입하는 함수는 매개변수로 받은 num에 해당하는 인접리스트의 노드를 활성화하는데
// 활성화의 표시를 activate배열의 num번째 원소를 1로 변경하여 해당 노드가 삽입되었음을 표시하였습니다.
void Insert_vertex(int num){
    activate[num] = 1;
}


// edge를 삽입하는 함수
// 매개변수로 두 노드(head,tail)을 받으며, 이를 해당하는 인접리스트의 요소들에 적용해야 하므로
// 인접리스트의 주소를 받습니다.
void Insert_edge(int head,int tail,Node *array){
    if(activate[head]==0||activate[tail]==0){ // 매개변수로 받은 두 노드중 하나라도 존재하지 않는다면
                                                // edge를 만들 수 없으므로 경고문 이후 함수를 종료
        printf("Node doesn't exit!\n");
        return;
    }
    // simple graph를 기준으로 하므로 간선이 중첩됬는지 검사
    // head를 기준으로 하여 array[head]에 연결된 모든 노드들을 검사합니다.
    // 검사시 tail에 해당하는 노드(동일한 node_num)일 발견되면 해당 edge가 이미 존재하는 것이므로
    // 경고문 이후 함수를 종료합니다.
    for(Node *ptr = array[head].next;ptr;ptr=ptr->next){ // for문을 활용해 head 인덱스에 연결된 모든 노드 확인
        if(ptr->node_num==tail){
            printf("Edge Already Exist!\n");
            return;
        }
    }

    // 삽입 되는 노드 만들어주기

    // 동적할당을 받고 삽입되는 노드의 번호와 해당 노드의 next를 일단 NULL로 초기화 합니다.
    // 이 함수의 파라미터의 head는 인접리스트의 인덱스 번호를 뜻하며 
    // tail은 인접리스트 인덱스에 연결 될 노드를 뜻합니다.
    Node* data = (Node*)malloc(sizeof(Node));
    data -> node_num = tail;
    data -> next = NULL;

    // 삽입 될 위치를 탐색할 때 사용될 포인터 변수 temp를 선언한 후 인접리스트에 인덱스의
    // next(해당 인덱스 가리키는 첫 번재 노드의 주소)를 temp에 넣어줍니다.
    Node *temp = array[head].next;

    // 해당 인접 리스트에 어떠한 노드도 존재하지 않는 다면 별도의 비교없이 새로운 노드를 바로 연결시켜 주면 됩니다.
    if(temp==NULL){ // 해당 노드에 아직 그래프가 생성되지 않은 경우
        array[head].next = data;
        return;
    }

    // 해당 인접 리스트에 어떠한 노드가 존재하는 경우 해당 노드의 node_num을 고려하여 삽입될 위치를 찾아줘야 합니다.
    // 이때 temp 직전 위치를 가리킬 포인터 follwer가 필요합니다. 
    // (반복문의 종료 조건이 temp가 NULL인 경우가 존재하는데 temp가 NULL이 되어 빠져나오면 삽입이 불가합니다.)
    else{
        Node* follwer = NULL; // temp 직전 노드를 가리킬 포인터 변수 follwer
        while(1){
            if(temp && temp->node_num<tail){ // temp가 NULL이거나 node_num>tail(삽입될 위치를 찾은 경우)이 아닌이상
            // 아니라면 계속해서 follwer와 temp를 다음 노드로 이동 시킵니다.
                follwer = temp;
                temp = temp->next;
            }
            else{break;}
        } // 삽입 해야하는 위치까지 이동
        
        // 위의 반복문을 빠져나왔다면 follwer의 다음 노드가 새로운 데이터가 들어가야할 위치가 됩니다.
        // 이때 follower가 NULL인 경우는 follower가 아예 움직이지 않은 경우, 즉 첫 번째 노드에 삽입되야 하는
        // 경우가 됩니다. 이 경우만 별도로 if문을 통해 검사해줍니다.
        if(follwer==NULL){ // follower가 이동하지 않은 경우 == 첫 번째 위치에 삽입하는 경우
            array[head].next = data; // 인접리스트의 해당 인덱스가 새로운 데이터를 가리키게한다.
            data -> next = temp; // 현재의 temp는 원래 인접리스트가 가리키고 있던 노드의 주소이므로
                                    // 새로운 데이터 노드가 temp를 가리키게 한다.
        }
        // follwer가 NULL이 아니라면 어떤 움직임 있었다는 것이며, 첫 번째 위치에 삽입되는 경우는 아니라는 것을
        // 의미합니다.
        else{
            // follower 다음에 새로운 데이터를, 새로운 데이터 다음을 원래 follower가 기리키던 노드를 가리키게 합니다.
            follwer->next = data;
            data->next = temp;
        }

    }

}

// graph를 출력하는 함수
// 출력 형태는 인접리스트를 출력하도록 했습니다.
void Print_graph(Node *array){
    printf("==============Print Graph==============\n");
    Node *ptr = NULL; // 출력시 사용할 포인터, 포인터를 움직이며 포인터가 가리키는 값들을 출력할 것입니다.
    // 인접리스트 각각의 인덱스마다 for문을 걸어 해당 인덱스가 가리키는 모든 노드들의 값을 출력합니다.
    for(int i=0;i<10;++i){ // 인접리스트를 돌기 위한 for문
        if(activate[i]==1){ // 인접리스트 인덱스(vertex)가 활성화 되지 않았으면 출력 pass
            printf("[%d]'s link : ",i); // 인접리스트의 인덱스 번호 출력
            for(ptr=array[i].next;ptr;ptr=ptr->next){ // 인접리스트의 어떤 인덱스에서 해당 인덱스와 연결된 모든
                                                        // 노드들을 출력하기 위한 for문
                printf(" -> [%d] ",ptr->node_num); // 연결된 노드의 node_num 출력
            }
            printf("\n");
        }
        else{continue;}
    }
}

// DFS (깊이 우선 탐색)
// 인접리스트의 주소와 탐색을 시작할 key(node_num)를 매개변수로 받습니다.
// 초기 node_num을 스택에 넣어줍니다. 스택에 존재하는 노드가 flag가 비활성화된 어떤 노드와 연결되어 있다면
// 해당 node의 flag를 활성화하고 스택에 넣어줍니다.(stack에 들어가는 모든 노드들을 push전에 print를 해줍니다.)
// 위 과정을 반복하다가 더 이상 flag가 비활성화된 노드 중 push할 노드가 존재하지 않는다면 pop해줍니다.
// pop한 후 top이 가리키는 노드를 기준으로 위의 과정을 반복해줍니다.(stack이 빌 때 까지 반복)
void Depth_First_Search(Node* array,int key){
    flag[key] = 1; // 입력 받은 시작 node_num의 flag를 활성화
    push(key); // 스택에 시작 node_num을 넣어줍니다.
    printf(" [%d] -> ",stack[top]); // 시작 node_num의 값을 출력하빈다.
    Node *ptr = array[key].next; // 탐색을 돕는 포인터를 선언 후 시작 인접리스트에서 시작 node_num 인덱스 요소가
                                        // 가리키는 첫 번째 노드의 주소로 포인터를 초기화 합니다.
    while(1){
        if(ptr==NULL){ // ptr이 NULL이라는 의미는 인접리스트의 어떤 인덱스와 연결된 모든 노드 중 어떠한 노드도
                            // 스택에 푸쉬할 노드가 없다는 것을 의미합니다. 즉, 더 이상 해당 노드와 연결된 노드 중
                             // 스택에 푸쉬할 노드가 없으므로 pop을 진행합니다.
            pop();
            if(top==-1){ // pop 이후 top == -1 (== 스택이 빔)이라면 탐색이 끝난 것을 의미하므로
                            // flag를 모두 0으로 초기화(다음의 탐색을 위해)한 후 함수를 종료합니다.
                printf("[end]\n");
                for(int i=0;i<10;++i){ // flag 초기화 부분
                    flag[i] = 0;
                }
                return;
            }
            // pop 이후에도 아직 스택에 원소가 남아있다면 스택의 top이 가리키는 값을 인접리스트의 인덱스로 하여
            // 해당 인덱스와 연결된 노드 중 flag가 비활성화 된 노드가 있는지 확인해야 합니다.
            // 따라서 ptr값을 top이 가리키는 값을 인접리스트의 인덱스로 한 next의 주소로 초기화 합니다.
            ptr = array[stack[top]].next;
        }

        // flag가 비활성화 된 노드가 존재한다면 해당 노드의 flag를 활성화 시키고 스택에 push 해줍니다.
        if(flag[ptr->node_num]==0){ // flag가 비활성화 되어 있다면
            flag[ptr->node_num]=1; // flag를 활성화하고
            push(ptr->node_num); // 스택에 넣어준다.
            printf(" [%d] -> ",stack[top]); // 넣은 값을 출력해준다.
            ptr = array[ptr->node_num].next; // ptr의 값은 ptr이 가리키던 값을 인덱스로 하여 인접리스트의 인덱스의
                                                // next값으로 업데이트 합니다.
        }
        else{
            ptr = ptr->next; // flag가 이미 활성화가 된 경우라면 다음 노드로 이동합니다.
        }
    }
}


// BFS(너비 우선 탐색)
// 시작 node_num을 먼저 enqeue 한 후 deqeue 해줍니다. 
// 위 과정 속에 일정한 규칙이 존재하는데, dequeue를 할 때는 dequeue를 하는 노드와 연결된 노드중 flag가 비활성인 노드는
// 모두 enqueue를 해줘야 합니다. 위 과정을 큐가 빌 때(front==rear) 까지 반복합니다.

// 함수의 매개변수로 인접리스트의 주소와 시작 key를 받습니다.
void Breath_First_Search(Node* array,int key){
    enqueue(key); // key(node_num)을 enqueue 합니다.
    key = dequeue(); // key에 dequeue값을 담습니다.
    printf(" [%d] -> ",key); // dequeue값을 출력합니다.
    flag[key] = 1; // dequeue한 값의 flag를 활성화 시킵니다.
    // 위 과정에서 key의 enqueue과정과 dequeue 과정은 아무런 의미가 없지만 규칙성을 일반화하기 위해 작성해봤습니다.
    while(1){
        for(Node* ptr = array[key].next;ptr;ptr=ptr->next){ // for문을 돌려 flag가 비활성화된 모든 node를
                                                                // 추가합니다.
            if(flag[ptr->node_num]==0){ // flag가 비활성이라면
                flag[ptr->node_num]=1; // flag를 활성화 시키고
                enqueue(ptr->node_num); // 해당 노드를 추가해줍니다.
            }
        }
        // 위 과정을 거치게 되면 최근 dequeue한 node와 인접한 노드중 flag가 비활성화인 모든 노드가
        //  queue에 들어가게 됩니다.

        if(front==rear){break;} 
        key = dequeue(); // key값을 dequeue값으로 업데이트 해줍니다.
        // 이렇게 key 값을 업데이트 하여 반복문을 돌려주면 해당 key 값을 기준으로 연결된(flag가 비활성화된)노드가
        // enqueue되고 dequeue됨을 반복하여 BFS가 구현되게 됩니다.
        printf(" [%d] -> ",key);
        // deqeue된 값을 출력해줍니다.
    }
    printf("[end]\n");
    // BFS가 끝났으면 다음 번의 탐색을 위해 flag 값을 모두 0으로 초기화해줍니다.
    for(int i=0;i<10;++i){
         flag[i] = 0;
    }
}

int main(){
    Node* head; // 인접리스트의 주소를 담는 head 포인터 
    char command; // 명령어를 담는 command
    // main문에는 메뉴얼을 작성하였습니다. 각 command 마다 해당 함수가 실행되게 작성하였습니다.
    while(1){
        printf("============================================\n");
        printf("                 Graph Search               \n");
        printf("============================================\n");
        printf("Initialize Graph   : z\n");
        printf("Insert Vertex      : v\t Insert Edge         : e\n");
        printf("Depth First Search : d\t Breath First Search : b\n");
        printf("Print Graph        : p\t Quit                : q\n");
        
        printf("Command : ");
        scanf(" %c", &command); // 명령어를 입력받음
        if(command=='z'){ // z는 그래프 초기화
            head = Initialize_graph();
            continue;
        }
        if(command=='v'){ // v는 노드 번호를 입력받아 해당 노드를 추가
            int num;
            printf("Vertex num : ");
            scanf("%d",&num);
            Insert_vertex(num);
            continue;
        }
        if(command=='e'){ // e는 edge 쌍을 입력받아 해당 edge 추가
            int p1,p2;
            printf("Head and Tail : ");
            scanf("%d %d",&p1,&p2);
            Insert_edge(p1,p2,head);
            Insert_edge(p2,p1,head);
            continue;
        }
        if(command=='d'){ // d는 시작지점을 입력받아 DFS 실행
            int key;
            printf("Starting Point : ");
            scanf("%d",&key);
            Depth_First_Search(head,key);
            continue;
        }
        if(command=='b'){ // b는 시작지점을 입력받아 BFS 실행
            int key;
            printf("Starting Point : ");
            scanf("%d",&key);
            Breath_First_Search(head,key);
            continue;
            continue;
        }
        if(command=='p'){ // p는 그래프를 인접리스트 형태로 출력
            Print_graph(head);
            continue;
        }
        if(command=='q'){ // q는 프로그램 종료
            return 0;
        }
    }
}

// 심심해서 non stack, non recursive으로 구현해봤습니다!
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
