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

void insertEnd(Node** head, int key){
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

int getMiddle(Node** head){
    Node* fst= *head;
    Node* sec= *head;
    while(sec!=NULL&&sec->next!=NULL){
        fst=fst->next;
        sec=(sec->next)->next;

    }
    return fst->data;
}

int main(){
    Node* S1;
    initialize(&S1);
    int i=0;
     while(i!=3){
        printf("Select \n1:Insert\n2:Find Middle Element\n3:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            insertEnd(&S1,n);
            printf("\n Inserted %d\n",n);
        }else if(i==2){
            printf("%d",getMiddle(&S1));
        }
        else {
            break;}
    }


}