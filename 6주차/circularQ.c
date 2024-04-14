#include <stdio.h>
#include <stdlib.h>

// 과제에서 요구한 'isEmpty','isFull','enQueue','deQueue'외에 추가적인기능
// 'makeQueue'(큐를 만드는 기능), 'showQueue'(현재 큐의 상태를 보여주는 기능), 'infoQueue(front와 rear의 위치 보여줌)'
// 을 추가적으로 구현했습니다.

// 또한 https://youtu.be/m3K4pDSbMZw의 영상과 같이 커맨드로 큐를 작동하게끔 구현했습니다.

// isEmpty와 isFull은 enQueue와 deQueue 내에서 하나의 조건문 검사로 작동하게끔 구현했습니다.

// queue가 가지는 데이터 타입은 'char'형으로 구현하였습니다.

// {어려웠던 부분}
// 원형 큐에서는 empty와 full 상태를 구분하기 위해 큐의 모든 공간을 사용하는 것이 아니라
// Queue_size - 1 만큼의 공간을 사용한다. 그러기 위해서 rear와 front를 '-1'에서 시작하는 것이 아닌 '0'에서 시작하게 한다.
// enqueue와 dequeue에서 front와 rear은 move -> act 의 동작으로 구현되며 인덱스가 max_size에 도달하면 처음 인덱스이 0으로 보내주게 된다.
// move->act 의 동작으로 작동하기 때문에 처음 시작 인덱스를 0으로 설정하면 0번째 인덱스가 비게 되며 이는 원형 큐에서의 속성 중
// 하나인 Queue_size - 1 만큼의 공간을 사용하는 것과 일치한다.

// 정리
// 1. enqueqe와 dequeue는 move -> act 방식으로 동작(not act->move 물론 act->move로 구현할 수도 있긴하다)
// 2. front와 rear의 시작 인덱스는 '-1'이 아닌 '0'에서 시작.
// 3. '1'과'2'조건의 결합 덕분에 원형큐는 Max_size - 1만큼의 공간을 사용할 수 있게 됨.
// 4. '3'번 덕분에 empty case와 full case를 구분할 수 있게 됨.

typedef struct{
	int front; // 큐의 front
	int rear; // 큐의 rear
	int max; // 큐의  크기
	char *q; // 동적할당된 배열(큐)를 받을 문자형 포인터 q
}Queue; // Queue라는 이름의 구조체 생성


// 매개변수 max 만큼의 큐를 생성한 후 front,rear를 0으로 초기화 하여 구조체 queue를 리턴하는 함수
Queue makeQueue(int max){
	char* data = (char*)malloc(sizeof(char)*max); // data에 malloc으로 동적할당 된 큐의 주소를 넣는다.
	Queue queue; //위에서 만든 데이터타입 Queue로 queue 생성
	queue.front = 0; // queue의 front index를 0으로 초기화
	queue.rear = 0; // queue의 rear index를 0으로 초기화
	queue.max = max; // queue의 크기를 매개변수로 받은 max로 초기화
	queue.q= data; // queue의 q를 큐의 사이즈만큼 동적할당 받은 문자형 배열 data의 주소를 갖도록 함.
	return queue; // 이렇게 만들어진 큐를 리턴한다.
}

// 큐가 비었는지 검사하는 함수
int isEmpty(Queue *q){
	return q->front==q->rear; 
	// front와 rear의 인덱스가 같다면 큐의 Empty조건에 해당한다. 
	// == 연산자로 true or false 값 리턴
}

// 큐가 full인지 검사하는 함수
int isFull(Queue *q){
	return (q->rear+1)%(q->max)==q->front; 
	// 원형 큐에서는 rear+1이 front와 같다면 full인 상태에 해당한다.
	// 나머지 연산을 통해 last index를 넘어가면 index 0 으로 보내준다.

}

