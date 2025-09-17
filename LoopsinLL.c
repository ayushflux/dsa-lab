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
void saved_insert(Node** head, Node** save){
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
void floyd_algo(Node **head){
    Node* slow= *head;
    Node* fast = *head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast){
            printf("Looping Linked List");
            return;
        }
    }
    printf("NO LOOP");
    display(head);
    return;
}
int main(){
    Node* head,*save;
    initialize(&head);
    insert(&head,1);
    insert_save(&head,&save,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    saved_insert(&head,&save);
    floyd_algo(&head);

}