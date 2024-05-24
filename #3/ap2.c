#include <stdio.h>
#include <stdlib.h>
void main()
{
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    int list[5];  // int형 데이터를 가지는 5칸의 배열 선언
    int *plist[5]; // int형 데이터의 주소를 가지는 5칸의 배열 선언
    list[0] = 10; // int형 데이터 배열의 첫 번째 원소를 10으로 초기화
    list[1] = 11; // int형 데이터 배열의 두 번째 원소를 11으로 초기화
    plist[0] = (int*)malloc(sizeof(int)); // 포인터 배열의 첫 번째 원소를 정수형 동적메모리를 가리키도록 초기화             
    printf("list[0] \t= %d\n", list[0]); // 정수형 리스트의 첫 번째 원소 출력  
    printf("list \t\t= %p\n", list); // 정수형 리스트의 주소 출력
    printf("&list[0] \t= %p\n", &list[0]); // 정수형 리스트의 첫 번째 원소의 주소 출력
    printf("list + 0 \t= %p\n", list+0); // 정수형 리스트의 첫 번째 원소의 주소 출력
    printf("list + 1 \t= %p\n", list+1); // 정수형 리스트의 두 번째 원소의 주소 출력
    printf("list + 2 \t= %p\n", list+2); // 정수형 리스트의 세 번째 원소의 주소 출력
    printf("list + 3 \t= %p\n", list+3); // 정수형 리스트의 네 번째 원소의 주소 출력
    printf("list + 4 \t= %p\n", list+4); // 정수형 리스트의 다섯 번째 원소의 주소 출력
    printf("&list[4] \t= %p\n", &list[4]); // 정수형 리스트의 다섯 번째 원소의 주소 출력
    free(plist[0]); // 동적메모리 할당된 포인터 배열의 첫 번째 원소 메모리 해지
}