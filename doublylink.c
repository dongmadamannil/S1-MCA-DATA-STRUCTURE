#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head= NULL;

void create(int d)
{
    struct node *temp,*newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev= NULL;
    newnode->data = d;
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
void insertb(int d)
{
    struct node *temp,*newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev= NULL;
    newnode->data = d;
    if(head==NULL)
    {
        head=temp=newnode;
    
    }
    else
    {
	newnode->next=head;
	head->next->prev=newnode;
	head=newnode;


    }
}

void inserte(int d)
{
   struct node *temp,*newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev= NULL;
    newnode->data = d;
    if(head==NULL)
    {
        head=temp=newnode;
    
    }
    else
    {
	while(temp->next!=NULL)
	{	
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	temp=newnode;
    }

}

void insertp(int d, int s)
{
    struct node *temp,*newnode;
    newnode =(struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev= NULL;
    newnode->data = d;
    if(head==NULL)
    {
        head=temp=newnode;
    
    }
    else
    {
	temp=head;
	while(temp->next!=NULL)
	{
	if(temp->data == s)
	{
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
	newnode->prev=temp;
	}
	temp=temp->next;
	}
	
	
   }
}

void traverse()
{

    struct node *temp;
    if(head == NULL)
        printf("The list is empty");
    else
    {
	printf("The elements are: ");
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }

    }
}

void deleteb()
{
	struct node *temp;
	if(head == NULL)
        printf("The list is empty");
	else
	{
	temp=head;
	head->next->prev=NULL;
	head=head->next;
	
	printf("The deleted element is %d\n",temp->data);
	free(temp);
	}
}

void deleteend()
{
	struct node *temp, *pretemp;
	if(head == NULL)
        printf("The list is empty");
	else
	{	temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		printf("The deleted element is %d\n",temp->data);
		free(temp);
	}
}

void deletepos(int s)
{
	struct node *temp,*ptr;
	if(head == NULL)
        printf("The list is empty");
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			if(temp->data==s)
			{
				ptr=temp->next;
				temp->next=ptr->next;
				ptr->next->prev=temp;
				printf("The deleted element is %d\n",ptr->data);
		
				free(ptr);
			}
			temp=temp->next;

		}
		
	

	}



}

int main()
{
    int ch,d,s,r;
    
    while(1)
    {
        printf("\n\nMenu 1.create\n 2.insert in beginning\n 3.insert in end \n4.insert after a value\n 5.Delete from beginning\n 6.delete from last\n 7.detele after a position\n 8.display \n9.exit\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data to be inserted ");
		    scanf("%d",&d);
		    create(d);
                    break;
            case 2: printf("Enter data to be inserted ");
		    scanf("%d",&d);
		    insertb(d);
                    break;
	    case 3: printf("Enter data to be inserted ");
		    scanf("%d",&d);
		    inserte(d);
		    break;
	    case 4: printf("Enter data to be searched ");
		    scanf("%d",&s);
		    printf("Enter data to be inserted ");
		    scanf("%d",&d);
		    insertp(d,s);
		    break;
	    case 5: deleteb();
		    break;
	    case 6: deleteend();
	            break;
	    case 7: printf("Enter data to be searched ");
		    scanf("%d",&s);
		    deletepos(s);
		    break;
	    case 8: traverse();
		    break;
	    case 9: exit(0);
		    break;
        }
    }
    return 0;
}

