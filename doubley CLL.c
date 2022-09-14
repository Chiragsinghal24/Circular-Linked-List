// making doubley circular linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node*next;
};
struct node *head,*tail;


void create(){
    head=0;
    struct node*newnode;
    int ch;
    printf("enter choice: ");
    scanf("%d",&ch);
    while(ch){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        newnode->prev=0;
        printf("enter data: ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;        //to make doubley circular linked list
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;                //tail->next->data to check circularity
        }
        printf("enter the choice (0/1): ");
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
        while(temp!=tail){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}



int main(){
    create();
    display();
    return 0;
}
