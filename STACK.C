#include <stdio.h>
//#include <conio.h>
int main()
{
	int a[30], i, n, o, top = -1, ITEM;
	char m;
	printf("enter the no. of terms:");
	scanf("%d", &n);
	do
	{
		printf("\nwhich operation do you want?\n1.PUSH\n2.POP\n3.DISPLAY\n4.SHOW TOP\n");
		scanf("%d", &o);
		//clrscr();
		if (o == 1)
			if (top >= n - 1)
				printf("stack is full\n");
			else
			{
				printf("enter the ITEM:");
				scanf("%d", &ITEM);
				top++;
				a[top] = ITEM;
			}
		else if (o == 2)
			if (top < 0)
				printf("stack is empty\n");
			else
			{
				ITEM = a[top];
				top--;
			}
		else if (o == 3)
		{
			if (top < 0)
				printf("stack is empty\n");
			else
			{
				printf("The stack is:\n");
				for (i = top; i >= 0; i--)
					printf("%d\t", a[i]);
			}
		}
		else if (o == 4)
		{
			if (top < 0)
				printf("stack is empty\n");
			else
			{
				printf("Top elements is:%d\n",a[top]);
				
			}
		}
		else
			printf("wrong input\n");
		printf("\ndo you want to continue(y/n):");
		getchar();
		scanf("%c", &m);
		//clrscr();
	} while (m == 'y' || m == 'Y');
	return 0;
}
