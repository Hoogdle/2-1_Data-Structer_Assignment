#include <stdio.h>
#include <string.h>


typedef struct data{
    char name[10];
    int age;
    data * next;
}data;

int main(){
    data kim;
    strcpy(kim.name,"KIM");
    kim.age = 10;

    printf("%s\t%d",kim.name,kim.age);

}