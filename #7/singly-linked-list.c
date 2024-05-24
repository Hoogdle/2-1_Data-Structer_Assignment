#include <stdio.h>
#include <stdlib.h>


// ���ǳ�Ʈ�� ������ ������� singly-linked-list.c�� ���� �����Ͽ����ϴ�.
// �������� �䱸�ϴ� �Լ� �ܿ� ���� �ڷ�� �÷��ֽ� ���� ��޵� �Լ��� �߰������� �����Ͽ����ϴ�.
// insertNode���� ������ ���� ��Ģ�� �÷��ֽ� ���� ó�� �����Ͱ� ������������ ���ĵ� �� �ְ� �����Ͽ����ϴ�.

// �̸� : ���¿�
// �а� : ����Ʈ�����к�
// �й� : 2023041012


typedef struct Node{
    int data; // �����͸� �����ϴ� ������ ���� 'data'
    struct Node* next; // ���� ����� �ּҸ� �����ϴ� Node ����ü ������ ���� next
}Node; // struct Node�� 'Node'�� ����


// Node�� �ּҸ� �����ϴ� �ʱ⼳�� �Լ� initialize
Node* initialize(){  
    Node* temp; // Node ������ ���� temp ����
    temp = NULL; // temp�� �ּҰ��� NULL�� �ʱ�ȭ
    return temp; // temp�� �����Ѵ�.
}

// Node�� �����ϴ� �Լ�, �Ű������� Node ������ ������ �ּҿ� ���� data�� �޴´�.
int insertNode(Node ** node,int data){
    Node* temp; // Node ������ ���� temp ����
    temp = (Node*)malloc(sizeof(Node)); // temp�� Node�� �����ŭ �����Ҵ� �Ѵ�.
    temp -> data = data; // temp�� data�� �Լ��� �Է¹��� data�� �ʱ�ȭ
    temp -> next = NULL; // temp�� ���� �ּҸ� �ϴ� NULL�� �ʱ�ȭ

    Node* mover = *node; // ���Կ� ������ �� Node ������ ���� mover�� node�� ����Ű�� �ּҷ� �ʱ�ȭ
    Node* tail = NULL; // ���Կ� ������ �� Node ������ ���� tail�� �ϴ� NULL�� �ʱ�ȭ

    if(!(*node)){ // node�� ����ִ� ���
        *node = temp; // list�� �ƹ��� �����Ͱ� ���� ����̹Ƿ� node�� �ٷ� temp�� �ּҸ� �־��ش�.
        return 0; // �Լ� ����
    }

    // node�� ������� ���� ���
    // mover�� ���� �ּҰ� NULL�� �ƴϸ鼭 mover->data�� data�� �ƴ� �� ���� �ݺ��� �ݺ�
    while(mover->next != NULL && mover->data < data){
        // tail�� mover�� �ݺ����� ������ ���� �� ���� �� ĭ ������ ��� �̵���Ų��.
        // tail�� mover�ٷ� ���� list�� ����Ű���� �Ѵ�.
        tail = mover; 
        mover = mover->next;
    }

    // tail�� mover�� �̵��� ���� ��� 

    // mover->data�� data ���� ũ�ų� ���� ���(���������� ������ ���)
    if(mover->data >= data){
        if(tail==NULL){ // tail�� NULL�̶�� tail�� mover�� �� ���� �������� �ʾҴٴ� �ǹ�, �� data�� ����Ʈ ù ��° �����ͺ��� ���� ����̴�.
            tail = (*node); // tail�� node�� ����Ű�� ����Ʈ�� ����Ű���� �Ѵ�.
            (*node) = temp; // node�� temp�� ����Ű�����Ѵ�.
            temp->next = tail; // temp�� ���� �ּҴ� tail, �� ���� node�� ����Ű�� �ּҸ� ����Ű���� �Ѵ�.
            // ù ��°�� ���� �Ϸ�!
        }
        else{ // �߰��� �����ϴ� ���
            tail->next = temp; // tail�� ������ temp��
            temp->next = mover; // temp�� ������ mover�� ����Ű�����Ѵ�.
            // �̷��� �����ϸ� data�� �� ū mover�� temp�� ���������� ���� ������ �������� ������ ��ų �� �ִ�.
        }
    }
    else if(mover->next == NULL){ // mover�� ������ ������ �� ���
        mover->next = temp; // mover�� ����, �� ������ ��忡 temp�� �־��ش�.
    }
}

