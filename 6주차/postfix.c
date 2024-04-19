#include <stdio.h>
#define SIZE 100

// main stack
// sub stack

char input[SIZE];
char Sub[SIZE]; // sub 스택
char Main[SIZE]; // main 스택
int Operand[SIZE]; // postfix -> eval

int eval = 0;

int s_top = -1;
int m_top = -1;
int o_top = -1;


void s_push(char c){
    Sub[++s_top] = c;
}
char s_pop(){
    return Sub[s_top--];
}

void m_push(char c){
    Main[++m_top] = c;
}
char m_pop(){
    return Main[m_top--];
}

void o_push(int c){
    Operand[++o_top] = c;
}
int o_pop(){
    return Operand[o_top--];
}

void Check(){ // check Operator
    int i=0;
    while(input[i]!='\0'){
        if(48<=input[i] && input[i]<=57){
            m_push(input[i]);
        }
        else if(input[i]=='('){
            s_push(input[i]);
        }
        else if(input[i]=='*' || input[i]=='/'){
            if(s_top==-1){
                s_push(input[i]);
            }
            else if(Sub[s_top]=='(')
            s_push(input[i]);
            else if(Sub[s_top]=='*' || Sub[s_top]=='/'){
                m_push(s_pop());
                s_push(input[i]);
            }
            else if(Sub[s_top]=='+' || Sub[s_top]=='-'){
                s_push(input[i]);
            }
        }
        else if(input[i]=='+' || input[i]=='-'){
            if(s_top==-1){
                s_push(input[i]);
            }
            else if(Sub[s_top]=='(')
            s_push(input[i]);
            else if(Sub[s_top]=='*' || Sub[s_top]=='/'){
                m_push(input[i]);
            }
            else if(Sub[s_top]=='+' || Sub[s_top]=='-'){
                m_push(s_pop());
                s_push(input[i]);
            }
        }
        else if(input[i]==')'){
            while(Sub[s_top]!='('){
                m_push(s_pop());
            }
            s_pop();
        }
        ++i;
    }
}

void End_Check(){ // for finishing check
    while(s_top!=-1){
        m_push(s_pop());
    }
}


void Reverse(){
    for(int i=0;i<=m_top/2;++i){
        char temp;
        int index = m_top-i;
        temp = Main[i];
        Main[i] = Main[index];
        Main[index] = temp;
    }
}

void Eval(){
    int put;
    int op1,op2;
    char op;
    while(m_top!=-1){
        if(48<=Main[m_top] && Main[m_top]<=57){
            put = m_pop()-48;
            o_push(put);
            continue;
        }
        else{
            op1 = o_pop();
            op2 = o_pop();
            op = m_pop();
            if(op=='*'){
                o_push(op1*op2);
                continue;
            }
            else if(op=='/'){
                o_push(op1/op2);
                continue;
            }
            else if(op=='+'){
                o_push(op1+op2);
            }
            else if(op=='-'){
                o_push(op1-op2);
            }
        }
    }
    eval = o_pop();
}


void System(char c){
    if(c=='C'){
        printf("Infix : ");
        scanf("%s",input);
        Check();
        End_Check();
        // printf("m_top : %d",m_top);
        printf("Postfix : ");
        for(int i=0;i<=m_top;++i){
            printf("%c",Main[i]);
        }
        printf("\n");
    }
    else if(c=='E'){
        printf("Eval : ");
        Reverse();
        // printf("Reversed : ");
        // for(int i=0;i<=m_top;++i){
        //     printf("%c",Main[i]);
        // }
        Eval();
        // printf("o_top : ");
        // printf("%d\n",o_top);   
        printf("Evaluation Value : ");
        printf("%d\n",eval);
        printf("\n");
        
    }

}

void Manual(){
    while(1){
        printf("Infix -> Postfix Program(Please insert the command following beleow)\n");
        printf("Command Sequence is C -> E\n");
        char c;
        printf("============================================\n");
        printf("               postfix program              \n");
        printf("============================================\n");
        printf("C : Convert Infix to Postfix\n");
        printf("E : Get the value of calculation\n");
        printf("Command : ");
        scanf(" %c",&c);
    
        System(c);
        printf("\n");
        if(c=='E'){
            return;
        }
    }
}
 
int main(){
    Manual();
}