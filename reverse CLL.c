// making circular linked list using tail pointer
//we can also make this link using tail pointer also
// we can also reverse the link


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


void reverse(){
    struct node *current, *prev, *nextnode;
    current=tail->next;
    if(tail==0){
        printf("list is empty");
    }
    else{
        while(current!=tail){
            prev=current;
            current=nextnode;
            nextnode=current->next;
            current->next=prev;
        }
        nextnode->next=tail;
        tail=nextnode;
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
    display();        // before reversing the list     
    reverse();
    display();        // after reversing the list
    return 0;
}
