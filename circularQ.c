#include <stdio.h>
#define MAX 100

typedef struct{
    int arr[100];
    int head;
    int rear;   
}Queue;

void initialize(Queue *q){
    q->head=0;
    q->rear=0;
}

int isEmpty(Queue *q){
    return(q->head==q->rear);
}

int isFull(Queue *q){
    return((q->rear)+1==q->head);
}

void enqueue(Queue *q, int k){
    if(!isFull(q)){
        q->rear=(q->rear+1)%MAX;
        (q->arr)[q->rear]=k;
    }else{
        printf("FULL");
    }

}
void dequeue(Queue *q){
    if(!isEmpty(q)){
        q->head=(q->head+1)%MAX;
    }
}

void display(Queue *q){
    int low=(q->head)+1;
    int high=q->rear;
    while(low<=high){
        printf("%d ",q->arr[low]);
        low++;
    }
}

int main(){
    Queue q;
    initialize(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    dequeue(&q);
    enqueue(&q,40);
    dequeue(&q);
    dequeue(&q);
    display(&q);
}