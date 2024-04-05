#include <stdio.h>
#include <stdlib.h>


// 객체 지향 프로그래밍을 연습하기 위해 과제에서 요구하는 함수를 포함한 추가적인 함수를 만들었습니다.

// 행렬을 만들기 위한 함수
int ** make_array(int row_num,int column_num){

    ///////////////// (b) 동적 메모리할당 방식으로 행렬 생성 /////////////////

     int **array = (int**)malloc(row_num*sizeof(int*)); 
    // 2차원 배열을 생성하기 위해 이중 포인터 array에 행의 갯수만큼 포인터 변수를 가질 수 있는 배열을 동적할당
    
    // array는 array[0],array[1],... 와 같은 배열의 첫 번째 원소 array[0]을 가리키는 이중 포인터 변수이며
    // array[0]는 array[0][0]의 주소를 가리키는 포인터 변수입니다.
    // array[0],array[1],array[2]... 의 주소는 연속적이고
    // array[0][0], array[0][1], array[0][2],...의 주소도 연속적입니다.
    // 하지만 array[0][[0] ~ array[1][0]의 주소는 연속적이지 않습니다.
    for (int i=0;i<row_num;++i){
        array[i] = (int*)malloc(column_num*sizeof(int));
        // array[i]는 포인터 변수이며 가리키는 주소는 하나의 행의 배열의 주소입니다.
        // 위 코드는 각 array[i] 마다 각 행의 주소를 가리키도록 주소를 넣어주는 코드입니다.
    }
    /////////////////////////////////////////////////////////////////////////
    return array;
}

void my_info(){
    print("[----- [김태영] [2023041012] -----]");
}
// 행렬을 랜덤 값으로 초기화 하기 위한 함수
void put_random(int **array,int row, int column){
        ///////////////// (c) 랜덤 값으로 행렬 채우기 /////////////////
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<column;++j) // 열을 탐색하기 위한 for문
            array[i][j] = rand()%9+1; // 1~9중 랜덤 값을 array[i][[j]의 값으로 초기화
    }
    /////////////////////////////////////////////////////////////////////////
}

// 행렬 출력을 간단히 하기 위한 보조함수 printer(굳이 함수로 안 만들어도 되지만 객체지향적 프로그래밍을 연습하고 싶어서 만들었습니다!)
void printer(int **array,int row_num,int column_num){ // 매개변수로 이중 포인터인 array와 행과 열의 정수 값을 받습니다.
    for(int i=0;i<row_num;++i){
        for(int j=0;j<column_num;++j){
            printf("%d\t",array[i][j]); // 이중 for문으로 각 행마다의 모든 열의 데이터를 출력합니다.
        }
        printf("\n");
    }
}

///////////////// (d) print_matrix 구현 /////////////////
void print_matrix(int **array_a, int ** array_b,int row,int col){ // 함수의 매개변수로 이중 포인터 변수인 행렬 A와 행렬 B를 받고 행과 열의 크기를 받습니다.
    printf("Matrix A\n");
    printer(array_a,row,col); // 보조함수 printer의 인자로 행렬 a와 행과 열의 크기를 줍니다.
    printf("Matrix B\n");
    printer(array_b,row,col); // 보조함수 printer의 인자로 행렬 b와 행과 열의 크기를 줍니다.
}
/////////////////////////////////////////////////////////////////////////

///////////////// (e) addtion_matrix 구현 /////////////////
void additon_matrix(int **array_a, int ** array_b,int row,int col){
    int **temp = make_array(row,col);
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j) // 열을 탐색하기 위한 for문
            temp[i][j] = array_a[i][j] + array_b[i][j]; // 1~9중 랜덤 값을 array[i][[j]의 값으로 초기화
    }
    printf("-----------------------------------------------------\n");
    printf("Result of Add\n");
    printer(temp,row,col);
    printf("-----------------------------------------------------\n");
    free(temp);
}
/////////////////////////////////////////////////////////////////////////

///////////////// (f) subtraction_matrix 구현 /////////////////
void subtraction_matrix(int **array_a, int ** array_b,int row,int col){
    int **temp = make_array(row,col);
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j) // 열을 탐색하기 위한 for문
            temp[i][j] = array_a[i][j] - array_b[i][j]; // 1~9중 랜덤 값을 array[i][[j]의 값으로 초기화
    }
    printf("-----------------------------------------------------\n");
    printf("Result of Sub\n");
    printer(temp,row,col);
    printf("-----------------------------------------------------\n");
    free(temp);
}
/////////////////////////////////////////////////////////////////////////

///////////////// (g) transpose_matrix 구현 /////////////////
void transpose_matrix(int **array,int row,int col){
    int **temp = make_array(row,col);
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j) // 열을 탐색하기 위한 for문
            temp[i][j] = array[j][i]; // 1~9중 랜덤 값을 array[i][[j]의 값으로 초기화
    }
    printf("-----------------------------------------------------\n");
    printf("Result of Transpose of A\n");
    printer(temp,row,col);
    printf("-----------------------------------------------------\n");
    free(temp);
}
/////////////////////////////////////////////////////////////////////////

///////////////// (h) multiply_matrix 구현 /////////////////
void multiply_matrix(int **array_a, int ** array_b,int row,int col){
    int **temp = make_array(row,col);
    for (int i=0;i<row;++i){ 
        for (int j=0;j<col;++j){
            int value = 0;
            for (int k=0;k<col;++k){
            value += array_a[i][k] * array_b[k][j]; 
            }
            temp[i][j] = value;
        }
    }
    printf("-----------------------------------------------------\n");
    printf("Result of Mul\n");
    printer(temp,row,col);
    printf("-----------------------------------------------------\n");
    free(temp);
}
/////////////////////////////////////////////////////////////////////////


///////////////// (j) 메모리 해제 함수 /////////////////
void free_matrix(int **array){
    free(array);
}
/////////////////////////////////////////////////////////////////////////


int main(){
    my_info();
    ///////////////// (a) 행렬 A와 B의 행과 열의 값을 입력 받는다. /////////////////
    int row_num,column_num; // 행렬의 행과 열의 갯수 변수
    scanf("%d %d",&row_num,&column_num); // 행렬 A의 행과 열의 갯수 입력 받기
    /////////////////////////////////////////////////////////////////////////

    int **array_a = make_array(row_num,column_num);
    int **array_b = make_array(row_num,column_num);

    put_random(array_a,row_num,column_num);
    put_random(array_b,row_num,column_num);


    print_matrix(array_a,array_b,row_num,column_num);
    additon_matrix(array_a,array_b,row_num,column_num);
    subtraction_matrix(array_a,array_b,row_num,column_num);
    transpose_matrix(array_a,row_num,column_num);
    multiply_matrix(array_a,array_b,row_num,column_num);

    return 0;
}