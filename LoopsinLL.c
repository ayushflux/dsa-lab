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
int floyd_algo(Node **head){
    Node* slow= *head;
    Node* fast = *head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}
int main(){
    Node* head,*save;
    initialize(&head);
    int i=0;
    while(i!=4){
        printf("Select \n1:Insert\n2:Save Insert Address K\n3:Use Saved Address\n4:Exit");
        scanf("%d",&i);
        if(i==1){
        int n;
        printf("\nEnter element to push: ");
        scanf("%d",&n);
        insertEnd(&head,n);
        printf("\n Inserted %d\n",n);
    }else if(i==2){
        int n;
        printf("\nEnter element to push: ");
        scanf("%d",&n);
        insert_save(&head,&save,n);
    }else if(i==3){
        saved_insert(&head,&save);
    }else{
        break;
    }

    }

    if(floyd_algo(&head)){
        printf("\nLoop Detected\n");}else{
            printf("No LOOPs");
        }

}