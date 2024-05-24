/*
 * Binary Search Tree #1
 *
 * Data Structures
 *
 * School of Computer Science
 * at Chungbuk National University
 *
 */

// 자료구조 과제 #8
// 이름 : 김태영
// 학부 : 소프트웨어학부
// 학번 : 2023041012

// 메뉴얼에 주어진 틀안에서 구현을 하되, main 문의 do while 부분만 while문으로 변경하여 구현했습니다.


#include <stdio.h>
#include <stdlib.h>

typedef struct node { // 각각의 트리 노드들이 가질 데이터 구조
	int key; // 노드의 값을 저장하는 변수
	struct node *left; // 왼쪽 트리의 주소를 저장할 변수
	struct node *right; // 오른쪽 트리의 주소를 저장할 변수
} Node;

int initializeBST(Node** h); // 트리를 가리킬 헤드 노드 생성 함수

/* functions that you have to implement */
void inorderTraversal(Node* ptr); // LVR 방식으로 순회하는 함수	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr); // VLR 방식으로 순회하는 함수    /* recursive preorder traversal */
void postorderTraversal(Node* ptr); // LRV 방식으로 순회하는 함수	  /* recursive postorder traversal */
int insert(Node* head, int key); // 노드를 새로 만들어 삽입할 함수 /* insert a node to the tree */
int deleteLeafNode(Node* head, int key); // 최하단 노드를 삭제하는 함수  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key); // recursive 방식으로 노드를 찾는 함수 /* search the node for the key */
Node* searchIterative(Node* head, int key); // non-recursive 방식으로 노드를 찾는 함수  /* search the node for the key */
int freeBST(Node* head); // 모든 트리를 동적메모리 해제하는 함수 /* free all memories allocated to the tree */

void post_free(Node *ptr){ // freeBST에서 recursvie 방식을 사용하여 동적메모리 해제하기 위해 별도의 post_free 함수를 만들었습니다.
	if(ptr){ // 매개변수로 받은 ptr이 있다면 아래 블록 실행
		post_free(ptr->left); // post_free 에 ptr의 왼쪽 트리 주소를 넣어 순환시킵니다.
		post_free(ptr->right); // post_free 에 ptr의 오른쪽 트리 주소를 넣어 순환시킵니다.

		int data = ptr->key; // 아래의 printf에 data를 출력하기 위해 값을 저장
		free(ptr); // 해당 ptr 해제
		printf("[%d] node free success\n",data); // 노드가 삭제됨을 알리기 위한 printf 문
	}
	// 초기에는 root 노드의 주소가 들어가지만 post_free(ptr->left)가 계속 순환 되면서 왼쪽 최하단 leaf node에 도달하게 됩니다.
	// 왼쪽 최하단 leaf node의 left와 right는 모두 null 이므로 함수가 post_free가 실행이 되더라도 if(ptr)문에서 false값으로 인해 아무런 동작이 발생되지 않으며
	// 두 post_free를 모두 거친 최하단 leaf_node는 아래의 데이터 해제 부분에서 메모리 해제가 됩니다.
	
	// 위에서 발생한 모든 결과는 최하단 leaf node의 부모 노드에서 부른 post_free(ptr->left) 함수의 결과입니다.
	// 다음으로는 post_free(ptr->right)가 실행되며 이 과정은 위에 기술한 과정과 동일합니다.

	// 이렇게 자식노드들이 순차적으로 해제되고 다음으로는 부모노드가 다음으로는 부모의 부모노드가 ... 순차적으로 해지되면서 결국 모든 노드가 해제되게 됩니다.
	
	// 즉, LRV 순회 방식을 따르되 free(ptr)만 추가하여 구현한 코드입니다.
}

/* you may add your own defined functions if necessary */


int main()
{
	char command; // 명령을 저장할 변수
	int key; // 트리 노드의 키
	Node* head = NULL; // 루트노드를 가리킬 포인터 헤드
	Node* ptr = NULL;	/* temp */

	while(1){
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			return 0;
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL){ // head가 이미 initialized 되어 있다면 해당 트리의 모든 노드를 동적 메모리 해지를 해줘야 합니다.
		freeBST(*h); // head가 가리키는 node를 동적메모리 해지
	}	

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); // head가 동적메모리 할당된 노드를 가리키도록
	(*h)->left = NULL;	/* root */ // head가 가리키는 노드의 왼쪽 포인터를 NULL 이 포인터가 root 노드를 가리키게 됩니다.
	(*h)->right = *h; // 오른쪽 포인터는 다시 head를 가리키도록 이쪽 포인터는 쓰지 않습니다.
	(*h)->key = -9999; // head 노드의 값을 -9999로 설정합니다.
	return 1;
}



void inorderTraversal(Node* ptr) // LVR 순회
{
	// 이 함수는 순환 구조를 가집니다. 
	// 
	if(ptr){ 
		inorderTraversal(ptr->left);
		printf("[%d] ",ptr->key);
		inorderTraversal(ptr->right);
	}
}

void preorderTraversal(Node* ptr)
{
	if(ptr){
		printf("[%d] ",ptr->key);
		preorderTraversal(ptr->left);
		preorderTraversal(ptr->right);
	}
}

void postorderTraversal(Node* ptr)
{
	if(ptr){
		postorderTraversal(ptr->left);
		postorderTraversal(ptr->right);
		printf("[%d] ",ptr->key);
	}
}


int insert(Node* head, int key)
{	
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->left = NULL;
	temp->right = NULL;
	temp->key = key;

	if(!(head->left)){
		head->left = temp;
		return 1;
	}

	head = head->left;
	Node* tail = NULL;
	while(head){
		if(key<head->key){
			tail = head;
			head = head->left;
		}
		else{
			tail = head;
			head = head->right;
		}
	}
	if(key<tail->key){tail->left = temp;}
	else{tail->right = temp;}
	
}

int deleteLeafNode(Node* head, int key)
{
	if(!(head->left)){
		printf("Tree is empty!\n");
		return 1;
	}

	head = head->left;
	Node* tail = NULL;
	while(head){
		if(head->key == key){break;}
		if(key<head->key){
			tail = head;
			head = head->left;
		}
		else{
			tail = head;
			head = head->right;
		}
	}

	// 값을 찾은 경우
	if(head){
		// leaf node가 아닌 경우
		if(!(head->left==NULL && head->right==NULL)){
			printf("[%d] is not leaf node!\n",head->key);
			return 1;
		}
		// leaf node인 경우 해당 노드삭제
		if(tail->left==head){
			tail->left = NULL;
		}
		else if(tail->right==head){
			tail->right = NULL;
		}
		free(head);
	}


}

Node* searchRecursive(Node* ptr, int key)
{
	if(!(ptr)){
		return NULL;
	}

	if(key==ptr->key){return ptr;}
	else if(key<ptr->key){return searchRecursive(ptr->left,key);}
	else{return searchRecursive(ptr->right,key);}
}

Node* searchIterative(Node* head, int key)
{
	head = head->left;
	while(head){
		if(key==head->key){return head;}

		if(key<head->key){
			head = head->left;
		}
		else if(key>head->key){
			head = head->right;
		}
	}
	return NULL;
}


int freeBST(Node* head)
{
	post_free(head->left);
	head->left=NULL;
	free(head);
	return 1;
}



// freeBST 부분 손보기!


