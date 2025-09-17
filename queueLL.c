#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

typedef struct{
    Node* head;
    Node* tail;
}Queue;

void initialize(Queue *q){
    q->head = NULL;
    q->tail = NULL;
};

void enqueue(Queue *q, int key){
    Node* next = (Node *)calloc(1,sizeof(Node));
    if(q->head==NULL && q->tail==NULL){
        q->head=next;
        q->tail=next;
    }else{
    ((q->tail)->next)=next;
    q->tail=next;}
    ((q->tail))->data=key;
    ((q->tail))->next=NULL;
}

int dequeue(Queue *q){
    if((q->head)!=NULL){
    int value = (q->head)->data;
    q->head=(q->head)->next;
    return value;
    }else{
        return -1;
    }
}

int peek(Queue *q){
    if((q->head)!=NULL){
    return (q->head)->data;
    }else{
        return -1;
    }
}

void display(Queue *q){
    Node* low = q->head;
    printf("The elements are: ");
    while(low!=NULL){
        printf("%d ",low->data);
        low=low->next;
    }
}

int main(){
    Queue q;
    initialize(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    dequeue(&q);
    display(&q);
}