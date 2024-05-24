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
	// 루트노드에서 시작하여 계속해서 이 함수를 부르게 되는데 prt->left가 함수의 매개변수로 먼저 걸리게 되므로
	// 먼저 왼쪽 최하단 노드에 도달하게 됩니다. 왼쪽 최하단 노드 기준 ptr->left와 ptr->right는 모두 null 이므로 
	// 왼쪽 최하단 노드의 값과 부모노드의 값이 순차대로 출력되게 됩니다. 이 후 ptr->right가 매개변수 들어가게 되어
	// 오른쪽 서브트리의 왼쪽 최하단 노드에 도달할 때 까지 함수가 계속 호출됩니다.

	// 위 과정을 요약하면 아래의 리프노드 부터 시작하여 LVR순으로 노드의 값이 출력되며 해당 서브트리의 모든 노드의 값이 출력되면
	// 부모 노드로 올라가서 모든 노드의 값이 출력될 때까지 LVR순으로 값이 출력되게 됩니다.
	if(ptr){ // 함수의 인자의 주소가 NULL이 아니라면 아래 블록 실행(리프노드 left와 right가 NULL 이기 때문에 이 조건문에 걸리게 됩니다.)
		inorderTraversal(ptr->left); // 왼쪽 자식노드의 주소가 먼저 들어갑니다(왼쪽 최하단 노드에서 시작되게 됨 + LVR 순서를 위해)
		printf("[%d] ",ptr->key); // 노드의 값을 출력
		inorderTraversal(ptr->right); // 오른쪽 자식노드의 주소가 이후 들어갑니다.
		// 위의 같은 순서로 자식노드가 함수에 들어가야 LVR이 구현됩니다.
	}
}

void preorderTraversal(Node* ptr) // VLR 순회
{
	// 위 함수 LVR 순회에서의 아이디어는 같지만 순서가 값출력 -> 왼쪽 자식 -> 오른쪽 자식으로 변경되었습니다.
	// V의 값을 출력하면서 먼저 왼쪽 서브트리로 내려가게 됩니다. 왼쪽 서브트리에서 출력할 수 있는 모든 V의 값이 출력되면
	// 오른쪽 서브트리를 탐색하기 시작하여 오른쪽 서브트리 기준 왼쪽으로 계속 내려가면서 출력할 수 있는 모든 V 값이 출력합니다.
	// 위 과정이 모든 노드에 적용되면 VLR 순회가 완료됩니다.
	if(ptr){
		printf("[%d] ",ptr->key); // 먼저 노드의 값(V)를 출력합니다/ 
		preorderTraversal(ptr->left); // 해당 노드의 왼쪽 자식 노드의 주소가 들어갑니다. 이 함수가 반복되면서 
									  // V의 값 출력->왼쪽 자식 노드로 이동이 반복되며 왼쪽 최하단 노드에 도달할 때 까지 반복합니다.
		preorderTraversal(ptr->right); // 위 함수가 종료(왼쪽 서브트리의 모든 V값이 출력)되었으면 이제는 오른쪽 서브트리를 탐색하여
										// 오른쪽 서브트리 기준 왼쪽 최하단 노드에 도달 할 때까지 V의 값을 출력합니다.
	}
}

void postorderTraversal(Node* ptr) // LRV 순회
{
	// 아이디어는 위의 순회 알고리즘과 동일하지만 값 출력의 순서에 변화가 있습니다.

	// 루트 노드에서 시작
	if(ptr){ // 함수 인자의 주소가 NULL 이 아니라면 아래 블록 실행
		postorderTraversal(ptr->left); // 이 함수가 순환하면서 왼쪽 최하단 노드에 도달하게 됩니다. 최하단 노드 기준 left와 right는 모든 NULL
									   // 이므로 printf를 통해 노드의 key 값이 출력되며 그 다음으로는 최하단 노드의 부모 노드의 ptr->right로 함수가 진행됩니다.
									   // 위에서 ptr->right는 왼쪽 최하단 노드의 형제 노드가 되고 해당 노드의 left와 right는 모두 NULL 이므로 key 값이 출력되게 됩니다.
		postorderTraversal(ptr->right); 
		printf("[%d] ",ptr->key); // 이후 왼쪽 최하단 노드의 부모노드의 key 값이 출력되며 이렇게 하나하나 부모노드를 향해 올라가게 되며 모든 노드의 key가 출력될 때 까지 반복됩니다.
	}
}


