// making circular linked list using tail pointer
//we can also make this link using tail pointer also
//deletion

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


void delete_at_beg(){
    struct node *temp;
    temp=tail->next;
    if(tail==0){
        printf("list is empty");
    }
    else if(temp->next==temp){
        tail=0;                       //only 1 element is list
        free(temp);
    }
    else{
        tail->next=temp->next;       // for more elements in list
        free(temp);
    }
    
}

          
void delete_at_end(){
    struct node *temp, *previous;
    temp=tail->next;            //we need two pointers 1 for delete and 1 for free
    if(tail==0){
        printf("list is empty");
    }
    else if(temp->next==temp){
        tail=0;                       //only 1 element is list
        free(temp);
    }
    else{
        while(temp->next!=tail->next){           //previous is used to assign address for tailk
            previous=temp;
            temp=temp->next;                     //temp is used to delete node
        }
        previous->next=tail->next;
        tail=previous;
        free(temp);
    }
}


void delete_from_pos(){            //means delete data of that pos
    struct node *temp, *current;
    current=tail->next;
    int i=1;
    int pos;
    printf("\nenter pos: ");
    scanf("%d",&pos);
    if(pos<0){
        printf("position is invalid");            //u have to write get length function
    }
    else if(pos==1){
        delete_at_beg();
    }
    else{
        while(i<pos-1){
            current=current->next;
        }
        temp=current->next;
        current->next=temp->next;
        free(temp);
    }
    
    
}

void display(){
    struct node *temp;
    temp=tail->next;
    if(tail==0){
        printf("list is empty");
    }
    else{
        printf("\n");
        while(temp->next!=tail->next){
            printf("%d ",temp->data);
            temp=temp->next;
        } 
        printf("%d",temp->data);              //printing last element
    }
}



int main(){
    create();
    display();              //before deletion
    delete_at_beg();
    display();               //after deletion in beginning
    delete_at_end();
    display();               //after deletion at last
    delete_from_pos();
    display();               //after deletion from pos
    return 0;
}
