#include <stdio.h>
struct student { // char,int,short를 가지는 구조체 student 선언
    char lastName[13]; /* 13 bytes */
    int studentId; /* 4 bytes */
    short grade; /* 2 bytes */
};
int main()
{
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    struct student pst; // pst를 student 구조체를 가지도록 선언
    printf("size of student = %ld\n", sizeof(struct student)); // 구조체 student의 크기를 출력
    printf("size of int = %ld\n", sizeof(int)); // int형 데이터의 크기를 출력
    printf("size of short = %ld\n", sizeof(short)); // short형 데이터의 크기를 출력
    return 0;
}

// 실제 구조체 내에서 선언된 변수들의 크기의 합은 19byte 이지만  구조체 패딩으로 인해 24byte의 크기를 가지게 됩니다.
// VScode는 packing 방식이 8byte로 지정되어 있기에 19byte를 24byte로 packing 하게 됩니다.     