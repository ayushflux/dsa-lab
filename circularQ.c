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
int dequeue(Queue *q){
    if(!isEmpty(q)){
        int value=(q->arr)[q->head];
        q->head=(q->head+1)%MAX;
        return value;
    }
    return -1;
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
    int i=0;
    while(i!=4){
        printf("Select \n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            enqueue(&q,n);
            printf("\nEnqueued %d\n",n);
        }else if(i==2){
            int n;
            n=dequeue(&q);
            if(n!=-1){
            printf("\nDequeued Value: %d\n",n);}else{
                printf("Empty Queue");
            }
        }else if(i==3){
            display(&q);
        }else{
            break;
        }
    }
}