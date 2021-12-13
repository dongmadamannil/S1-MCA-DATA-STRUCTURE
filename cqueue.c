#include<stdio.h>
int queue[50];
#define n 5
int front=-1,rear=-1;
void enqueue(){
if((front==0&&rear>=n-1)||rear==front-1){
printf("QUEUE IS FULL");
}
else
{
if(front==-1&&rear==-1)
{
front=0;rear=0;
}else if(rear==n-1&&front!=0){
rear=0;
}
else
{
rear=rear+1;
}
printf("\nEnter the data to intert\n");
scanf("%d",&queue[rear]);
}
}
void dequeue(){
if(front==-1){
printf("QUEUE IS EMPTY");
}
else
{
if(front==rear){
front=-1;rear=-1;
}else if(front==n-1){
front=0;
}
else
{
front=front+1;
}
}
}
void peek(){
if(front==-1){
printf("Empty");
}
else
{
printf("peek elements is %d\n",queue[front]);
}
}
void disp(){
int i;
if(front==-1&&rear==-1)
{
printf("EMPTY");
}
else
{
if(front<rear)
{
for(i=front;i<=rear;i++)
printf("%d\n",queue[i]);

}
else
{
for(i=front;i<=n-1;i++)
printf("%d\n",queue[i]);
for(i=0;i<=rear;i++)
printf("%d",queue[i]);


}
}
}

void main(){
int o;
do{
printf("\nEnter operation to perform\n");
printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.EXIT\n");
scanf("%d",&o);
switch(o){
case 1:enqueue();break;
case 2:dequeue();break;
case 3:peek();break;
case 4:disp();break;
case 5:break;
default:printf("Enter a valid input");
}
}while(o!=5);
}
