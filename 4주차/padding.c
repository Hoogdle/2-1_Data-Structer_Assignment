#include <stdio.h>
struct student { // char,int,short�� ������ ����ü student ����
    char lastName[13]; /* 13 bytes */
    int studentId; /* 4 bytes */
    short grade; /* 2 bytes */
};
int main()
{
    printf("[----- [%s] [%s] -----]\n","���¿�","2023041012"); // �̸� �� �й� ���
    struct student pst; // pst�� student ����ü�� �������� ����
    printf("size of student = %ld\n", sizeof(struct student)); // ����ü student�� ũ�⸦ ���
    printf("size of int = %ld\n", sizeof(int)); // int�� �������� ũ�⸦ ���
    printf("size of short = %ld\n", sizeof(short)); // short�� �������� ũ�⸦ ���
    return 0;
}

// ���� ����ü ������ ����� �������� ũ���� ���� 19byte ������  ����ü �е����� ���� 24byte�� ũ�⸦ ������ �˴ϴ�.
// VScode�� packing ����� 8byte�� �����Ǿ� �ֱ⿡ 19byte�� 24byte�� packing �ϰ� �˴ϴ�.     