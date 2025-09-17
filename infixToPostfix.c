#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    int top;
    int size;
    char st[MAX];
}Stack;

void stack_init(Stack *S){
    S->top=-1;
    S->size=0;
}
int stack_full(Stack *S){
    return S->size==MAX;
}
int stack_empty(Stack *S){
    return S->size==0;
}
char stack_pop(Stack *S){
    if(!stack_empty(S)){
        S->size-=1;
        return S->st[S->top--];
    }
}
void stack_push(Stack *S, int num){
    if(!stack_full(S)){
        S->st[++S->top]=num;
        S->size++;
    }
}
char stack_top(Stack *S){
    if(!stack_empty(S)){
        return S->st[S->top];
    }
}


int prec(char a, char b){
    int val_a;
    int val_b;
    switch (a)
    {
    case ('+'):val_a=1; break;
    case ('-'):val_a=1; break;
    case('*'): val_a=2; break; 
    case('/'): val_a=2;break;
    case ('^'):val_a=3;break;
    case ('('):val_a=0;break;
    default:break;
    }
    switch (b)
    {
    case ('+'): val_b=1;break;
    case ('-'): val_b=1; break;
    case('*'): val_b=2; break; 
    case('/'):val_b=2;break;
    case ('^'):val_b=3;break;
    case ('('): val_b=0;break;
    default: break;
    }
    return val_a-val_b;
}

int main(){ 
    printf("Enter your infix string");
    char infix[MAX];
    scanf("%s",infix);
    char postfix[(int)strlen(infix)];
    Stack op;
    stack_init(&op);
    int i=0;
    int count=0;
    while(i<(int)strlen(infix)){
        char c = infix[i];
        if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
            if(stack_empty(&op))stack_push(&op,c);
            else{
                if(prec(c,stack_top(&op))>0)stack_push(&op, c);
                else{
                    if(c!='^'){
                        while(!stack_empty(&op) && prec(c,stack_top(&op))<=0){
                            postfix[count++]=stack_pop(&op);
                        }
                        stack_push(&op, c);
                    }else{
                        while(!stack_empty(&op) && prec(c,stack_top(&op))<0){
                            postfix[count++]=stack_pop(&op);
                        }
                        stack_push(&op, c);
                    }

                }
            }
        }else if(c=='('){
            stack_push(&op,c);
        }else if(c==')'){
            char popped=stack_pop(&op);
            while(popped!='('){
                postfix[count++]=popped;
                popped=stack_pop(&op);
            }
        }else{
            postfix[count++]=c;
        }
        i++;
    }
    while(!stack_empty(&op)){
        postfix[count++]=stack_pop(&op);
    }
    postfix[count]='\0';
    printf("%s",postfix);
}