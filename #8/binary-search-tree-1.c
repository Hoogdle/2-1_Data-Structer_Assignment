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


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

void post_free(Node *ptr,Node* tail){
	if(ptr){
		post_free(ptr->left);
		post_free(ptr->right);
		free(ptr);
	}
}

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
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
			if(head==NULL){printf("success\n");}
			if(head->left==NULL){printf("wow");}
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

	}while(command != 'r' && command != 'R');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;
	return 1;
}



void inorderTraversal(Node* ptr)
{
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
	post_free(head);
}