// �����͸� ù ��°�� �����ϴ� �Լ�, �Ű������� Node ������ ������ �ּ�, ������ ���� data�� �޴´�.
int insertFirst(Node ** node,int data){

    
    Node* temp; // Node ������ ���� temp, temp�� ���� ������ ����̴�.
    Node* messenger; // Node ������ ���� messenger, messenger�� ������ �����ִ� �����̴�.
    temp = (Node*)malloc(sizeof(Node)); // temp�� Node�� ũ�⸸ŭ �����޸� �Ҵ�
    temp -> data = data; // temp�� data�� data�� �ʱ�ȭ
    temp -> next = NULL; // temp�� ���� �ּҸ� NULL�� �ʱ�ȭ

    if(!(*node)){ // node�� ����ִ� ���
        *node = temp; // list�� �ƹ��� �����Ͱ� ���� ����̹Ƿ� node�� �ٷ� temp�� �ּҸ� �־��ش�.
        return 0; // �Լ� ����
    }


    messenger = (*node); // messenger�� node�� ����Ű�� �ּҸ� �־��ش�.
    (*node) = temp; // node�� ���� temp�� ����Ű���� �Ѵ�.(temp�� ù ��°�� ���ԵǴ� �Ͱ� ��ġ)
    temp ->next = messenger; // temp�� ���� �ּҸ� ���� node�� ����Ű�� �ּ�(messenger�� ��)�� �ʱ�ȭ ���ش�.
    // �̷ν� ���� ù ��° ������ �����Ͱ� ���Եȴ�.
}

// �������� �����ϴ� �Լ�, �Ű������� Node ������ ������ �ּ�, ������ ���� data�� �޴´�.
int insertLast(Node ** node,int data){
    Node* temp; // Node ������ ���� temp, temp�� ���� ������ ����̴�.
    temp = (Node*)malloc(sizeof(Node)); // temp�� Node�� ũ�⸸ŭ �����޸� �Ҵ�
    temp->data = data; // temp�� data�� data�� �ʱ�ȭ

    Node* mover = *node; // ������ ��� ���� �̵��� Node ������ ���� mover�� ���� �� node�� ����Ű�� �ּ��� ������ �ʱ�ȭ
    while(mover->next != NULL){ // mover�� linked list�� ������ ���� �� ������
        mover = mover->next; // mover�� �� ĭ�� ������ �̵���Ų��.
    }
    mover->next = temp; // mover�� ���� �ּҸ� temp�� ����
    temp->next = NULL; // temp�� ���� �ּҸ� NULL�� �ʱ�ȭ �Ѵ�.
}

// linked list�� �������� �ϴ� �Լ�, �Ű������� Node ������ ������ �ּҸ� �޴´�.
int invertList(Node ** node){
    // �������� ����� ���� �����ִ� Node ������ ���� b_head,s_head,temp�� ����
    Node* b_head;
    Node* s_head;
    Node* temp;

    s_head = *node; // s_head�� node�� ����Ű�� �ּҷ� �ʱ�ȭ
    b_head = (*node)->next; // b_head�� node�� ����Ű�� �ּҰ� ����Ű�� ���� �ּҷ� �ʱ�ȭ
    if(s_head==NULL || b_head==NULL){ // ���� node�� ����Ű�� �ּҰ� ���ų� b_head�� NULL(��尡 1���� ���) �������� �������� ���ϹǷ� ���� ó��
        printf("Cannot Reverse!\n");
        return 0;
    }

    temp = b_head->next; // temp�� b_haed->next ��, 3��° ��带 ����Ű���� �Ѵ�.

    // �̷��� �����ϸ� 
    // s_head�� ù ��° ���, b_head�� �� ��° ���, temp�� �� ��° ��带 ����Ű�� �ȴ�.

    s_head -> next = NULL; // ���� ������ ���� s_head�� ����Ű�� �ּҸ� NULL�� �ʱ�ȭ
    b_head->next = s_head; // b_head�� �� ����� s_head�� ����Ű���� �Ѵ�.

    while(1){ // �ݺ��� ����
        // �� ������ ���� �� ĭ�� ������ �̵���Ų��.
        s_head = b_head; // s_head�� b_head�� ����Ű��
        b_head = temp; // b_head�� temp�� ����Ű�� �Ѵ�.
        if(!(b_head)){ // b_head�� NULL�� ����Ű�� �ݺ����� ����ȴ�. �� �� s_head�� ���� node�� ����Ű�� �ּҰ� �ȴ�.
            break;
        }
        temp = temp->next; // temp�� temp�� ����Ű�� ���� �ּҸ� ����Ű�� �Ѵ�.
        
        b_head->next = s_head; // b_head�� ���� �ּҸ� ���� ��� s_head�� ����Ű���� �Ѵ�(���� ������ ����)
    }
    *node = s_head; // �ݺ����� ����Ǹ� s_head�� ���� �ǰ� s_head���� ���� *node���� ���������� ����ǰ� �ȴ�. �� �������� ����ǰ� �ȴ�.
    // node�� ���� s_head�� ����Ű�� �Ѵ�.

    return 0;
}

