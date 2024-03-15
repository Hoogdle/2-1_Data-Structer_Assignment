#include <stdio.h>
int main(){

 char charType; //문자형 데이터 변수 charType 
 int integerType; //정수형 데이터 변수 integerType
 float floatType; //실수형 데이터 변수 floatType
 double doubleType; //double형 데이터 변수 doubleTy
 printf("--------[%s] [%s]--------\n","김태영","2023041012"); 
 printf("Size of char: %ld byte\n",sizeof(charType)); //charType 변수의 사이즈 확인, 문자형이므로 1바이트
 printf("Size of int: %ld bytes\n",sizeof(integerType)); // integerType 변수의 사이즈 확인, int형이므로 4바이트
 printf("Size of float: %ld bytes\n",sizeof(floatType)); // floatType 변수의 사이즈 확인 float형이므로 4바이트
 printf("Size of double: %ld bytes\n",sizeof(doubleType)); // doubleType 변수의 사이즈 확인 double형이므로 8바이트
 printf("-----------------------------------------\n");
 printf("Size of char: %ld byte\n",sizeof(char)); // 자료형 char의 사이즈 확인, char은 1바이트 크기를 가지므로 1바이트
 printf("Size of int: %ld bytes\n",sizeof(int)); // 자료형 int의 사이즈 확인, int은 4바이트 크기를 가지므로 4바이트
 printf("Size of float: %ld bytes\n",sizeof(float)); // 자료형 float 사이즈 확인, float은 4바이트 크기를 가지므로 4바이트
 printf("Size of double: %ld bytes\n",sizeof(double)); // 자료형 double 사이즈 확인, double은 8바이트 크기를 가지므로 8바이트
 printf("-----------------------------------------\n");
 // cf) pc가 64비트 머신이라 포인터의 크기는 8바이트이지만 vscode가 32비트 기준으로 컴파일을하여 출력 결과는 4바이트가 나옵니다.
 printf("Size of char*: %ld byte\n",sizeof(char*)); // char을 가리키는 포인터의 크기를 확인합니다. 포인터는 주소를 가리키기 때문에 가리키는 데이터 타입과 상관없이 8바이트의 크기를 가집니다.
 printf("Size of int*: %ld bytes\n",sizeof(int*)); // int를 가리키는 포인터의 크기를 확인합니다. 포인터는 주소를 가리키기 때문에 가리키는 데이터 타입과 상관없이 8바이트의 크기를 가집니다.
 printf("Size of float*: %ld bytes\n",sizeof(float*)); // float를 가리키는 포인터의 크기를 확인합니다. 포인터는 주소를 가리키기 때문에 가리키는 데이터 타입과 상관없이 8바이트의 크기를 가집니다.
 printf("Size of double*: %ld bytes\n",sizeof(double*)); // double를 가리키는 포인터의 크기를 확인합니다. 포인터는 주소를 가리키기 때문에 가리키는 데이터 타입과 상관없이 8바이트의 크기를 가집니다.
 return 0;
}