#include <stdio.h>
void print_one(int *ptr, int rows); // print_one �Լ� ����
int main()
{
    printf("[----- [%s] [%s] -----]\n","���¿�","2023041012"); // �̸� �� �й� ���
    int one[] = {0, 1, 2, 3, 4}; // int�� �迭 ���� �� {0,1,2,3,4} �� �ʱ�ȭ
    printf("one = %p\n", one); // int�� �迭 one�� �ּ� ���
    printf("&one = %p\n", &one); // int�� �迭 one�� �ּ� ���
    printf("&one[0] = %p\n", &one[0]); // int�� �迭 one�� ù ��° ���� �ּ� ���
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5); // �Լ��� �Ű������� ����Ʈ one�� ù ��° �ε����� �ּҿ� 5�� input
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5); // �Լ��� �Ű������� ����Ʈ one�� �ּҿ� 5�� input
    return 0;
}
void print_one(int *ptr, int rows) // int�� ����Ű�� ������ ���� ptr�� int�� ������ rows�� �Ű������� �Է� ����
    {/* print out a one-dimensional array using a pointer */
    int i; // int�� ������ i ����
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++) // �Ű������� ���� rows��ŭ �ݺ��� ����
    printf("%p \t %5d\n", ptr + i, *(ptr + i)); // ptr�� i�� ���� �ּҿ� ptr�� i�� ���� �ּҰ� ������ �ִ� ���� ���
    printf("\n");
}

// �迭�� �ּҿ� �迭�� ù ��° �ε����� �ּҰ� ���ٴ� ���� ������ �� �־���
// �迭�� �ּ� ������ {�迭} + {����} �� ���� �� �� �ְ� �׿� ���� ���� ������ *�� �����ϴ� ���� ������ �� �־���