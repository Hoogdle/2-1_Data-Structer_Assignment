#include <stdio.h>
#include <stdlib.h>


// 객체 지향 프로그래밍을 연습하기 위해 과제에서 요구하는 함수를 포함한 추가적인 함수를 만들었습니다.


//*****************************************************************************************
// 문제에서 행렬 A와 B가 정사각 행렬을 가정하는 것인지 모르겠습니다. 서로 다른 크기의 행과 열을 가진다면 Add,Sub 함수가 적용이 안 될것이고 행렬의 곱셈은 A의 열과 B의 행이 일치할 때만 가능할 텐데
// 문제에서는 이에 대한 아무런 언급이 없어 모든 연산이 가능한 정사각 행렬을 가정하고 코드를 작성하였습니다.

// 문제에서 요구하는 것은 A와 B의 연산이고 연산의 결과를 print_matrix로 출력하라고 요구하는데 문제에서 제시한 print_matrix() 함수는 A와 B의 행렬을 출력하는 함수이지
// '연산 결과'를 출력하는 함수는 아니라고 생각됩니다. 연산의 결과를 A 행렬에 저장하거나 B 행렬에 저장하라는 말이 명시되어 있지 않아 연산의 결과를 출력해주는 함수'printer'를 임의로 만들었습니다.
// 문제에서 요구하는 A와 B를 출력하는 함수도 구현했으나 연산의 결과는 printer()로 출력하였습니다. 제가 문제의 의도를 잘못 파악한거라면 죄송합니다!
//*****************************************************************************************




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


    printf("[----- [김태영] [2023041012] -----]\n");
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

// 행렬 출력을 간단히 하기 위한 보조함수 printer
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
void additon_matrix(int **array_a, int ** array_b,int row,int col){ // 함수의 매개변수로 이중 포인터 변수인 행렬 A와 행렬 B를 받고 행과 열의 크기를 받습니다.
    int **temp = make_array(row,col); // 새로운 이중 포인터 temp를 행렬 생성함수 make_array로 초기화 합니다.
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j) // 열을 탐색하기 위한 for문
            temp[i][j] = array_a[i][j] + array_b[i][j]; // 행렬의 각각의 요소의 서로 동일한 인덱스를 공유하는 요소와 더합니다. 그 결과를 2차원 배열 temp에 저장합니다.
        } 
    printf("-----------------------------------------------------\n");
    printf("Result of Add\n");
    printer(temp,row,col); // printer() 로 2차원 배열 temp를 출력합니다.
    printf("-----------------------------------------------------\n");
    free(temp); // 동적 메모리할당 된 temp를 메모리 해지합니다.
}
/////////////////////////////////////////////////////////////////////////

///////////////// (f) subtraction_matrix 구현 /////////////////
void subtraction_matrix(int **array_a, int ** array_b,int row,int col){ //함수의 매개변수로 이중 포인터 변수인 행렬 A와 행렬 B를 받고 행과 열의 크기를 받습니다.
    int **temp = make_array(row,col); // 새로운 이중 포인터 temp를 행렬 생성함수 make_array로 초기화 합니다.
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j) // 열을 탐색하기 위한 for문
            temp[i][j] = array_a[i][j] - array_b[i][j]; // 행렬의 각각의 요소의 서로 동일한 인덱스를 공유하는 요소와 -연산을 합니다. 그 결과를 2차원 배열 temp에 저장합니다.
     }
    printf("-----------------------------------------------------\n");
    printf("Result of Sub\n");
    printer(temp,row,col); // printer() 로 2차원 배열 temp를 출력합니다.
    printf("-----------------------------------------------------\n");
    free(temp); // 동적 메모리할당 된 temp를 메모리 해지합니다.
}
/////////////////////////////////////////////////////////////////////////

