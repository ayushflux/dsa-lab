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

void RotatebyK(Node **head, int k){
    Node* low = *head;
    int l=0;
    if(low==NULL)return;
    while(low!=NULL){
        l+=1;
        low=low->next;
    }
    low = *head;
    int shift=k%l;
    if(k%l){
    for(int i=0;i<shift-1;i++){
        low=low->next;
    }
    Node* save=low;
    while(low->next!=NULL){
        low=low->next;
    }
    low->next=*head;
    *head=save->next;
    save->next=NULL;
}
}
    

void display(Node **q){
    Node* low = (*q);
    printf("The elements are: ");
    while(low!=NULL){
        printf("%d ",low->data);
        low=low->next;
    }
    printf("\n");
}

int main(){
    Node* head;
    initialize(&head);
        int i=0;
    while(i!=4){
        printf("Select \n1:Insert\n2:Rotate by K\n3:Display\n4:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            insert(&head,n);
            printf("\n Inserted %d\n",n);
        }else if(i==2){
            int n;
            printf("\nEnter number of rotations: ");
            scanf("%d",&n);
            RotatebyK(&head, n);
            printf("Rotated by K Linked List: ");
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
    RotatebyK(&head, 4);
    display(&head);

}