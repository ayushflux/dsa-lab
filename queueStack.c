#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    int top;
    int size;
    int st[MAX];
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
int stack_top(Stack *S){
    if(!stack_empty(S)){
        return S->st[S->top];
    }
}

void enqueue(Stack *S1, Stack *S2, int key){
    stack_push(S1,key);
}

int dequeue(Stack *S1, Stack *S2){
    int n=0;
    while (!stack_empty(S1))
    {
        n+=1;
        stack_push(S2,stack_pop(S1));
    }
    int value=stack_pop(S2);
    n--;
    while(n--){
        stack_push(S1,stack_pop(S2));
    }
    return value;   
}

int main(){
    Stack S1,S2;
    stack_init(&S1);
    stack_init(&S2);
    enqueue(&S1,&S2,10);
    enqueue(&S1,&S2,20);
    enqueue(&S1, &S2,30);
}