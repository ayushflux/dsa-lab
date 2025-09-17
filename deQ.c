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
int deleteFront(Queue *q){
    if(!isEmpty(q)){
        int value = (q->arr)[q->head];
        q->head=(q->head+1)%MAX;
        return value;
    }
    return -1;
}
int deleteRear(Queue *q){
    if(!isEmpty(q)){
        int value = (q->arr)[q->rear];
        q->rear=(q->rear+MAX-1)%MAX;
        return value;
    }
    return -1;
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
    int i=0;
    while(i!=6){
        printf("Select \n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Display\n6:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            insertFront(&q,n);
            printf("\nPUSHED\n");
        }else if(i==2){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            insertRear(&q,n);
            printf("\nPUSHED\n");
        }else if(i==3){
            int n;
            n=deleteFront(&q);
            if(n!=-1){
            printf("\nDequeued Value: %d\n",n);}else{
                printf("Empty Queue");
            }
        }else if(i==4){
            int n;
            n=deleteRear(&q);
            if(n!=-1){
            printf("\nDequeued Value: %d\n",n);}else{
                printf("Empty Queue");
            }
        }else if(i==5){
            display(&q);
        }else{
            break;
        }
    }

}