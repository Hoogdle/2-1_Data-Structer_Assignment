#include<stdio.h>
#include<stdlib.h>
void main()
{
    int **x; // 정수형 포인터를 가리키는 포인터 변수 즉 더블 포인터 변수 x 선언
    // pc는 64비트 머신이지만 vscode가 32비트로 코드를 실행하여 포인터의 크기가 4비트로 나옵니다.
    // 64비트 머신이면 8바이트, 32비트 머신이면 4바이트의 포인터 크기를 갖습니다.
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    printf("sizeof(x) = %lu\n", sizeof(x)); // 더블 포인터 변수의 크기 출력 
    printf("sizeof(*x) = %lu\n", sizeof(*x)); // 포인터 변수의 크기 출력 
    printf("sizeof(**x) = %lu\n", sizeof(**x)); // int형 변수의 크기 출력
}