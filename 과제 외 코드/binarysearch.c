#include <stdio.h>

int binarysearch(int array[],int size,int find){
    int left = 0;
    int right = size-1;
    int middle = 0;
    while(1){
        middle = (left+right)/2;
        if(array[middle] == find){return middle;}
        if(array[middle]>find){right=middle-1;}
        if(array[middle]<find){left=middle+1;}
        if(left>right){
            printf("no data");
            return 0;
        }
    }
}

int main(){
    int a[5] = {1,2,3,4,5};
    int value;
    if(value = binarysearch(a,5,5)){
        printf("%d",value);
    }
}