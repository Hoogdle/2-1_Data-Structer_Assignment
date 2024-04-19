#include <stdio.h>
#define SIZE 100 // 입력 문자열과 큐의 사이즈는 100으로 제한

// 노서영 교수님께서 수업시간에 말씀하신 '직접 구현 능력의 중요성'에 깊은 감명을 받아 postfix.c를 직접 구현했습니다.
// 강의 노트에 있는 방법과는 조금 다를 수도 있습니다.
// 구현한 알고리즘을 쉽게 나타내기 위해 보고서에 구조도를 첨가했습니다.
// 프로그램은 과제 메뉴얼에 나와 있는대로 'toPostfix(Postfix 변환)'과 'evaluation(연산)'만을 구현하였습니다.
// 프로그램은 toPostfix -> evaluation의 과정을 1번 완료하면 프로그램이 종료되게끔 설계했습니다.

char input[SIZE]; // 중위연산자 저장 배열
char Sub[SIZE]; // infix -> postfix에 도움울 줄 스택
char Main[SIZE]; // 후위 연산자를 저장할 스택
int Operand[SIZE]; // postfix -> eval 에서의 operand들을 저장할 스택

int eval = 0; // Evaluation의 값을 저장할 정수형 변수 eval

int s_top = -1; // Sub 스택의 초기 top을 -1로 초기화
int m_top = -1; // Main 스택의 초기 top을 -1로 초기화
int o_top = -1; // Operand 스택의 초기 top을 -1로 초기화


void s_push(char c){ //Sub 스택 Push 함수
    Sub[++s_top] = c; // s_top을 1 증가시킨 후 매개변수로 받은 문자형 c를 Sub스택에 넣는다.
}
char s_pop(){ //Sub 스택 Pop 함수
    return Sub[s_top--]; // s_top이 가리키는 Sub 스택의 값을 반환한 후 s_top을 1 감소시킨다.
}

void m_push(char c){ //Main 스택 Push 함수
    Main[++m_top] = c; // m_top을 1 증가시킨 후 매개변수로 받은 문자형 c를 Main 스택에 넣는다.
}
char m_pop(){ //Main 스택 Pop 함수
    return Main[m_top--]; // m_top이 가리키는 Main 스택의 값을 반환한 후 m_top을 1 감소시킨다.
}

void o_push(int c){ // Operand 스택 Push 함수
    Operand[++o_top] = c; // o_top을 1 증가시킨 후 매개변수로 받은 문자형 c를 Operand 스택에 넣는다
}
int o_pop(){ // Operand 스택 Pop 함수
    return Operand[o_top--]; // o_top이 가리키는 Operand 스택의 값을 반환한 후 o_top을 1 감소시킨다.
}


