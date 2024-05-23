#include <stdio.h>
#include <stdlib.h>


// 강의노트의 내용을 기반으로 singly-linked-list.c를 직접 구현하였습니다.
// 보고서에서 요구하는 함수 외에 참고 자료로 올려주신 영상에 언급된 함수도 추가적으로 구현하였습니다.
// insertNode에서 데이터 삽입 규칙은 올려주신 영상 처럼 데이터가 오름차순으로 정렬될 수 있게 삽입하였습니다.

// 이름 : 김태영
// 학과 : 소프트웨어학부
// 학번 : 2023041012


typedef struct Node{
    int data; // 데이터를 저장하는 정수형 변수 'data'
    struct Node* next; // 다음 노드의 주소를 저장하는 Node 구조체 포인터 변수 next
}Node; // struct Node를 'Node'로 정의


// Node의 주소를 리턴하는 초기설정 함수 initialize
Node* initialize(){  
    Node* temp; // Node 포인터 변수 temp 선언
    temp = NULL; // temp의 주소값을 NULL로 초기화
    return temp; // temp를 리턴한다.
}

// Node를 삽입하는 함수, 매개변수로 Node 포인터 변수의 주소와 정수 data를 받는다.
int insertNode(Node ** node,int data){
    Node* temp; // Node 포인터 변수 temp 선언
    temp = (Node*)malloc(sizeof(Node)); // temp를 Node의 사이즈만큼 동적할당 한다.
    temp -> data = data; // temp의 data를 함수로 입력받은 data로 초기화
    temp -> next = NULL; // temp의 다음 주소를 일단 NULL로 초기화

    Node* mover = *node; // 삽입에 도움을 줄 Node 포인터 변수 mover를 node가 가리키는 주소로 초기화
    Node* tail = NULL; // 삽입에 도움을 줄 Node 포인터 변수 tail을 일단 NULL로 초기화

    if(!(*node)){ // node가 비어있는 경우
        *node = temp; // list에 아무런 데이터가 없는 경우이므로 node에 바로 temp의 주소를 넣어준다.
        return 0; // 함수 종료
    }

    // node가 비어있지 않은 경우
    // mover의 다음 주소가 NULL이 아니면서 mover->data가 data가 아닐 때 까지 반복문 반복
    while(mover->next != NULL && mover->data < data){
        // tail과 mover을 반복문의 조건이 깨질 때 까지 한 칸 앞으로 계속 이동시킨다.
        // tail은 mover바로 뒤의 list를 가리키도록 한다.
        tail = mover; 
        mover = mover->next;
    }

    // tail과 mover의 이동이 끝난 경우 

    // mover->data가 data 보다 크거나 같은 경우(오름차순이 깨지는 경우)
    if(mover->data >= data){
        if(tail==NULL){ // tail이 NULL이라면 tail과 mover가 한 번도 움직이지 않았다는 의미, 즉 data가 리스트 첫 번째 데이터보다 작은 경우이다.
            tail = (*node); // tail이 node가 가리키는 리스트를 가리키도록 한다.
            (*node) = temp; // node는 temp를 가리키도록한다.
            temp->next = tail; // temp의 다음 주소는 tail, 즉 원래 node가 가리키던 주소를 가리키도록 한다.
            // 첫 번째에 삽입 완료!
        }
        else{ // 중간에 삽입하는 경우
            tail->next = temp; // tail의 다음이 temp를
            temp->next = mover; // temp의 다음이 mover를 가리키도록한다.
            // 이렇게 삽입하면 data가 더 큰 mover가 temp의 오른쪽으로 들어가기 때문에 오름차순 정렬을 지킬 수 있다.
        }
    }
    else if(mover->next == NULL){ // mover가 마지막 노드까지 온 경우
        mover->next = temp; // mover의 다음, 즉 마지막 노드에 temp를 넣어준다.
    }
}

