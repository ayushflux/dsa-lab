#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

void initialize(Node** curr){
    *curr=NULL;
}

void insert(Node** head, int key){
    Node* next = (Node *)calloc(1,sizeof(Node));
    next->data=key;
    next->next=NULL;
    if(*head==NULL){
        *head=next;
    }else{
        Node* low= *head;
        while(low->next!=NULL){
            low=low->next;
        }
        low->next=next;
    }
}
void insert_save(Node** head, Node** save, int key){
    Node* next = (Node *)calloc(1,sizeof(Node));
    next->data=key;
    next->next=NULL;
    if(*head==NULL){
        *head=next;
    }else{
        Node* low= *head;
        while(low->next!=NULL){
            low=low->next;
        }
        low->next=next;
    }
    *save=next;
}
void attach(Node** head, Node** save){
    Node* next = *save;
    if(*head==NULL){
        *head=next;
    }else{
        Node* low= *head;
        while(low->next!=NULL){
            low=low->next;
        }
        low->next=next;
    }
}

void display(Node **q){
    Node* low = (*q);
    printf("The elements are: ");
    while(low!=NULL){
        printf("%d ",low->data);
        low=low->next;
    }
}

void intersection(Node **q1, Node **q2){
    Node* l1=*q1;
    Node* l2=*q2;
    int m=0;
    int n=0;
    while(l1!=NULL){
        m+=1;
        l1=(l1)->next;
    }
    while(l2!=NULL){
        n+=1;
        l2=(l2)->next;
    }
    l1=*q1;
    l2=*q2;
    if(n>m){
        for(int i=0;i<n-m;i++){
            l2=l2->next;
        }
    }else{
        for(int i=0;i<m-n;i++){
            l1=l1->next;
        }
    }
    while(!(l1==NULL||l2==NULL)){
        if(l1==l2){
            printf("Intersecting at %d\n", l2->data);
            return;
        }
        l1=l1->next;
        l2=l2->next;
    }
    printf("Not Intersecting\n");
    return;

}
int main(){
    Node* q1,*q2,*cm,*save;
    initialize(&q1);
    initialize(&q2);
    initialize(&cm);
    int i=0;
    while(i!=6){
        printf("Select \n1:Insert to First Queue \n2:Insert to Second Queue K\n3:Insert to Common Tail\n4:Attach Common Tail to Both Queues\n5:Find Intersection Point\6:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            insert(&q1,n);
            printf("\n Enqueued Value %d\n",n);
        }else if(i==2){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            enqueue(&q2,n);
            printf("\n Enqueued Value %d\n",n);
        }else if(i==3){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            enqueue(&cm,n);
            printf("\n Enqueued Value %d\n",n);
        }else if(i==4){
            attach(&q1,&cm);
            attach(&q2,&cm);
        }else if(i==5){
            intersection(&q1,&q2);
        }else{
            break;
        }
    }

}