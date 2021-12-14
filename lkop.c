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

void ifornt(){//front insertion
tmp=create();
ptr=start;
if(start==NULL){
start=tmp;
}
else{
tmp->next=ptr;
start=tmp;
}
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
void iposition(){//given posirion
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
void dfront(){//deletion at front
ptr=start;
if(ptr==NULL){
printf("Underflow");
}
else
start=start->next;
}
void dend(){//del at end
ptr=start;
if(ptr==NULL){
printf("Underflow");
}
else
{
while(ptr->next!=NULL){
tmp=ptr;
ptr=ptr->next;
}tmp->next=NULL;
}

}

void dspc(){//del at end
int xz;
ptr=start;
if(ptr==NULL){
printf("Underflow");
}
else
{
	printf("ENter data to delete?\n");
	scanf("%d",&xz);
while(ptr->data!=xz){
tmp=ptr;
ptr=ptr->next;
}tmp->next=ptr->next;
}

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
int o1,o2;
do{
printf("\nEnter The operation to perform\n");
printf("1.Insertion\n2.Delesion\n3.Display\n4.Exit\n");
scanf("%d",&o1);
switch(o1){
case 1: //insertion
	h1:printf("\nSelect one of the following\n");
	printf("1.Insertion at front\n2.Insersion at end\n3.Insertion After specific data\n");
	scanf("%d",&o2);
	if(o2==1){//front
	ifornt();
                 }
	else if(o2==2){//end
			iend();
			}
	else if(o2==3){//position
iposition();
			}
	else {printf("\nEnter a valid coice\n");goto h1;
		}break;

case 2://Delesion
	h3:printf("\nSelect one of the following\n");
	printf("1.Delesion at front\n2.Delesion at end\n3.Delesion of specific data\n");
	scanf("%d",&o2);
	if(o2==1){//front
               dfront();
                 }
	else if(o2==2){//end
	dend();
			}
	else if(o2==3){//position
	dspc();
			}
	else {printf("\nEnter a valid coice\n");goto h3;
		}break;

case 3://display 
       displ();
	break;
case 4:break;
default:printf("Enter a valid choice");
}
}while(o1!=4);
}


//read me
//success git git
//display success
