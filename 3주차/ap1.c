#include <stdio.h>
#include <stdlib.h>
void main()
{
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    int list[5]; // int형 데이터 5개를 저장하는 배열 선언
    int *plist[5] = {NULL,}; // int형 데이터의 주소를 가리키는(포인터) 5칸 짜리 배열 선언
    plist[0] = (int *)malloc(sizeof(int)); // int형 포인터 배열의 첫 번째 인덱스를 정수형 데이터 타입을 가지는 동적메모리의 주소로 할당
    list[0] = 1; // int형 데이터를 저장하는 배열의 첫 번째 인덱스를 1로 초기화
    list[1] = 100; // int형 데이터를 저장하는 배열의 두 번째 인덱스를 100으로 초기화
    *plist[0] = 200; // int형 포인터 배열의 첫 번째 인덱스의 주소가 가지는 값을 200으로 초기화
    printf("list[0] = %d\n", list[0]); // int형 배열의 첫번째 원소 출력
    printf("&list[0] = %p\n", &list[0]); // int형 배열의 첫 번째 원소의 주소 출력
    printf("list = %p\n", list); // int형 배열(자체)의 주소 출력, 배열의 주소는 첫 번째 인덱스와 동일
    printf("&list = %p\n", &list); // int형 배열(자체)의 주소 출력, 배열의 주소는 첫 번째 인덱스와 동일
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]); // int형 배열의 두 번째 원소 출력
    printf("&list[1] = %p\n", &list[1]); // int형 배열의 두 번째 원소의 주소 출력
    printf("*(list+1) = %d\n", *(list + 1)); // int형 배열의 두 번째 원소의 값 출력, list+1은 두 번째 원소의 주소이며 '*'를 통해 값에 접근하다.
    printf("list+1 = %p\n", list+1); // int형 배열의 두 번째 원소의 주소 출력, list + 1은 두 번째 원소의 주소이다.
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]); // int형 포인터 배열의 첫 번째 원소가 가리키는 주소에서의 값 출력
    printf("&plist[0] = %p\n", &plist[0]); // int형 포인터 배열의 첫 번째 원소의 주소 출력
    printf("&plist = %p\n", &plist); // int형 포인터 배열의 주소(자체)를 출력, 배열의 주소는 첫 번째 인덱스의 주소와 같다.
    printf("plist = %p\n", plist); // int형 포인터 배열의 주소(자체)를 출력, 배열의 이름은 배열의 주소와 같다.
    printf("plist[0] = %p\n", plist[0]); // int형 포인터 배열의 첫 번째 인덱스가 가리키는 주소를 출력
    printf("plist[1] = %p\n", plist[1]); // int형 포인터 배열의 두 번째 인덱스가 가리키는 주소를 출력
    printf("plist[2] = %p\n", plist[2]); // int형 포인터 배열의 세 번째 인덱스가 가리키는 주소를 출력
    printf("plist[3] = %p\n", plist[3]); // int형 포인터 배열의 네 번째 인덱스가 가리키는 주소를 출력
    printf("plist[4] = %p\n", plist[4]); // int형 포인터 배열의 다섯 번째 인덱스가 가리키는 주소를 출력
    free(plist[0]); // 동적 메모리 할당된 포인터 배열의 첫 번째 원소를 해제
}