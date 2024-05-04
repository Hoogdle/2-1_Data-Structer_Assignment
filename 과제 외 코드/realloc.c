#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// realloc(재할당할 포인터 변수, 재할당할 크기)
// realloc을 하면 포인터 변수의 주소가 달라진다.

int main(){
    int* temp;
    temp = (int*)malloc(sizeof(*temp)*SIZE);
    printf("%p\n",temp); //00752520

    temp = (int*)realloc(temp,SIZE*100);
    printf("%p\n",temp); //007536C0

}