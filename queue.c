#include<stdio.h>
#define n 10
int queue[n];
int front=-1,rear=-1;
void insert();
int d_ele();
int peek();
void display();
int main(){
int op,val;
do{
printf("\nmenu\n");
printf("\n1.Insert an elements\n2.Delete an element\n3.Peek(Show front elements)\n4.Display\n5.Exit\n");
scanf("%d",&op);
switch(op)
{

case 1:insert();break;
case 2:val=d_ele();
        if(val==-1){
          printf("Oops,Somethng went wrong!");    
          }
         else
         {
          printf("Element deleted value is%d",val);
         }
       break;
case 3:val=peek();
         if(val!=-1){
          printf("The peek element is %d",val);  
          }
          else{ printf("Oops,Somethng went wrong!"); 
             }break;
case 4:display();break;
}
}while(op!=5);
return 0;
}
void insert()
{
int num;
printf("Enter number to be inserted in the queue");
scanf("%d",&num);
if(rear==n-1)
printf("\noverflow");
else if(front==-1&&rear==-1)
front=rear=0;
else
rear++;
queue[rear]=num;
}
int d_ele()
{
int val;
if(front==-1||front>rear)
{ 
printf("\nUnderflow");
return -1;
}
else
{
val=queue[front];
front++;
if(front>rear){
front=rear=-1;
}
return val;

} 
}
int peek(){
if(front==-1||front>rear)
{
printf("Empty\n");
return -1;
}
else
{
return queue[front];

}
}
void display(){
int i;
if(front==-1||front>rear)
printf("\nEmpty");
else
{
for(i=front;i<=rear;++i)
printf("\t%d",queue[i]);
}
}
