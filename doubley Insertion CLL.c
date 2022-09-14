// making doubley circular linked list
// insetion at doubley circular linked list

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


void insert_at_beg(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->prev=0;
    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    if(head==0){
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else{                        //u can also take lines common before 
        newnode->next=head;      //if and else statement
        head->prev=newnode;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
}



void insert_at_end(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->next=0;
    newnode->prev=0;
    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    if(head==0){
        head=tail=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        newnode->prev=tail;
        tail->next=newnode;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
}


void insert_at_any_pos(){           //here pos=1 means begin//pos means after pos+1 and less pos-1
    struct node *temp;               // to traverse
    temp=head;
    int i=1;                      // u can also count the length of LL
    int pos;
    printf("\nenter pos: ");
    scanf("%d",&pos);
    if(pos==1){
        insert_at_beg();
    }
    else{
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=0;
        newnode->prev=0;
        printf("enter data: ");
        scanf("%d",&newnode->data);
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next->prev=newnode;
        temp->next=newnode;
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
    insert_at_beg();
    display();        //display after insertion at beg
    insert_at_end();
    display();       // display after insertion at end
    insert_at_any_pos();
    display();          //after insertion at pos
    return 0;
}
