#include <stdio.h>
void print_one(int *ptr, int rows); // print_one 함수 선언
int main()
{
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    int one[] = {0, 1, 2, 3, 4}; // int형 배열 선언 및 {0,1,2,3,4} 로 초기화
    printf("one = %p\n", one); // int형 배열 one의 주소 출력
    printf("&one = %p\n", &one); // int형 배열 one의 주소 출력
    printf("&one[0] = %p\n", &one[0]); // int형 배열 one의 첫 번째 원소 주소 출력
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5); // 함수의 매개변수로 리스트 one의 첫 번째 인덱스의 주소와 5를 input
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5); // 함수의 매개변수로 리스트 one의 주소와 5를 input
    return 0;
}
void print_one(int *ptr, int rows) // int를 가리키는 포인터 변수 ptr와 int형 데이터 rows를 매개변수로 입력 받음
    {/* print out a one-dimensional array using a pointer */
    int i; // int형 데이터 i 선언
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++) // 매개변수로 받은 rows만큼 반복문 실행
    printf("%p \t %5d\n", ptr + i, *(ptr + i)); // ptr과 i를 더한 주소와 ptr과 i를 더한 주소가 가지고 있는 값을 출력
    printf("\n");
}

// 배열의 주소와 배열의 첫 번째 인덱스의 주소가 같다는 것을 복습할 수 있었다
// 배열의 주소 접근을 {배열} + {정수} 와 같이 할 수 있고 그에 대한 값의 참조는 *로 접근하는 것을 복습할 수 있었다