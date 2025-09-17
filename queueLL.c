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
    Queue S1;
    initialize(&S1);
    int i=0;
     while(i!=4){
        printf("Select \n1:Push\n2:Pop\n3:Display\n4:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            enqueue(&S1,n);
            printf("\n Enqueued Value %d\n",n);
        }else if(i==2){
            int n;
            n=dequeue(&S1);
            if(n!=-1){
            printf("\nDequeued Value: %d\n",n);}else{
                printf("Empty Queue");
            }
        }else if(i==3){
            display(&S1);
        }
        else {
            break;}
    }
}