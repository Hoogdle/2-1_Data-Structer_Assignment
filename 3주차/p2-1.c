#include <stdio.h>
#define MAX_SIZE 100 // MAX_SIZE 를 100으로 지정
float sum1(float list[], int); // sum1 함수 선언
float sum2(float *list, int); // sum2 함수 선언
float sum3(int n, float *list); // sum3 함수 선언
float input[MAX_SIZE], answer; // 전역변수로 float형 100개의 원소를 갖는 input 배열과 float형 데이터를 갖는 answer 선언
int i; // 전역번수로 int형 데이터 i 선언
void main(void)
{
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    for(i=0; i < MAX_SIZE; i++) // 100번 반복하는 for문
    input[i] = i; // input 배열의 원소를 0~99로 각각 초기화
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열의 주소 출력
    answer = sum1(input, MAX_SIZE); // answer을 sum1 함수의 리턴값으로 초기화, sum1안에 명령어들이 먼저 실행됨.
    printf("The sum is: %f\n\n", answer); // answer의 값. 즉 list의 모든 값을 더한 값이 출력
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열의 주소 출력
    answer = sum2(input, MAX_SIZE); // sum2의 명령 실행, answer의 값이 sum2의 반환 값으로 초기화 됨.
    printf("The sum is: %f\n\n", answer); // answer 의 값. 즉 list의 모든 값을 더한 값이 출력
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input 배열의 주소 출력
    answer = sum3(MAX_SIZE, input); // sum3의 명령 실행, answer의 값을 sum3의 반환 값으로 초기화
    printf("The sum is: %f\n\n", answer); // answer의 값 출력
}

float sum1(float list[], int n) { // 매개변수로 float형 배열과 int 형 n를 받음
printf("list\t= %p\n", list); // 매개변수로 받은 배열의 주소 출력
printf("&list\t= %p\n \n", &list); // 포인터 변수 list가 저장된 스택 메모리 주소
int i; // int형 i 선언
float tempsum = 0; // float형 tempsum 선언 및 0 으로 초기화
for(i = 0; i < n; i++) // 매개변수로 받은 n만큼 배열 반복
tempsum += list[i];  // tempsum에 list의 모든 값을 더하게 된다
return tempsum; // tempsum 반환
}

float sum2(float *list, int n) { // 매개변수로 float형을 가리키는 list와 int형 n을 받음
printf("list\t= %p\n", list); // list의 주소를 출력
printf("&list\t= %p\n\n", &list); // 포인터 변수 list가 저장된 스택 메모리 주소
int i; // int형 i 선언
float tempsum = 0; // float형 tempsum 선언 및 0으로 초기화
for(i = 0;i < n;i++) // 매개변수로 받은 n 만큼 for문 반복
tempsum += *(list +i); // list의 배열의 0~n 까지의 원소의 값을 모두 tempsum에 더하게 된다.
return tempsum; // tempsum을 반환
}

/* stack variable reuse test */
float sum3(int n, float *list) { // 매개변수로 int형 n과 float 데이터를 가리키는 포인터를 받음
printf("list\t= %p\n", list); // list의 주소를 출력
printf("&list\t= %p\n\n", &list); // 포인터 변수 list가 저장된 스택 메모리 주소(매개변수 순서가 변경되어서 list의 스택 주소 또한 변경됨.)
int i; // int형 i를 선언
float tempsum = 0; // float형 tempsum을 선언 및 초기화
for(i = 0;i < n;i++) // 매개변수로 받은 n만큼 반복
tempsum += *(list +i); // tempsum에다 list 원소 0~n의 값을 더한다
return tempsum; // tempsum을 반환
}
