//new comment for git
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;
};
void main()
{
struct node *start=NULL,*newnode,*tmp;
int c1=0,c,e,flg=0,k,z;
do{
newnode=(struct node *)malloc(sizeof(struct node));
printf("Enter Data");
scanf("%d",&newnode->data);
newnode->link=NULL;
if(start==NULL){
start=tmp=newnode;
}
else
{
tmp->link=newnode;
tmp=newnode;
}
c1++;
printf("Do you want to continue(0/1)");
scanf("%d",&c);
}while(c==1);
do{
printf("\nEnter operation to perform\n");
printf("1.Count total elements\n");
printf("2.Search an element\n");
printf("3.Print the list\n");
printf("0.To exit\n");
scanf("%d",&k);
switch(k)
{
case 1:printf("\n\nThe total number of elements are %d",c1);break;
case 2:	printf("Enter the element to search");
       	scanf("%d",&e);
	tmp=start;c1=0;
	while(tmp!=NULL)
	{c1++;
	if(tmp->data==e)
	{
	flg=c1;
	}
	tmp=tmp->link;
	}
	if(flg==0){
	printf("\nElement not found");
	}
	else
	printf("\nElement found at %d position",flg);
	break;
case 3:tmp=start;
	while(tmp!=NULL)
	{
	printf("%d\t",tmp->data);
	tmp=tmp->link;
	}
case 0:break;
default :printf("\n\nEnter a valid input");
}
}while(k!=0);
}
