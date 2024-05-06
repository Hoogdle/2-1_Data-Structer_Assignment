#include <stdio.h>
#include <stdlib.h>



int main(){
    int row = 3;
    int col = 5;

    int** matrix = (int**)malloc(sizeof(int*)*row);
    for(int i=0;i<row;++i){
        matrix[i] = (int*)malloc(sizeof(int)*col);
    }
    

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            matrix[i][j] = i+j;
        }
    }

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

    // transpose

    printf("\n\n");
    printf("After Transpose \n\n\n");

    int **transpose = (int**)malloc(sizeof(int*)*col);
    for(int i=0;i<col;++i){
        transpose[i] = (int*)malloc(sizeof(int*)*row);
    }

    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            transpose[j][i] = matrix[i][j];
        }
    }

    for(int i=0;i<col;++i){
        for(int j=0;j<row;++j){
            printf("%d\t",transpose[i][j]);
        }
        printf("\n");
    }

    

}