// Check 함수
// 중위 연산자로 입력받은 input값에서 후위 연산자 스택인 Main 스택에 값을 넣어주는 함수 
// 중위 연산자 -> 후위 연산자 알고리즘을 따른다.
void Check(){ 
    int i=0; // 중위 연산자 배열 input의 인덱스 데이터 i 선언 및 0으로 초기화
    while(input[i]!='\0'){ // input의 끝을 만나면 반복문을 종료하는걸로 한다.
        if(48<=input[i] && input[i]<=57){ // 아스키 코드로 봤을 때 input이 숫자를 나타내는 문자라면
            m_push(input[i]); // Main 스택에 해당 문자를 바로 Push
        }
        // 숫자를 나타내는 문자가 아니라면
        else if(input[i]=='('){ // '('의 경우에는 우선순위가 가장 높기 때문에 Sub 스택에 바로 Push한다.
            s_push(input[i]);
        }
        else if(input[i]=='*' || input[i]=='/'){ // '*'과 '/'의 경우 Sub스택의 연산자들을 고려해야한다.
            if(s_top==-1){ // 일단 Sub Stack이 비어있다면 바로 추가해준다.
                s_push(input[i]);
            }
            else if(Sub[s_top]=='(') // Sub Stack의 top 값이 ( 라면, 연산자 우선순위로 인해 바로 추가된다.
            s_push(input[i]);
            else if(Sub[s_top]=='*' || Sub[s_top]=='/'){ // Sub stack의 top 값이 '*'이거나 '/'이라면
            // 동일한 우선순위를 가지므로 Sub stack의 top을 pop한 후 input의 연산자를 Sub Stack에 Push 해준다.
                m_push(s_pop());
                s_push(input[i]);
            }
            else if(Sub[s_top]=='+' || Sub[s_top]=='-'){ // Sub stack의 top 값이 '+'이거나 '-'이라면
            // *과 /이 우선순위가 더 높으므로 Sub  Stack에 push 해준다.
                s_push(input[i]);
            }
        }
        else if(input[i]=='+' || input[i]=='-'){ // Input의 연산자가 + 이거나 - 인 경우
            // Sub Stack이 비어있다면 바로 Push 해준다.
            if(s_top==-1){
                s_push(input[i]);
            }
            //  Sub Stack의 Top 값이 ( 라면 연산자 우선순위에 따라 Push 해준다.
            else if(Sub[s_top]=='(')
            s_push(input[i]);
            // Sub Stack의 Top 값이 *이거나 / 라면 연산자 우선순위에 따라 input의 연산자(+ or -)가 바로
            // Main Stack에 Push 된다.
            else if(Sub[s_top]=='*' || Sub[s_top]=='/'){
                m_push(input[i]);
            }
            // Sub Stack의 Top 값이 +이거나 -라면 동일한 연산자 우선순위를 가지므로 Main Stack에 Sub stack의 pop한 값을 넣어주고
            // Sub Stack에는 Input의 값을 push 해준다.
            else if(Sub[s_top]=='+' || Sub[s_top]=='-'){
                m_push(s_pop());
                s_push(input[i]);
            }
        }
        // Input의 값이 ) 인경우 Sub stack에서 '('이 나오기 전까지 존재하는 모든 연산자들을 pop 해준다.
        else if(input[i]==')'){
            while(Sub[s_top]!='('){
                m_push(s_pop());
            }
            s_pop(); // while문을 거치면 ( 이 남게되므로 한 번더 pop 해준다.
        }
        ++i; // input의 인덱스를 증가시킨다.
    }
}

void End_Check(){ // Sub Stack에 남은 모든 연산자를 pop 시켜주는 함수
    while(s_top!=-1){  // input의 모든 데이터를 읽었음에도 Sub Stack에 연산자가 남는 경우가 발생할 수 있다.
    // 이를 방지하기 위해 위의 Check 함수를 진행한 후 Sub Stack에 존재하는 모든 연산자를 pop 시켜준다.
        m_push(s_pop());
    }
}

// 위에서 사용한 Push and Pop의 메커니즘을 그대로 이용하기 위해 
// Main Stack을 역전시켜줍니다.
// 추가설명 : Pop연산은 최상위 인덱스 top 에서 일어나는데 Main Stack의 데이터는 초기 인덱스부터 갖고와야 하기 때문
void Reverse(){
    for(int i=0;i<=m_top/2;++i){ //Main의 중간에 해당하는 데이터까지 반복문을 실행
        char temp; // 값 변환을 위한 임의의 변수 temp
        int index = m_top-i; // 값 변환을 위해 인덱스 지정
        // 값 변환
        temp = Main[i];
        Main[i] = Main[index];
        Main[index] = temp;
    }
}

