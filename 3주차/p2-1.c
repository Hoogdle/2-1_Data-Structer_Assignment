#include <stdio.h>
#define MAX_SIZE 100 // MAX_SIZE �� 100���� ����
float sum1(float list[], int); // sum1 �Լ� ����
float sum2(float *list, int); // sum2 �Լ� ����
float sum3(int n, float *list); // sum3 �Լ� ����
float input[MAX_SIZE], answer; // ���������� float�� 100���� ���Ҹ� ���� input �迭�� float�� �����͸� ���� answer ����
int i; // ���������� int�� ������ i ����
void main(void)
{
    printf("[----- [%s] [%s] -----]\n","���¿�","2023041012"); // �̸� �� �й� ���
    for(i=0; i < MAX_SIZE; i++) // 100�� �ݺ��ϴ� for��
    input[i] = i; // input �迭�� ���Ҹ� 0~99�� ���� �ʱ�ȭ
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input �迭�� �ּ� ���
    answer = sum1(input, MAX_SIZE); // answer�� sum1 �Լ��� ���ϰ����� �ʱ�ȭ, sum1�ȿ� ��ɾ���� ���� �����.
    printf("The sum is: %f\n\n", answer); // answer�� ��. �� list�� ��� ���� ���� ���� ���
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input �迭�� �ּ� ���
    answer = sum2(input, MAX_SIZE); // sum2�� ��� ����, answer�� ���� sum2�� ��ȯ ������ �ʱ�ȭ ��.
    printf("The sum is: %f\n\n", answer); // answer �� ��. �� list�� ��� ���� ���� ���� ���
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input); // input �迭�� �ּ� ���
    answer = sum3(MAX_SIZE, input); // sum3�� ��� ����, answer�� ���� sum3�� ��ȯ ������ �ʱ�ȭ
    printf("The sum is: %f\n\n", answer); // answer�� �� ���
}

float sum1(float list[], int n) { // �Ű������� float�� �迭�� int �� n�� ����
printf("list\t= %p\n", list); // �Ű������� ���� �迭�� �ּ� ���
printf("&list\t= %p\n \n", &list); // ������ ���� list�� ����� ���� �޸� �ּ�
int i; // int�� i ����
float tempsum = 0; // float�� tempsum ���� �� 0 ���� �ʱ�ȭ
for(i = 0; i < n; i++) // �Ű������� ���� n��ŭ �迭 �ݺ�
tempsum += list[i];  // tempsum�� list�� ��� ���� ���ϰ� �ȴ�
return tempsum; // tempsum ��ȯ
}

float sum2(float *list, int n) { // �Ű������� float���� ����Ű�� list�� int�� n�� ����
printf("list\t= %p\n", list); // list�� �ּҸ� ���
printf("&list\t= %p\n\n", &list); // ������ ���� list�� ����� ���� �޸� �ּ�
int i; // int�� i ����
float tempsum = 0; // float�� tempsum ���� �� 0���� �ʱ�ȭ
for(i = 0;i < n;i++) // �Ű������� ���� n ��ŭ for�� �ݺ�
tempsum += *(list +i); // list�� �迭�� 0~n ������ ������ ���� ��� tempsum�� ���ϰ� �ȴ�.
return tempsum; // tempsum�� ��ȯ
}

/* stack variable reuse test */
float sum3(int n, float *list) { // �Ű������� int�� n�� float �����͸� ����Ű�� �����͸� ����
printf("list\t= %p\n", list); // list�� �ּҸ� ���
printf("&list\t= %p\n\n", &list); // ������ ���� list�� ����� ���� �޸� �ּ�(�Ű����� ������ ����Ǿ list�� ���� �ּ� ���� �����.)
int i; // int�� i�� ����
float tempsum = 0; // float�� tempsum�� ���� �� �ʱ�ȭ
for(i = 0;i < n;i++) // �Ű������� ���� n��ŭ �ݺ�
tempsum += *(list +i); // tempsum���� list ���� 0~n�� ���� ���Ѵ�
return tempsum; // tempsum�� ��ȯ
}
