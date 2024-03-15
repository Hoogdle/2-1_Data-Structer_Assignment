#include <stdio.h>
int main()
{
    int i;
    int *ptr;
    int **dptr;
    i = 1234;
    
    printf("--------[%s] [%s]--------\n","김태영","2023041012"); 
    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i); // i의 값 확인
    printf("address of i == %p\n", &i); // i의 주소 확인
    printf("value of ptr == %p\n", ptr); // ptr이 가리키는 변수의 주소 확인
    printf("address of ptr == %p\n", &ptr); // ptr(자체) 주소 확인
    ptr = &i; /* ptr is now holding the address of i */ //ptr이 i의 주소를 가리키도록 초기화
    printf("\n[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i); // i의 값 확인
    printf("address of i == %p\n", &i); // i의 주소 확인
    printf("value of ptr == %p\n", ptr); // ptr이 가리키는 변수(i)의 주소 확인
    printf("address of ptr == %p\n", &ptr); // ptr 자체의 주소 확인
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 변수(i)의 값 확인
    dptr = &ptr; /* dptr is now holding the address of ptr */ // 이중 포인터 dptr이 포인터 ptr를 가리키도록 초기화
    printf("\n[checking values after dptr = &ptr] \n");
    printf("value of i == %d\n", i); // i의 값 확인
    printf("address of i == %p\n", &i); // i의 주소 확인
    printf("value of ptr == %p\n", ptr); //ptr이 가리키는 변수(i)의 주소 확인
    printf("address of ptr == %p\n", &ptr); //ptr 자체의 주소 확인
    printf("value of *ptr == %d\n", *ptr); //ptr이 가리키는 변수(i)의 값 확인
    printf("value of dptr == %p\n", dptr); // dptr이 가리키는 변수(ptr)의 주소 확인
    printf("address of dptr == %p\n", &dptr); // dptr 자체의 주소 확인
    printf("value of *dptr == %p\n", *dptr); // dptr이 가리키는 변수(ptr)의 값(i의 주소) 확인
    printf("value of **dptr == %d\n", **dptr); // dptr이 가리키는 변수(ptr)가 가리키는 변수(i)의 값 확인
    *ptr = 7777; /* changing the value of *ptr */ // ptr이 가리키는 변수(i)의 값을 7777로 초기화
    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i); // i의 값 확인
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 변수(i)의 값 확인
    printf("value of **dptr == %d\n", **dptr); // dptr이 가리키는 변수(ptr)이 가리키는 변수(i)의 값 확인
    **dptr = 8888; /* changing the value of **dptr */ // dptr이 가리키는 변수(ptr)가 가리키는 변수(i)의 값을 8888로 초기화
    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i); // i의 값 확인
    printf("value of *ptr == %d\n", *ptr); // ptr이 가리키는 변수(i)의 값 확인
    printf("value of **dptr == %d\n", **dptr); // dptr이 가리키는 변수(ptr)가 가리키는 변수(i)의 값 확인
    return 0;
}