// 큐에 데이터를 입력시키는 함수
void enQueue(Queue *q){
	char c; // 데이터를 입력 받을 문자형 c
	if(isFull(q)){ // 데이터를 입력하기 전에 큐가 가득 차있는지 확인한다.
		printf("큐가 가득 찼습니다.\n");
		return;
		// 큐가 가득차있으면 더 이상 데이터를 넣지 못하므로 메시지를 전달하고 입력함수 enqueue를 종료시킨다.
	}

	// 큐가 가득 차 있지 않은 경우
	printf("Input data : ");
	scanf(" %c",&c);
	q->rear = (q->rear+1)%(q->max);
	// rear의 인덱스를 하나 증가시킨다. last index를 벗어난 경우 나머지 연산으로 index 0으로 보내준다.
	q->q[q->rear] = c; // q에서 rear에 해당하는 공간에 입력받은 c를 넣어준다.
}

// 큐의 데이터를 제거하는 함수
void deQueue(Queue *q){
	if(isEmpty(q)){ // 큐가 비었는지 확인한다.
		printf("큐가 비었습니다.\n");
		return;
		// 큐가 비어있는 경우 삭제할 데이터가 없으므로 dequeue 함수를 종료한다.
	}
	q->front = (q->front+1)%(q->max); 
	// front의 인덱스를 하나 증가시킨다. last index를 벗어난 경우 나머지 연산으로 index 0으로 보내준다.
	q->q[q->front]= ' '; // q에서 front에 해당하는 공간을 빈 문자 ' '로 변경해준다.
}

// 현재 큐에 들어있는 데이터를 출력하는 함수
void showQueue(Queue *q){
	printf("[");
	for(int i=0;i<q->max;++i){
		printf(" %c ",q->q[i]);
		// 반복문으로 현재 큐의 모든 내용을 출력한다.
	}
	printf("]\n");
}

// 현재 큐의 데이터와 rear와 front의 인덱스를 출력하는 함수.
void infoQueue(Queue *q){
	// 위에서 구현한 showQueue로 큐의 데이터 출력
	showQueue(q);
	printf("\n");
	// front와 rear의 인덱스를 출력
	printf("front : %d\n",q->front);
	printf("rear : %d\n",q->rear);
}

// '유튜브 영상의 프로그램 대로' 큐가 작동하게끔 구현한 manual 함수
// 각 문자 마다 Enqueue,Dequeue,Showqueue,Infoqueue의 작동 조건을 주고
// 문자를 입력 받아 각 함수를 작동하게끔 구현
void manual(Queue *q){
	while(1){
		char c; // 작동 조건을 담당하는 c
		printf("Please Type Command\n");
		printf("===================\n");
		printf("I : Enqueue\n");
		printf("D : Dequeue\n");
		printf("S : Showqueue\n");
		printf("O : Info about 'front','rear'\n");
		printf("Q : quit\n");
		printf("Command : ");
		// 각 문자마다 담당하는 작동 함수가 있다.
		scanf(" %c",&c); // 문자를 입력 받는다.

		// 각 조건에 매칭시켜 함수를 실행
		// 'Q'를 입력받으면 함수가 종료 된다.
		if(c=='Q')
			return;
		else if(c=='I')
			enQueue(q);
		else if(c=='D')
			deQueue(q);
		else if(c=='S')
			showQueue(q);
		else if(c=='O')
			infoQueue(q);
	}
}	



int main(){
	// 전역변수에서 선언한 Queue로 구조체 q를 만든 후
	// q를 makeQueue의 리턴 값으로 초기화 했습니다.
	// q의 주소를 manual의 매개변수로 보내어 큐 프로그램이 작동하게끔 했습니다.

	// q의 주소를 함수의 매개변수로 사용하는 이유는 q의 정보를 해당 함수내에서 변경하기 위함입니다.

	Queue q; // Queue 구조체를 가지는 q 선언
	int size; // 큐의 크기를 담당하는 size 변수
	printf("[----- [김태영] [2023041012] -----]\n");
	printf("큐의 크기를 입력하세요 : ");
	scanf("%d",&size); // 큐의 크기를 입력받는다.
	q = makeQueue(size); // size 만큼의 큐를 생성한다.
	manual(&q); // 큐 프로그램 실행

	return 0;
}