// 순서가 역전된 Main 스택을 이용하여 Eval을 진행한다.
void Eval(){
    int put; // Operand 스택에 넣을 데이터 put
    int op1,op2; // Operand 스택에서 꺼내올 데이터 op1, op2
    char op; // Main 연산자에서 꺼내온 연산자 op
    while(m_top!=-1){ // Main 연산자의 데이터를 모두 읽을 때 까지 반복문을 진행한다.
        if(48<=Main[m_top] && Main[m_top]<=57){ // Main Stack에서의 top 데이터가 숫자를 가리키는 문자형인 경우
            put = m_pop()-48; // Main에서 top인덱스의 데이터를 pop한 후 0의 아스키코드로 뺄셈을 시켜 숫자 문자형을 정수 숫자형 데이터로 변환해준다.
            o_push(put); //Operand 스택에 put데이터를 push
            continue; // 다음 반복으로 진행
        }
        else{ // Operand Stack의 top index 데이터가 연산자인 경우
            op1 = o_pop(); // Operand stack에서 데이터를 pop하여 op1에 저장
            op2 = o_pop(); // Operand stack에서 데이터를 pop하여 op2에 저장
            op = m_pop(); // Main Satck에서 연산자 데이터를 pop하여 op에 저장
            if(op=='*'){ // op가 *인 경우 op1*op2의 결과를 Operand Stack에 push 해준다.
                o_push(op1*op2);
                continue;
            }
            else if(op=='/'){ // op가 /인 경우 op1/op2의 결과를 Operand Stack에 push 해준다.
                o_push(op1/op2);
                continue;
            }
            else if(op=='+'){ // op가 +인 경우 op1+op2의 결과를 Operand Stack에 push 해준다.
                o_push(op1+op2);
            }
            else if(op=='-'){ // op가 -인 경우 op1-op2의 결과를 Operand Stack에 push 해준다.
                o_push(op1-op2);
            }
        }
    }
    // 위 과정을 거치면 Operand 스택에는 연산의 결과만이 남게된다. 해당 결과를 얻기위해 Operand를 pop한 후 eval 변수에 값을 넣어준다.
    eval = o_pop(); 
}


// 사용자의 입력 문자에 따라 실행 동작을 정의할 System 함수
void System(char c){
    if(c=='C'){ // 입력 문자가 C인 경우 Infix -> Postfix 과정을 실행한다.
        printf("Infix : ");
        scanf("%s",input); // input 문자열에 입력받은 Infix 데이터를 저장
        Check(); // Check 함수 실행
        End_Check(); // End_Check 함수 실행
        // Check() 와 End_Check() 함수의 결과로 Main Stack에는 Postfix 표현이 저장되게 된다.
        // printf("m_top : %d",m_top);
        
        // Postfix 표현 출력
        printf("Postfix : ");
        for(int i=0;i<=m_top;++i){
            printf("%c",Main[i]);
        }
        printf("\n");
    }
    else if(c=='E'){ // 입력 문자가 E인경우 Evaluation을 진행
        printf("Eval : ");
        Reverse(); // Evaluation을 위해 Main Stack을 역전시킨다.
        Eval(); // Evaluation 진행, eval값에 연산의 결과가 저장되게 된다.

        // 연산의 결과 출력
        printf("Evaluation Value : ");
        printf("%d\n",eval);
        printf("\n");
        
    }

}

void Manual(){
    while(1){
        printf("Infix -> Postfix Program(Please insert the command following beleow)\n");
        printf("Command Sequence is C -> E\n");
        char c; // Command를 입력받을 문자형 변수 c
        printf("============================================\n");
        printf("               postfix program              \n");
        printf("============================================\n");
        printf("C : Convert Infix to Postfix\n");
        printf("E : Get the value of calculation\n");
        printf("Command : ");
        scanf(" %c",&c); // Command를 입력 받는다.
    
        System(c); // 입력받은 Command를 System의 매개변수로 넣어준다.
        printf("\n");
        if(c=='E'){ // 프로그램은 단 한 번의 연산 후 종료하게끔 설계했습니다.
            return;
        }
    }
}
 
int main(){
	printf("[----- [김태영] [2023041012] -----]\n");
    Manual(); // Manual함수 실행
}