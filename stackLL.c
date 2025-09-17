#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* before;
};

typedef struct Node Node;

void push(Node** current, int key){
    Node* nxt=(Node *)calloc(1,sizeof(Node));
    nxt->before=(*current);
    nxt->data=key;
    nxt->next=NULL;
    *(current)=nxt;
    return;
}
int pop(Node** current){
    if(*current!=NULL){
    Node* bef=(*current)->before;
    int value=(*current)->data;
    free(*current);
    bef->next=NULL;
    *(current)=bef;
    return value;}
    return -1;
}
int peek(Node **current){
    if(*current==NULL){
        return -1;
    }
    return (*current)->data;
}
void display(Node *current){
    printf("Elements are: ");
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->before;
    }
}

int main(){
    Node *n=NULL;
    push(&n,10);
    push(&n,20);
    push(&n,30);
    printf("%d\n",pop(&n));
    display(n);
}