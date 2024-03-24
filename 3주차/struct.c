#include <stdio.h>
struct student1 { // char,int,char 데이터를 가지는 student1 구조체 선언
    char lastName;
    int studentId;
    char grade;
};
typedef struct { // char,int,char 데이터를 가지는 student2 구조체 선언
                // typedef로 student2만으로도 구조체를 정의할 수 있도록 간편화
    char lastName;
    int studentId;
    char grade;
} student2;
int main() {
    printf("[----- [%s] [%s] -----]\n","김태영","2023041012"); // 이름 및 학번 출력
    struct student1 st1 = {'A', 100, 'A'}; // st1을 student1 구조체로 선언 및 'A',100,'A'로 값을 초기화
    printf("st1.lastName = %c\n", st1.lastName); // st1의 lastName의 값 출력
    printf("st1.studentId = %d\n", st1.studentId); // st1의 studentId 값 출력
    printf("st1.grade = %c\n", st1.grade); // st1의 grade 값 출력
    student2 st2 = {'B', 200, 'B'}; // st2를 student2 구조체로 선언 및 'B',200,'B'로 값을 초기화
    printf("\nst2.lastName = %c\n", st2.lastName); // st2 lastName의 값 출력
    printf("st2.studentId = %d\n", st2.studentId); // st2 studentId의 값 출력
    printf("st2.grade = %c\n", st2.grade); // st2 grade의 값 출력
    student2 st3; // st3 student2 로 선언 
    st3 = st2; // st3을 st2의 내용들로 초기화
    printf("\nst3.lastName = %c\n", st3.lastName); // st3 lastName의 값 출력
    printf("st3.studentId = %d\n", st3.studentId); // st3 studentId의 값 출력
    printf("st3.grade = %c\n", st3.grade); // st3 grade의 값 출력
    /* equality test */
    // if(st3 == st2) /* not working */ // 구조체의 비교는 단일 '=='으로는 불가능하다
    //     printf("equal\n");
    // else
    //     printf("not equal\n");
    return 0;
}

// 구조체의 초기화는 '='로 처리할 수 있지만 구조체의 if문 연산은 '=='로 처리할 수 없다는 것을 복습했습니다.
