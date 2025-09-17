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
    return(((q->rear)+1)%MAX==q->head);
}

void insertRear(Queue *q, int k){
    if(!isFull(q)){
        q->rear=(q->rear+1)%MAX;
        (q->arr)[q->rear]=k;
    }else{
        printf("FULL");
    }

}
void insertFront(Queue *q, int k){
    if(!isFull(q)){
        (q->arr)[q->head]=k;
        q->head=(q->head+MAX-1)%MAX;
    }else{
        printf("FULL");
    }

}
void deleteFront(Queue *q){
    if(!isEmpty(q)){
        q->head=(q->head+1)%MAX;
    }
}
void deleteRear(Queue *q){
    if(!isEmpty(q)){
        q->rear=(q->rear+MAX-1)%MAX;
    }
}

void display(Queue *q){
    int low=((q->head)+1)%MAX;
    int high=q->rear;
    if(!isEmpty(q)){
        printf("Elements are: ");
        while(low!=(high+1)%MAX){
            printf("%d ",(q->arr)[low]);
            low=(low+1)%MAX;
        }
    }
}

int main(){
    Queue q;
    initialize(&q);
    insertRear(&q,10);
    insertRear(&q,20);
    insertFront(&q,5);
    deleteRear(&q);
    insertFront(&q,15);
    display(&q);
}