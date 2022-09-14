//circular singley linked list;

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head,*newnode;

void create(){
    struct node *temp;
    head=0;
    int ch=1;
    while(ch){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;                         // u can also use tail instead of temp it is also ok
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
        printf("do u want to continue (0/1): ");
        scanf("%d",&ch);
    }
}


void display(){
    struct node *temp;
    temp=head;
    if(head==0){
        printf("list is empty");
    }
    else{
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);                      // to display the last element
    }
}



int main(){
    create();
    display();
    return 0;
}