// ���� �Է¹޾� �ش� ���� ��ġ�ϴ� ��带 �����ϴ� �Լ�, �Ű������� Node ������ ������ �ּҿ� ������ data�� �Է¹޴´�.
void deleteNode(Node **node,int data){

    // ����� ������ ������ Node ������ ���� mover�� b_mover�� ����
    Node* mover = *node; // mover�� node�� ����Ű�� �ּҸ� ����Ű��
    Node* b_mover = NULL; // b_mover�� �ϴ� NULL�� �ʱ�ȭ

    while(mover->next != NULL && mover->data != data){ // �ش� �����Ͱ� �����ų� mover�� �������� ������ �� ���� �ݺ����� �ݺ��Ѵ�.
        // �ݺ����� �����ϸ鼭 b_mover�� mover�� �� ĭ�� ������ ������Ų��.
        b_mover = mover; // b_mover�� mover�� ����Ű��
        mover = mover->next; // mover�� mover ���� �ּҸ� ����Ű��
    }
    if(mover->next == NULL){ // mover�� ������ ��忡 ������ ���
        if(mover->data == data){ // mover�� ����Ű�� �����Ͱ� ���� ã�� �����Ϳ� ���� ���(�ش� �����͸� ������ �Ѵ�)
            b_mover->next = NULL; // b_mover�� ���� �ּҸ� NULL�� �Ͽ� mover�� list���� ���� ��Ų��.
            free(mover); // mover�� �޸� ����
            return;
        }
        else{ // ������ ������ �Դµ��� ���� ã�� �����Ͱ� ���� ���
            return; // �Լ� ����
        }
    }
    else{ // �������� �ƴ� ���, ã�� data�� ã�� ���
        if(b_mover==NULL){ // ã�� data�� ù ��° ��忡 �ִ� ����̴�.
            mover = (*node)->next; // mover�� ��尡 ����Ű�� �ּҰ� ����Ű�� ���� �ּҸ� �־��ش�.
            free(*node); // node�� ����Ű�� ��� �޸�����(ù ��° ��� ����)
            (*node) = mover; // node�� mover�� �ּ�(���� 2��°�� �����ϴ� �ּ�)�� ����Ű�� �Ѵ�.
        }
        else{ // ã�� data�� ù ��° ��忡 �������� �ʰ� �߰��뿡 �����ϴ� ���(mover�� ����Ű�� ��带 �����ؾ� ��)
            b_mover->next = mover->next; // b_mover�� ���� �ּҷ� mover�� ���� �ּҸ� �־��ش�.
            mover -> next = NULL; // mover�� ���� �ּҰ� NULL�� ����Ű����
            free(mover); // mover�� �޸� ����
        }
    }
}

// ������ ��带 �����ϴ� �Լ�, �Ű������� Node ������ ������ �ּҸ� �Է¹޴´�.
void deleteLast(Node **node){
    Node* mover = *node; // Node ����ü�� ����Ű�� ������ ���� mover�� node�� ����Ű�� �ּҸ� ������ ���� �� �ʱ�ȭ
    Node* b_mover = NULL; // Node ����ü�� ����Ű�� ������ ���� b_mover�� �ϴ� NULL�� �ʱ�ȭ

    while(mover->next != NULL){ // mover�� ������ ��忡 ������ �� ���� �ݺ�(b_mover�� mover�� �̵���Ű�� ����)
        b_mover = mover; // b_mover�� �� ĭ ������
        mover = mover->next; // mover�� �� ĭ ������ �̵���Ų��.
    }
    mover->next = NULL; // mover�� ���� �ּҸ� NULL�� �ʱ�ȭ
    free(mover); // mover�� �޸� ����
    b_mover->next = NULL; // b_mover�� ���� �ּҸ� NULL�� �ʱ�ȭ
}

