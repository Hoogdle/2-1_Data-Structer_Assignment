#include <stdio.h>
int main()
{
    int i;
    int *ptr;
    int **dptr;
    i = 1234;
    
    printf("--------[%s] [%s]--------\n","���¿�","2023041012"); 
    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i); // i�� �� Ȯ��
    printf("address of i == %p\n", &i); // i�� �ּ� Ȯ��
    printf("value of ptr == %p\n", ptr); // ptr�� ����Ű�� ������ �ּ� Ȯ��
    printf("address of ptr == %p\n", &ptr); // ptr(��ü) �ּ� Ȯ��
    ptr = &i; /* ptr is now holding the address of i */ //ptr�� i�� �ּҸ� ����Ű���� �ʱ�ȭ
    printf("\n[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i); // i�� �� Ȯ��
    printf("address of i == %p\n", &i); // i�� �ּ� Ȯ��
    printf("value of ptr == %p\n", ptr); // ptr�� ����Ű�� ����(i)�� �ּ� Ȯ��
    printf("address of ptr == %p\n", &ptr); // ptr ��ü�� �ּ� Ȯ��
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� ����(i)�� �� Ȯ��
    dptr = &ptr; /* dptr is now holding the address of ptr */ // ���� ������ dptr�� ������ ptr�� ����Ű���� �ʱ�ȭ
    printf("\n[checking values after dptr = &ptr] \n");
    printf("value of i == %d\n", i); // i�� �� Ȯ��
    printf("address of i == %p\n", &i); // i�� �ּ� Ȯ��
    printf("value of ptr == %p\n", ptr); //ptr�� ����Ű�� ����(i)�� �ּ� Ȯ��
    printf("address of ptr == %p\n", &ptr); //ptr ��ü�� �ּ� Ȯ��
    printf("value of *ptr == %d\n", *ptr); //ptr�� ����Ű�� ����(i)�� �� Ȯ��
    printf("value of dptr == %p\n", dptr); // dptr�� ����Ű�� ����(ptr)�� �ּ� Ȯ��
    printf("address of dptr == %p\n", &dptr); // dptr ��ü�� �ּ� Ȯ��
    printf("value of *dptr == %p\n", *dptr); // dptr�� ����Ű�� ����(ptr)�� ��(i�� �ּ�) Ȯ��
    printf("value of **dptr == %d\n", **dptr); // dptr�� ����Ű�� ����(ptr)�� ����Ű�� ����(i)�� �� Ȯ��
    *ptr = 7777; /* changing the value of *ptr */ // ptr�� ����Ű�� ����(i)�� ���� 7777�� �ʱ�ȭ
    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i); // i�� �� Ȯ��
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� ����(i)�� �� Ȯ��
    printf("value of **dptr == %d\n", **dptr); // dptr�� ����Ű�� ����(ptr)�� ����Ű�� ����(i)�� �� Ȯ��
    **dptr = 8888; /* changing the value of **dptr */ // dptr�� ����Ű�� ����(ptr)�� ����Ű�� ����(i)�� ���� 8888�� �ʱ�ȭ
    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i); // i�� �� Ȯ��
    printf("value of *ptr == %d\n", *ptr); // ptr�� ����Ű�� ����(i)�� �� Ȯ��
    printf("value of **dptr == %d\n", **dptr); // dptr�� ����Ű�� ����(ptr)�� ����Ű�� ����(i)�� �� Ȯ��
    return 0;
}