///////////////// (g) transpose_matrix 구현 /////////////////
void transpose_matrix(int **array,int row,int col){ // 이중 포인터 변수 1개(행렬 A)와 행과 열의 값을 매개변수로 받습니다.
    int **temp = make_array(col,row); // 새로운 이중 포인터 temp를 행렬 생성함수 make_array로 초기화 합니다.
    for (int i=0;i<row;++i){ // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j) // 열을 탐색하기 위한 for문
            temp[j][i] = array[i][j]; // 행렬 A의 행과 열의 요소를 열->행 순으로 temp에 넣어줍니다.
    }
    printf("-----------------------------------------------------\n");
    printf("Result of Transpose of A\n");
    printer(temp,col,row); //printer() 로 2차원 배열 temp를 출력합니다. // transpose이기에 행과 열의 차원이 바뀝니다.
    printf("-----------------------------------------------------\n");
    free(temp); // 동적 메모리할당 된 temp를 메모리 해지합니다.
}
/////////////////////////////////////////////////////////////////////////

///////////////// (h) multiply_matrix 구현 /////////////////
void multiply_matrix(int **array_a, int ** array_b,int row,int col){ // 매개변수로 이중 포인터 변수 두개와 행과 열의 값을 받습니다.
    int **temp = make_array(row,col); // 새로운 이중 포인터 temp를 행렬 생성함수 make_array로 초기화 합니다.
    for (int i=0;i<row;++i){  // 행을 탐색하기 위한 for문
        for (int j=0;j<col;++j){ // 열을 탐색하기 위한 for문
            int value = 0; // 행렬의 곱 연산에서 각 원소의 곱을 저장할 변수 value
            for (int k=0;k<col;++k){ // 열의 갯수만 큼 k를 반복
            value += array_a[i][k] * array_b[k][j]; // i와 j를 고정했을 때 k를 a에서는 수평방향 b에서는 수직방향으로 움직이게 하여 행렬의 곱셈 연산을 구현 하였습니다.
            }
            temp[i][j] = value; // 곱의 결과를 2차원 배열 temp에 저장
        }
    }
    printf("-----------------------------------------------------\n");
    printf("Result of Mul\n");
    printer(temp,row,col); //printer() 로 2차원 배열 temp를 출력합니다. 
    printf("-----------------------------------------------------\n");
    free(temp); // 동적 메모리할당 된 temp를 메모리 해지합니다.
}
/////////////////////////////////////////////////////////////////////////


///////////////// (j) 메모리 해제 함수 /////////////////
void free_matrix(int **array){ // 매개변수로 이중 포인터를 받습니다.
    free(array); // free 함수로 동적할당 된 array를 해지합니다.
}
/////////////////////////////////////////////////////////////////////////


int main(){
    my_info();
    ///////////////// (a) 행렬 A와 B의 행과 열의 값을 입력 받는다. /////////////////
    int row_num,column_num; // 행렬의 행과 열의 갯수 변수
    scanf("%d %d",&row_num,&column_num); // 행렬 A의 행과 열의 갯수 입력 받기
    /////////////////////////////////////////////////////////////////////////

    int **array_a = make_array(row_num,column_num); // make_array 함수로 입력 받은 행과 열의 크기만큼의 A행렬 생성
    int **array_b = make_array(row_num,column_num); // make_array 함수로 입력 받은 행과 열의 크기만큼의 B행렬 생성

    put_random(array_a,row_num,column_num); // put_random 함수로 A행렬을 랜덤값으로 초기화
    put_random(array_b,row_num,column_num); // put_random 함수로 B행렬을 랜덤값으로 초기화


    print_matrix(array_a,array_b,row_num,column_num); // A행렬과 B행렬을 출력합니다.
    additon_matrix(array_a,array_b,row_num,column_num); // A행렬과 B행렬의 덧셈 결과를 출력합니다.
    subtraction_matrix(array_a,array_b,row_num,column_num); // A행렬과 B행렬의 -연산 결과를 출력합니다.
    transpose_matrix(array_a,row_num,column_num); // A행렬의 전치 행렬을 출력합니다.
    multiply_matrix(array_a,array_b,row_num,column_num); // A행렬과 B행렬의 곱의 결과를 출력합니다.

    free_matrix(array_a); // 동적 메모리 할당된 A행렬을 메모리 해지합니다.
    free_matrix(array_b); // 동적 메모리 할당된 B행렬을 메모리 해지합니다.

    return 0;
}