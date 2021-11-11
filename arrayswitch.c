#include<stdio.h>
#define n 5
int a[10];
void largest(int b[])
{
	int l=0,i;
	for(i=0;i<n;i++)
	{
		if(b[i]>l)
		l=b[i];
	}
	printf("largest number is %d",l);
}
void smallest(int b[])
{
	int s=b[0],i;
	for(i=0;i<n;i++)
	{
		if(b[i]<s)
		s=b[i];
	}
	printf("the smallest number is %d",s);
}
void sum(int b[])
{
	int s=0,i;
        for(i=0;i<n;i++)
  	{
    	 s=s+b[i];
   	}
	printf("sum is %d",s);
}

void mean(int b[])
{
	int mean,sum=0,i;
	for(i=0;i<n;i++)
	{
	sum=sum+b[i];

	}
	mean=(sum/n);
	printf("mean is %d",mean);
}
void reverse(int b[])
{
	int i;
	printf("the reversed array is\n");
	for(i=n-1;i>=0;i--)
	{
		printf("%d\t",a[i]);
	}

}
void main()
{
int ch,i;

printf("enter the elements of the array\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
do{
printf("\n\nchoice\n1.largest\n2.smallest\n3.sum\n4.reverse\n5.mean\n6.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:largest(a);
break;
case 2:smallest(a);
break;
case 3:sum(a);
break;
case 4:reverse(a);
break;
case 5:mean(a);
break;
case 6:break;
default :printf("wrong choice\n");
}}while(ch!=6);
}
