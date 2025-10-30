#include<stdio.h>
#include<stdlib.h>
struct node
{

    int data;
    struct node*link;
};
struct node*temp,*head;
struct node* creationcircularlist()//node created kyuki baar baar ye line likhni na pde
{
    struct node*newnode;
    newnode=(struct node*)malloc(1*sizeof(struct node));
    int value;
    printf("enter the value:\n");
    scanf("%d",&value);
    
    newnode->data=value;
  
    newnode->link=NULL;

    return newnode;
}

void creationcircular(){
  struct node*newnode=creationcircularlist();
  if(head==NULL){
    temp=head=newnode;
    head->link=head;
  }
  else{
    temp->link=newnode;
    temp=newnode;
    temp->link=head;
  }
}
void traverse(){
  struct node*temp=head;
  if(head==NULL){
    printf("circular linked list is empty");
  }
  else{
    do{
      printf("%d->",temp->data);
      temp=temp->link;
    }
    while(temp!=head);
  }
}
int main(){
  creationcircularlist();
  creationcircular();
  creationcircular();
  traverse();
}