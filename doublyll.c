#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode,*prev,*ptr;
void new();
void insertb();
void insertpos();
void inserte();
void deleteb();
void deletepos();
void deletel();
void traverse();
int main()
{
    int ch;
    do
    {
        printf("\n Menu\n1.new\n2.insert at biginning\n3.insert after a node\n4.insert at end\n5.delete from beginning\n6.delete after a node\n7.delete at end\n8.traverse\nenter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:new();
            break;
            case 2:insertb();
            break;
            case 3:insertpos();
            break;
            case 4:inserte();
            break;
            case 5:deleteb();
            break;
            case 6:deletepos();
            break;
            case 7:deletel();
            break;
            case 8:traverse();
            break;
            default:
            printf("wrong choice");
        }

    }while(ch!=9);
}
void new(){
    int c=1;
    while(c==1){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->next=0;
        newnode->prev=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;   
        }
        printf("Do you want to continue(0/1)");
        scanf("%d",&c); 
    }

}     
void insertb()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data ");
    scanf("%d",&newnode->data);
     newnode->prev=0;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;

}
void insertpos()
{
    int pos;
    printf("enter the position");
    scanf("%d",&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data ");
     scanf("%d",&newnode->data);
     temp=head;
     while(temp->data!=pos)
     {
         temp=temp->next;
         }
         newnode->next=temp->next;
         newnode->prev=temp;
         temp->next=newnode;
         temp->next->prev=newnode;
}
void inserte()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("entre the data");
scanf("%d",&newnode->data);
newnode->next=0;
temp=head;
while(temp->next!=0)
{
    temp=temp->next;
}
temp->next=newnode;
newnode->prev=temp;

}
void deleteb()
{
    temp=head;
    if(head==0)
    {
        printf("underflow\n");
    }
    else
    head=head->next;
    head->prev=0;
    free(temp);
}

void deletepos()
{
    int val;
ptr=temp=head;
if(head==0)
{
    printf("underflow\n");

}
printf("enter the data after which you have to delete node\n");
scanf("%d",&val);
while(ptr->data!=val)
{
    ptr=ptr->next;
}
temp=ptr->next;
ptr->next=temp->next;
temp->next->prev=ptr;
free(temp);
}


void deletel()
{
temp=head;
if(head==0)
{
    printf("underflow\n");
}
while(temp->next!=0)
{
    temp=temp->next;
}
temp->prev->next=0;
free(temp);
}

void traverse()
{
temp=head;
printf("the elements are\n");
while(temp!=0)
{
    printf("%d",temp->data);
    temp=temp->next;
}
}