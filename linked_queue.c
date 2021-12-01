#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *ptr,*tmp,*kmp;

struct node *create(){//create single node
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter Data");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}

void peek(){
    if(ptr==NULL){
printf("Underflow");
}
else
printf("%d",start->data);
}

void iend(){//end insertion
tmp=create();
ptr=start;
if(ptr==NULL){
start=tmp;
}
else{
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=tmp;}
}

void dfront(){//deletion at front
ptr=start;
if(ptr==NULL){
printf("Underflow");
}
else
start=start->next;
}

void displ(){//fn to disply
ptr=start;
while(ptr->next!=NULL){
printf("%d\t",ptr->data);
ptr=ptr->next;
}
printf("%d\t",ptr->data);
}
void main(){
int o1;
do{
printf("\nEnter The operation to perform\n");
printf("1.Insertion\n2.Delesion\n3.Display\n4.peek\n5.exit\n");
scanf("%d",&o1);
switch(o1){
case 1: //insertion
		iend();
               break;

case 2://Delesion
	               dfront();
     break;

case 3://display 
       displ();
	break;
case 4:peek();break;
case 5:break;
default:printf("Enter a valid choice");
}
}while(o1!=5);
}


//read me
//insertion completed all cases
//display success
