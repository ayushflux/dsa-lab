#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* before;
};

typedef struct Node Node;

void push(Node** current, int key){
    Node* nxt=(Node *)calloc(1,sizeof(Node));
    nxt->before=(*current);
    nxt->data=key;
    nxt->next=NULL;
    *(current)=nxt;
    return;
}
int pop(Node** current){
    if(*current!=NULL){
    Node* bef=(*current)->before;
    int value=(*current)->data;
    free(*current);
    bef->next=NULL;
    *(current)=bef;
    return value;}
    return -1;
}
int peek(Node **current){
    if(*current==NULL){
        return -1;
    }
    return (*current)->data;
}
void display(Node *current){
    printf("Elements are: ");
    while(current!=NULL){
        printf("%d ",current->data);
        current=current->before;
    }
}

int main(){
    Node *S1=NULL;
    int i=0;
     while(i!=4){
        printf("Select \n1:Push\n2:Pop\n3:Display\n4:Exit");
        scanf("%d",&i);
        if(i==1){
            int n;
            printf("\nEnter element to push: ");
            scanf("%d",&n);
            push(&S1,n);
            printf("\nPUSHED %d\n",n);
        }else if(i==2){
            int n;
            n=pop(&S1);
            if(n!=-1){
            printf("\nPopped Value: %d\n",n);}else{
                printf("Empty Queue");
            }
        }else if(i==3){
            display(&S1);
        }
        else {
            break;}
    }

}