// 데이터를 첫 번째에 삽입하는 함수, 매개변수로 Node 포인터 변수의 주소, 정수형 변수 data를 받는다.
int insertFirst(Node ** node,int data){

    
    Node* temp; // Node 포인터 변수 temp, temp는 새로 삽입할 노드이다.
    Node* messenger; // Node 포인터 변수 messenger, messenger는 삽입을 도와주는 변수이다.
    temp = (Node*)malloc(sizeof(Node)); // temp를 Node의 크기만큼 동적메모리 할당
    temp -> data = data; // temp의 data를 data로 초기화
    temp -> next = NULL; // temp의 다음 주소를 NULL로 초기화

    if(!(*node)){ // node가 비어있는 경우
        *node = temp; // list에 아무런 데이터가 없는 경우이므로 node에 바로 temp의 주소를 넣어준다.
        return 0; // 함수 종료
    }


    messenger = (*node); // messenger에 node가 가리키는 주소를 넣어준다.
    (*node) = temp; // node는 이제 temp를 가리키도록 한다.(temp가 첫 번째에 삽입되는 것과 일치)
    temp ->next = messenger; // temp의 다음 주소를 원래 node가 가리키던 주소(messenger의 값)로 초기화 해준다.
    // 이로써 제일 첫 번째 구간에 데이터가 삽입된다.
}

// 마지막에 삽입하는 함수, 매개변수로 Node 포인터 변수의 주소, 정수형 변수 data를 받는다.
int insertLast(Node ** node,int data){
    Node* temp; // Node 포인터 변수 temp, temp는 새로 삽입할 노드이다.
    temp = (Node*)malloc(sizeof(Node)); // temp를 Node의 크기만큼 동적메모리 할당
    temp->data = data; // temp의 data를 data로 초기화

    Node* mover = *node; // 마지막 노드 까지 이동할 Node 포인터 변수 mover를 선언 후 node가 가리키는 주소의 값으로 초기화
    while(mover->next != NULL){ // mover가 linked list의 마지막 노드로 갈 때까지
        mover = mover->next; // mover를 한 칸씩 앞으로 이동시킨다.
    }
    mover->next = temp; // mover의 다음 주소를 temp로 선언
    temp->next = NULL; // temp의 다음 주소를 NULL로 초기화 한다.
}

// linked list를 역순으로 하는 함수, 매개변수로 Node 포인터 변수의 주소를 받는다.
int invertList(Node ** node){
    // 역순으로 만드는 것을 도와주는 Node 포인터 변수 b_head,s_head,temp를 선언
    Node* b_head;
    Node* s_head;
    Node* temp;

    s_head = *node; // s_head를 node가 가리키는 주소로 초기화
    b_head = (*node)->next; // b_head를 node가 가리키는 주소가 가리키는 다음 주소로 초기화
    if(s_head==NULL || b_head==NULL){ // 만일 node가 가리키는 주소가 없거나 b_head가 NULL(노드가 1개인 경우) 역순으로 정렬하지 못하므로 예외 처리
        printf("Cannot Reverse!\n");
        return 0;
    }

    temp = b_head->next; // temp를 b_haed->next 즉, 3번째 노드를 가리키도록 한다.

    // 이렇게 선언하면 
    // s_head는 첫 번째 노드, b_head는 두 번째 노드, temp는 세 번째 노드를 가리키게 된다.

    s_head -> next = NULL; // 역순 변경을 위해 s_head가 가리키는 주소를 NULL로 초기화
    b_head->next = s_head; // b_head는 전 노드인 s_head를 가리키도록 한다.

    while(1){ // 반복문 실행
        // 각 포인터 들을 한 칸씩 앞으로 이동시킨다.
        s_head = b_head; // s_head가 b_head를 가리키게
        b_head = temp; // b_head는 temp를 가리키게 한다.
        if(!(b_head)){ // b_head가 NULL을 가리키면 반복문이 종료된다. 이 때 s_head가 원래 node가 가리키는 주소가 된다.
            break;
        }
        temp = temp->next; // temp는 temp가 가리키는 다음 주소를 가리키게 한다.
        
        b_head->next = s_head; // b_head의 다음 주소를 직전 노드 s_head를 가리키도록 한다(역순 정렬을 위해)
    }
    *node = s_head; // 반복문이 종료되면 s_head만 남게 되고 s_head부터 원래 *node까지 순차적으로 연결되게 된다. 즉 역순으로 연결되게 된다.
    // node는 이제 s_head를 가리키게 한다.

    return 0;
}

