// making circular linked list using tail pointer
//we can also make this link using tail pointer also
//insertion

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *newnode,*tail;

void create(){
    tail=0;
    int ch=1;
    while(ch){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{                                //using tail instead of temp
            newnode->next=tail->next;          //same working of tail as temp
            tail->next=newnode;
            tail=newnode;
        }
        printf("do u want to continue (0/1): ");
        scanf("%d",&ch);
    }
}


void insert_at_beg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    printf("\nenter data to insert at front: ");
    scanf("%d",&newnode->data);
    if(tail==0){
        tail=newnode;               //if inserted node is first node
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
    }
}


void insert_at_end(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    printf("\nenter data to insert at end: ");
    scanf("%d",&newnode->data);
    if(tail==0){
        tail=newnode;               //if inserted node is first node as last
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;                 
        tail=newnode;                //only this line changes
    }
}


void insert_at_pos(){
    struct node *temp;              //to traversing
    int i=1,pos;                      //make a function to get the length
    printf("\nenter pos: ");
    scanf("%d",&pos);
    if(pos==1){
        insert_at_beg();
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        printf("\nenter data to insert at pos: ");
        scanf("%d",&newnode->data);
        temp=tail->next;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}



void display(){
    struct node *temp;
    temp=tail->next;
    if(tail==0){
        printf("list is empty");
    }
    else{
        while(temp->next!=tail->next){
            printf("%d ",temp->data);
            temp=temp->next;
        } 
        printf("%d",temp->data);              //printing last element
    }
}



int main(){
    create();
    display();              //before insertion
    insert_at_beg();
    display();               //after insertion in beginning
    insert_at_end();
    display();               //after insertion at last
    insert_at_pos();
    display();               //after insertion at pos
    return 0;
}