// ù ��° ��带 �����ϴ� �Լ�, �Ű������� Node ������ ������ �ּҸ� �Է¹޴´�.
void deleteFirst(Node **node){
    Node *temp = (*node); // Node ����ü�� ����Ű�� ������ ���� temp�� node�� ����Ű�� �ּҸ� ������ ���� �� �ʱ�ȭ
    (*node) = (*node)->next; // node�� ����Ű�� �ּҸ� node�� ����Ű�� �ּ��� ������ ����Ű�� �ּҷ� �ʱ�ȭ, �� ���� ��忡�� 2��° �ּҸ� ����Ű���� �ʱ�ȭ
    temp->next = NULL; // ���� node�� ����Ű�� ����� ���� �ּҸ� NULL�� �ʱ�ȭ

    free(temp); // ���� node�� ����Ű�� ��带 �޸� ����
}


// linked list ����� ���� �Լ�, �Լ��� �Ű������� Node ������ ������ �޴´�. 
void Print(Node *node){
    int count = 0; // �� ��° ������� �˷��ִ� ������ ���� count

    if(!(node)){ // node�� ����Ű�� ���� ���ٸ� �����Ͱ� �����Ƿ� �Լ� ����
        printf("No Data!\n");
        return;
    }
    while(1){
        printf("[ [%d] = %d ]\n",count,node->data); // ����� ������ ����� �����͸� ���
        ++count; // ���� up
        node = node->next; // ���� ���� �̵�
        if(node==NULL){ // ��尡 NULL�� ������ ��� �Լ��� ����
            return;
        }
    }
}



// �����Լ�
int main(){
	printf("[----- [���¿�] [2023041012] -----]\n");
    Node* Head; // Node�� ����Ű�� ������ ���� Head����
    char c; // ��ɾ �Է¹��� ������ ���� c ����
    do{ // �Ʒ� ��ɾ �ݺ��Ѵ�.
        printf("        Please Input Command        \n");
        printf("====================================\n");
        printf("I : Initialize      P : Print\n");
        printf("i : Insert Node     d : Delete Node\n");
        printf("l : Insert Last     e : Delete Last\n");
        printf("f : Insert First    x : Delete First\n");
        printf("r : Invert List     q : Quit\n");
        printf("====================================\n");
        printf("Command : ");
        scanf(" %c",&c); // ���� command�� �°� ����ڷκ��� ��ɾ �Է¹޾� c�� �����Ѵ�.

        if(c=='I'){ // ��ɾ I�� ��� initialize �Լ� ����
            Head = initialize(); 
            continue;
        }
        else if(c=='i'){ // ��ɾ i�� ��� ���� �����͸� �Է¹��� �� insertNode �Լ� ����
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertNode(&Head,data);
            continue;
        }
        else if(c=='l'){ // ��ɾ l�� ��� ���� �����͸� �Է¹��� �� insertLast �Լ� ����
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertLast(&Head,data);
            continue;
        }
        else if(c=='f'){ // ��ɾ f�� ��� ���� �����͸� �Է¹��� �� insertFirst �Լ� ����
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            insertFirst(&Head,data);
            continue;
        }
        else if(c=='r'){ // ��ɾ r�� ��� invertList �Լ� ����
            invertList(&Head);
            continue;
        }
        else if(c=='P'){ // ��ɾ P�� ��� Print �Լ� ����
            Print(Head);
            continue;
        }
        else if(c=='d'){ // ��ɾ d�� ��� deleteNode �Լ� ����
            int data;
            printf("Input Data : ");
            scanf("%d",&data);
            deleteNode(&Head,data);
            continue;
        }
        else if(c=='e'){ // ��ɾ e�� ��� deleteLast �Լ� ����
            deleteLast(&Head);
            continue;
        }
        else if(c=='x'){ // ��ɾ d�� ��� deleteFirst �Լ� ����
            deleteFirst(&Head);
            continue;
        }
        else if(c=='q'){ // ��ɾ q�� ��� ���α׷� ����
            printf("���α׷��� �����մϴ�.");
            return 0;
        }
    }while(1);
 
}