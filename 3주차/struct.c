#include <stdio.h>
struct student1 { // char,int,char �����͸� ������ student1 ����ü ����
    char lastName;
    int studentId;
    char grade;
};
typedef struct { // char,int,char �����͸� ������ student2 ����ü ����
                // typedef�� student2�����ε� ����ü�� ������ �� �ֵ��� ����ȭ
    char lastName;
    int studentId;
    char grade;
} student2;
int main() {
    printf("[----- [%s] [%s] -----]\n","���¿�","2023041012"); // �̸� �� �й� ���
    struct student1 st1 = {'A', 100, 'A'}; // st1�� student1 ����ü�� ���� �� 'A',100,'A'�� ���� �ʱ�ȭ
    printf("st1.lastName = %c\n", st1.lastName); // st1�� lastName�� �� ���
    printf("st1.studentId = %d\n", st1.studentId); // st1�� studentId �� ���
    printf("st1.grade = %c\n", st1.grade); // st1�� grade �� ���
    student2 st2 = {'B', 200, 'B'}; // st2�� student2 ����ü�� ���� �� 'B',200,'B'�� ���� �ʱ�ȭ
    printf("\nst2.lastName = %c\n", st2.lastName); // st2 lastName�� �� ���
    printf("st2.studentId = %d\n", st2.studentId); // st2 studentId�� �� ���
    printf("st2.grade = %c\n", st2.grade); // st2 grade�� �� ���
    student2 st3; // st3 student2 �� ���� 
    st3 = st2; // st3�� st2�� ������ �ʱ�ȭ
    printf("\nst3.lastName = %c\n", st3.lastName); // st3 lastName�� �� ���
    printf("st3.studentId = %d\n", st3.studentId); // st3 studentId�� �� ���
    printf("st3.grade = %c\n", st3.grade); // st3 grade�� �� ���
    /* equality test */
    // if(st3 == st2) /* not working */ // ����ü�� �񱳴� ���� '=='���δ� �Ұ����ϴ�
    //     printf("equal\n");
    // else
    //     printf("not equal\n");
    return 0;
}

// ����ü�� �ʱ�ȭ�� '='�� ó���� �� ������ ����ü�� if�� ������ '=='�� ó���� �� ���ٴ� ���� �����߽��ϴ�.