int insert(Node* head, int key) // Node 삽입함수
{	
	Node* temp; // 새로운 노드를 가리킬 포인터 변수 temp
	temp = (Node*)malloc(sizeof(Node)); // temp에 Node 구조체를 동적 메모리할당
	temp->left = NULL; // 새로 삽입되는 노드는 leaf node가 되므로 left와 right 모두 NULL로 초기화 해준다.
	temp->right = NULL; // right NULL로
	temp->key = key; // 새로 삽입될 노드의 key를 매개변수로 받은 key로 업데이트 해준다.

	if(!(head->left)){ // head left는 루트노드를 가리키는데 루트 노드가 존재하지 않는다면
		head->left = temp; // 루트노드를 위에서 만든 temp로 지정해줍니다.
		return 1; // 함수 종료
	}

	// 루트 노드가 존재하는 경우 (== 기존에 이미 트리가 있는 경우)
	head = head->left; // head를 일단 루트노드로 설정해줍니다.
	Node* tail = NULL; // head 포인터 바로 뒤를 따라갈 포인터 변수 tail
	while(head){ // head가 NULL이 아닐 때 까지 반복합니다.
				 // 아래 과정에서 head가 트리의 아래로 계속 내려가게 되는데 head가 NULL이라는 것은 tail이 leaf node에
				 // 도달했다는 것입니다.
		if(key<head->key){ // 포인터 변수 head가 어디로 움직일지 결정해줍니다. 트리는 부모노드 기준 왼쪽에는 작은 값 오른쪽에는 큰 값을
						   // 배치하므로 그 form에 맞도록 해줍니다.
						   // 새로운 노드의 key 값이 부모노드의 key 값보다 작은 경우 이므로 left child 로 가야합니다.
			tail = head; // tail이 head의 직전 주소를 가리키게 합니다.
			head = head->left; // head를 왼쪽 자식 노드를 가리키게 합니다.
		}
		else{ // 새로운 노드 key가 부모 노드의 key 보다 큰 경우
			tail = head; // tail이 head의 직전 주소를 가리키게 합니다.
			head = head->right;// head를 오른쪽 자식 노드를 가리키게 합니다.
		}
	}
	// tail를 둔 이유는 위 while문 조건이 head가 NULL인 경우에 끝나게 되므로 head의 직전 주소를 저장해야만 합니다.

	// 위 과정을 거치면 새로운 노드의 부모노드를 tail이 가리키게 됩니다.

	// key 값이 tail 보다 작은 경우 tail 왼편에 key를, 큰 경우에는 오른편에 key가 들어가게 합니다.
	if(key<tail->key){tail->left = temp;} // key 값이 tail key 보다 작은 경우 왼편에
	else{tail->right = temp;} // key 값이 tail key 보다 큰 경우 오른편에
}

int deleteLeafNode(Node* head, int key) // leafnode를 삭제하는 함수
{
	if(!(head->left)){ // head->left는 루트 노드를 가리키는 이게 NULL 이라면 Tree가 비었다는 것을 의미하므로 
		printf("Tree is empty!\n"); // 트리가 비었다고 출력한 후 함수를 종료합니다.
		return 1;
	}

	head = head->left; // head가 루트노드를 가리키게 합니다.
	Node* tail = NULL; // head의 직전 주소를 저장할 포인터 tail 선언 및 NULL로 초기화





	while(head){ // head가 NULL이 될 때까지 반복해줍니다. head가 NULL이 되면 삭제해야할 노드의 주소를 잃게 되므로
				// head 직전 주소를 저장할 tail 포인터를 위에서 선언해줬습니다.
		if(head->key == key){break;} // 만약 head가 가리키는 key가 내가 찾는 key라면 반복문에서 나옵니다.
		if(key<head->key){ // 내가 찾는 key가 head key 보다 작다면 key는 왼쪽에 있으므로 head를 왼쪽으로 이동시킵니다.
			tail = head; // tail이 head 직전 주소를 가리키게 합니다.
			head = head->left; // head를 왼쪽 자식을 가리키게 합니다.
		}
		else{ // 내가 찾는 key가 head의 key 보다 큰 경우
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


