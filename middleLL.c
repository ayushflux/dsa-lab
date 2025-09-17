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
    Node* head;
    initialize(&head);
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    insertEnd(&head, 60);
    printf("%d",getMiddle(&head));

}