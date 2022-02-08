#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
struct node *start=NULL;
struct node *ptr,*tmp;

struct node *create(){
struct node *newnode;
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter Data");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}
void crt(){
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
void srch(){
	int e,c1,flg=0;
	printf("Enter the element to search");
       	scanf("%d",&e);
	    tmp=start;c1=0;
	    while(tmp!=NULL)
	    {c1++;
	    if(tmp->data==e)
	    {
	    flg=c1;
	    }
	    tmp=tmp->next;
	    }
	    if(flg==0){
	    printf("\nElement not found\n\n");
	    }
	    else
	    printf("\nElement found at %d position\n\n",flg);
}
void insert(){
int pos;
printf("\nEnter data after the data has to be inerted\n");
scanf("%d",&pos);
tmp=create();
ptr=start;
while(ptr->data!=pos){
ptr=ptr->next;
}
tmp->next=ptr->next;
ptr->next=tmp;
}
void delete(){
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
int o1,o2,lk,flg,c1,e;
printf("Creation\n");
printf("Enter size of linked list");
scanf("%d",&o2);
for(lk=0;lk<o2;lk++)
crt();
do{
printf("\nEnter The operation to perform\n");
printf("1.Insertion At Middle\n2.Delesion At front\n3.Search\n4.Display\n5.Exit\n");
scanf("%d",&o1);
switch(o1){
case 1: insert();break;

case 2:delete();break;

case 3:srch();
	    break;

case 4:displ();	break;

case 5:printf("******THANK u******");break;
default:printf("Enter a valid choice");
}
}while(o1!=5);
}

