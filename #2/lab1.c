#include <stdio.h>
int main(){

 char charType; //������ ������ ���� charType 
 int integerType; //������ ������ ���� integerType
 float floatType; //�Ǽ��� ������ ���� floatType
 double doubleType; //double�� ������ ���� doubleTy
 printf("--------[%s] [%s]--------\n","���¿�","2023041012"); 
 printf("Size of char: %ld byte\n",sizeof(charType)); //charType ������ ������ Ȯ��, �������̹Ƿ� 1����Ʈ
 printf("Size of int: %ld bytes\n",sizeof(integerType)); // integerType ������ ������ Ȯ��, int���̹Ƿ� 4����Ʈ
 printf("Size of float: %ld bytes\n",sizeof(floatType)); // floatType ������ ������ Ȯ�� float���̹Ƿ� 4����Ʈ
 printf("Size of double: %ld bytes\n",sizeof(doubleType)); // doubleType ������ ������ Ȯ�� double���̹Ƿ� 8����Ʈ
 printf("-----------------------------------------\n");
 printf("Size of char: %ld byte\n",sizeof(char)); // �ڷ��� char�� ������ Ȯ��, char�� 1����Ʈ ũ�⸦ �����Ƿ� 1����Ʈ
 printf("Size of int: %ld bytes\n",sizeof(int)); // �ڷ��� int�� ������ Ȯ��, int�� 4����Ʈ ũ�⸦ �����Ƿ� 4����Ʈ
 printf("Size of float: %ld bytes\n",sizeof(float)); // �ڷ��� float ������ Ȯ��, float�� 4����Ʈ ũ�⸦ �����Ƿ� 4����Ʈ
 printf("Size of double: %ld bytes\n",sizeof(double)); // �ڷ��� double ������ Ȯ��, double�� 8����Ʈ ũ�⸦ �����Ƿ� 8����Ʈ
 printf("-----------------------------------------\n");
 // cf) pc�� 64��Ʈ �ӽ��̶� �������� ũ��� 8����Ʈ������ vscode�� 32��Ʈ �������� ���������Ͽ� ��� ����� 4����Ʈ�� ���ɴϴ�.
 printf("Size of char*: %ld byte\n",sizeof(char*)); // char�� ����Ű�� �������� ũ�⸦ Ȯ���մϴ�. �����ʹ� �ּҸ� ����Ű�� ������ ����Ű�� ������ Ÿ�԰� ������� 8����Ʈ�� ũ�⸦ �����ϴ�.
 printf("Size of int*: %ld bytes\n",sizeof(int*)); // int�� ����Ű�� �������� ũ�⸦ Ȯ���մϴ�. �����ʹ� �ּҸ� ����Ű�� ������ ����Ű�� ������ Ÿ�԰� ������� 8����Ʈ�� ũ�⸦ �����ϴ�.
 printf("Size of float*: %ld bytes\n",sizeof(float*)); // float�� ����Ű�� �������� ũ�⸦ Ȯ���մϴ�. �����ʹ� �ּҸ� ����Ű�� ������ ����Ű�� ������ Ÿ�԰� ������� 8����Ʈ�� ũ�⸦ �����ϴ�.
 printf("Size of double*: %ld bytes\n",sizeof(double*)); // double�� ����Ű�� �������� ũ�⸦ Ȯ���մϴ�. �����ʹ� �ּҸ� ����Ű�� ������ ����Ű�� ������ Ÿ�԰� ������� 8����Ʈ�� ũ�⸦ �����ϴ�.
 return 0;
}