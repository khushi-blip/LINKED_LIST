#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node*prev;
    int data;
    struct node*next;
};
struct node*temp,*head;
void creationdoubly();//prototype
struct node* creationdoublylist();//prototype
void insertatfrontdoubly();
void insertatenddoubly();
void insertatmid();
void deletefront();
struct node* creationdoublylist()//node created kyuki baar baar ye line likhni na pde
{
    struct node*newnode;
    newnode=(struct node*)malloc(1*sizeof(struct node));
    int value;
    printf("enter the value:\n");
    scanf("%d",&value);
    newnode->prev=NULL;
    newnode->data=value;
  
    newnode->next=NULL;

    return newnode;
}

void creationdoubly(){//normal creation function
    struct node*newnode=creationdoublylist();
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
}


void reverselist()
{
    struct node*temp=head;
    if(head==NULL)
    {
        printf("linked list is empty!!");
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->prev;
    }
}
void traverselist()
{
    struct node*temp=head;
    if(head==NULL)
    {
        printf("linked list is empty!");
    }
    while(temp!=NULL)
    {
        
        printf("%d->",temp->data);
        
        temp=temp->next;
    }
}
void insertatfrontdoubly(){
    struct node*newnode=creationdoublylist();
    if(head==NULL){
     head=temp=newnode;
    }
    else{
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    
    printf("node inserted succesfully at front\n");
}
}
void insertatenddoubly(){
    struct node*newnode=creationdoublylist();
    struct node*temp=head;
    if(head==NULL){
        insertatfrontdoubly();// printf("linked list empty")
    }
    while(temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=newnode;
    newnode->prev=temp;
    printf("node inserted succesufully at end\n");
    }
void insertatmid(){
    struct node*newnode=creationdoublylist();
    struct node*temp=head;
    int pos,count=0;
    printf("enter position where u want to insert node\n");
    scanf("%d",&pos);
    while(count<pos-1){
        count ++;
        temp=temp->next;
    }
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev=newnode;
    newnode->prev->next=newnode;
    printf("node inserted at mid succesfully\n");
}
void deletefront(){
    struct node*temp=head;
    if(head==NULL){
        printf("linked list is empty\n");
    }
    else{
            head=head->next;
            head->prev=NULL;
            free(temp);
            printf("node deleted at front successfully\n");
    }
}
void deleteend(){
    struct node*temp=head,*q;
    if(head==NULL){
        printf("linked list is empty\n");
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next=NULL;
        free(temp);
        printf("node deleted");
    }
}
int main()
{
    creationdoubly();

    creationdoubly();
    traverselist();
    //insertatfrontdoubly();
    insertatenddoubly();
    traverselist();
   // reverselist();
   insertatmid();
   deletefront();
   deleteend();
   traverselist();
}