// 값을 입력받아 해당 값과 일치하는 노드를 삭제하는 함수, 매개변수로 Node 포인터 변수의 주소와 정수형 data를 입력받는다.
void deleteNode(Node **node,int data){

    // 노드의 삭제를 도와줄 Node 포인터 변수 mover와 b_mover를 선언
    Node* mover = *node; // mover는 node가 가리키는 주소를 가리키게
    Node* b_mover = NULL; // b_mover는 일단 NULL로 초기화

    while(mover->next != NULL && mover->data != data){ // 해당 데이터가 나오거나 mover가 마지막에 도달할 때 까지 반복문을 반복한다.
        // 반복문을 진행하면서 b_mover와 mover를 한 칸씩 앞으로 전진시킨다.
        b_mover = mover; // b_mover는 mover를 가리키게
        mover = mover->next; // mover는 mover 다음 주소를 가리키게
    }
    if(mover->next == NULL){ // mover가 마지막 노드에 도달한 경우
        if(mover->data == data){ // mover가 가리키는 데이터가 내가 찾는 데이터와 같은 경우(해당 데이터를 지워야 한다)
            b_mover->next = NULL; // b_mover의 다음 주소를 NULL로 하여 mover를 list에서 제외 시킨다.
            free(mover); // mover의 메모리 해제
            return;
        }
        else{ // 마지막 노드까지 왔는데도 내가 찾는 데이터가 없는 경우
            return; // 함수 종료
        }
    }
    else{ // 마지막이 아닌 경우, 찾는 data를 찾은 경우
        if(b_mover==NULL){ // 찾는 data가 첫 번째 노드에 있는 경우이다.
            mover = (*node)->next; // mover에 노드가 가리키는 주소가 가리키는 다음 주소를 넣어준다.
            free(*node); // node가 가리키는 노드 메모리해지(첫 번째 노드 삭제)
            (*node) = mover; // node가 mover의 주소(원래 2번째에 존재하던 주소)를 가리키게 한다.
        }
        else{ // 찾는 data가 첫 번째 노드에 존재하지 않고 중간쯤에 존재하는 경우(mover가 가리키는 노드를 삭제해야 함)
            b_mover->next = mover->next; // b_mover의 다음 주소로 mover의 다음 주소를 넣어준다.
            mover -> next = NULL; // mover의 다음 주소가 NULL를 가리키도록
            free(mover); // mover를 메모리 해제
        }
    }
}

// 마지막 노드를 삭제하는 함수, 매개변수로 Node 포인터 변수의 주소를 입력받는다.
void deleteLast(Node **node){
    Node* mover = *node; // Node 구조체를 가리키는 포인터 변수 mover가 node가 가리키던 주소를 갖도록 선언 및 초기화
    Node* b_mover = NULL; // Node 구조체를 가리키는 포인터 변수 b_mover를 일단 NULL로 초기화

    while(mover->next != NULL){ // mover가 마지막 노드에 도달할 때 까지 반복(b_mover와 mover을 이동시키기 위함)
        b_mover = mover; // b_mover를 한 칸 앞으로
        mover = mover->next; // mover를 한 칸 앞으로 이동시킨다.
    }
    mover->next = NULL; // mover의 다음 주소를 NULL로 초기화
    free(mover); // mover를 메모리 해제
    b_mover->next = NULL; // b_mover의 다음 주소를 NULL로 초기화
}

