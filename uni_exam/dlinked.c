#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *llink,*rlink;
};
struct node *newnode,*temp,*head=NULL,*tempr,*hlo;
struct node *create(){
int val;
printf("\nenter data to be inserted:");
scanf("%d",&val);
newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=val;
newnode->rlink=NULL;
newnode->llink=NULL;
return newnode;
}
void i_front(){//front insertion
temp=create();
if(head==NULL){
head=temp;
}
else
{
tempr=head;
temp->rlink=tempr;
tempr->llink=temp;
head=temp;
printf("\n*********Data inserted*********\n");
}
}
void i_given(){//insertion at given position
int ri_dta;
printf("ENter data after which new data to be inserted");
scanf("%d",&ri_dta);
temp=create();
tempr=head;
while(tempr->data!=ri_dta && tempr->rlink!=NULL){
tempr=tempr->rlink;
}
hlo=tempr->rlink;
tempr->rlink=temp;
temp->llink=tempr;
temp->rlink=hlo;
printf("\n*********Data inserted*********\n");
}
void i_end(){//insertion at end
temp=create();
tempr=head;
while(tempr->rlink!=NULL){
tempr=tempr->rlink;
}
tempr->rlink=temp;
temp->llink=tempr;
printf("\n*********Data inserted*********\n");
}
void d_front(){
if(head==NULL){
printf("List is empty");
}
else
{
printf("\n*************%d deleted**************\n",head->data);
head=head->rlink;
head->llink=NULL;

}

}
void d_given(){
int ri_dta;
printf("Enter data to be deleted");
scanf("%d",&ri_dta);
temp=head;
if(head->data!=ri_dta){
while(temp->data!=ri_dta&& tempr->rlink!=NULL){
temp=temp->rlink;
}
if(temp->data==ri_dta){
temp->llink->rlink=temp->rlink;
temp->rlink->llink=temp->llink;
printf("\nData deleted\n");
}else
{
printf("element not found");
}
}
else
{
d_front();
}
}
void d_end(){//deletion at end
temp=head;
while(temp->rlink!=NULL){
temp=temp->rlink;
}
temp->llink->rlink=NULL;
printf("\n*************%d deleted**************\n",temp->data);
}
void main()
{
int n,i,o,o1,ri=1;
printf("Enter The size of list to be created");
scanf("%d",&n);
printf("\nEnter %d data",n);
for(i=0;i<n;i++){
temp=create();
if(head==NULL){
head=temp;
}
else
{
tempr=head;
while(tempr->rlink!=NULL){
tempr=tempr->rlink;
}
tempr->rlink=temp;
temp->llink=tempr;
}
}

while(ri!=0){
printf("\nSelect Operation to perform\n");
printf("1.Insertion\n2.Deletion\n3.Display List\n4.Exit\n");
scanf("%d",&o);
switch(o){
case 1:printf("Enter Operation to perform\n");
	printf("\n1.Insertion at front\n2.Insertion at given position\n3.Insertion at end\n");
	scanf("%d",&o1);
	switch(o1){
	case 1:i_front();break;
	case 2:i_given();break;
	case 3:i_end();break;
	default:printf("\nENter a valid choice\n");
	}break;

case 2:printf("\nEnter Operation to perform\n");
	printf("1.Deletion at front\n2.Deletion of specific data\n3.Deletion at end\n");
	scanf("%d",&o1);
	switch(o1){
	case 1:d_front();break;
	case 2:d_given();break;
	case 3:d_end();break;
	default:printf("\nENter a valid choice\n");
	}break;

case 3:temp=head;
	if(temp!=NULL){
	printf("\nData are:\n");
	while(temp!=NULL){
	printf("%d\n",temp->data);
	temp=temp->rlink;
	}}
	else
	{
	printf("\nList is empty\n");
	}break;

case 4:ri=0;break;
default:printf("\nEnter a valid choice\n");

}

}



}
