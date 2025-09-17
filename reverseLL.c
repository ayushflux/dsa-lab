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

void reverse(Node **head){
    Node* curr = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}

void display(Node **q){
    Node* low = (*q);
    printf("The elements are: ");
    while(low!=NULL){
        printf("%d ",low->data);
        low=low->next;
    }
}

int main(){
    Node* head;
    initialize(&head);
    int i=0;
    while(i!=3){
        printf("Select \n1:Insert\n2:Reverse Linked List\n3:Display\n4:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            insert(&head,n);
            printf("\n Inserted %d\n",n);
        }else if(i==2){
            reverse(&head);
            printf("Reversed Linked List: ");
            display(&head);
        }else if(i==3){
            printf("Linked List: ");
            display(&head);
        }
        else {
            break;}
    }
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    display(&head);
    reverse(&head);
    display(&head);

}