// 첫 번째 노드를 삭제하는 함수, 매개변수로 Node 포인터 변수의 주소를 입력받는다.
void deleteFirst(Node **node){
    Node *temp = (*node); // Node 구조체를 가리키는 포인터 변수 temp가 node가 가리키던 주소를 갖도록 선언 및 초기화
    (*node) = (*node)->next; // node가 가리키던 주소를 node가 가리키던 주소의 변수가 가리키는 주소로 초기화, 즉 원래 노드에서 2번째 주소를 가리키도록 초기화
    temp->next = NULL; // 원래 node가 가리키던 노드의 다음 주소를 NULL로 초기화

    free(temp); // 원래 node가 가리키던 노드를 메모리 해지
}


// linked list 출력을 위한 함수, 함수의 매개변수로 Node 포인터 변수를 받는다. 
void Print(Node *node){
    int count = 0; // 몇 번째 노드인지 알려주는 정수형 변수 count

    if(!(node)){ // node가 가리키는 곳이 없다면 데이터가 없으므로 함수 종료
        printf("No Data!\n");
        return;
    }
    while(1){
        printf("[ [%d] = %d ]\n",count,node->data); // 노드의 순서와 노드의 데이터를 출력
        ++count; // 순서 up
        node = node->next; // 다음 노드로 이동
        if(node==NULL){ // 노드가 NULL에 도달한 경우 함수를 종료
            return;
        }
    }
}



// 메인함수
int main(){
	printf("[----- [김태영] [2023041012] -----]\n");
    Node* Head; // Node를 가리키는 포인터 변수 Head선언
    char c; // 명령어를 입력받을 문자형 변수 c 선언
    do{ // 아래 명령어를 반복한다.
        printf("        Please Input Command        \n");
        printf("====================================\n");
        printf("I : Initialize      P : Print\n");
        printf("i : Insert Node     d : Delete Node\n");
        printf("l : Insert Last     e : Delete Last\n");
        printf("f : Insert First    x : Delete First\n");
        printf("r : Invert List     q : Quit\n");
        printf("====================================\n");
        printf("Command : ");
        scanf(" %c",&c); // 위의 command에 맞게 사용자로부터 명령어를 입력받아 c에 저장한다.

        if(c=='I'){ // 명령어가 I인 경우 initialize 함수 실행
            Head = initialize(); 
            continue;
        }
        else if(c=='i'){ // 명령어가 i인 경우 정수 데이터를 입력받은 후 insertNode 함수 실행
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertNode(&Head,data);
            continue;
        }
        else if(c=='l'){ // 명령어가 l인 경우 정수 데이터를 입력받은 후 insertLast 함수 실행
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertLast(&Head,data);
            continue;
        }
        else if(c=='f'){ // 명령어가 f인 경우 정수 데이터를 입력받은 후 insertFirst 함수 실행
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertFirst(&Head,data);
            continue;
        }
        else if(c=='r'){ // 명령어가 r인 경우 invertList 함수 실행
            invertList(&Head);
            continue;
        }
        else if(c=='P'){ // 명령어가 P인 경우 Print 함수 실행
            Print(Head);
            continue;
        }
        else if(c=='d'){ // 명령어가 d인 경우 deleteNode 함수 실행
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            deleteNode(&Head,data);
            continue;
        }
        else if(c=='e'){ // 명령어가 e인 경우 deleteLast 함수 실행
            deleteLast(&Head);
            continue;
        }
        else if(c=='x'){ // 명령어가 d인 경우 deleteFirst 함수 실행
            deleteFirst(&Head);
            continue;
        }
        else if(c=='q'){ // 명령어가 q인 경우 프로그램 종료
            printf("프로그램을 종료합니다.");
            return 0;
        }
    }while(1);
 
}