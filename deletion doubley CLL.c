// making doubley circular linked list
// deletion at doubley circular linked list

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


void delete_at_beg(){
    struct node *temp;
    temp=head;
    if(head==0){
        printf("list is empty");
    }
    else if(head->next==head){              //condition applied when there is only 1 node
        head=tail=0;
        free(temp);
    }
    else{
        head=head->next;
        head->prev=tail;                //in remaining conditions
        tail->next=head;
        free(temp);
    }
}


void delete_at_end(){
    struct node *temp;
    temp=tail;
    if(head==0){
        printf("list is empty");
    }
    else if(head->next==head){              //condition applied when there is only 1 node
        head=tail=0;
        free(temp);
    }
    else{
        tail=tail->prev;
        tail->next=head;               // in remaining conditions
        head->prev=tail;
        free(temp);
    }
}


void delete_from_pos(){              //means if pos=3 means u have to delete 3rd node
    int i=1;
    int pos;                     //there are 3 case 1, last, or invalid 
    struct node *temp;
    temp=head;
    printf("enter pos: ");         // make a function to get the length
    scanf("%d",&pos);
    if(pos<1){
        printf("invalid pos");
    }
    else if(pos==1){
        delete_at_beg();
    }
    else{
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;        //used for deletion
        temp->next->prev=temp->prev;
        if(temp->next==head){
            tail=temp->prev;               // if the delete node id the last node
        }
        free(temp);
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
        printf("\n");
    }
}



int main(){
    create();
    display();
    delete_at_beg();
    display();        //display after insertion at beg
    delete_at_end();
    display();       // display after insertion at end
    delete_from_pos();
    display();          //after insertion at pos
    return 0;
}
