#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *left,*right;
};
struct node *crte(){
int dta;
struct node *ptr;
ptr=(struct node*)malloc(sizeof(struct node));
printf("ENter data to insert(0 for no insersion)\n");
scanf("%d",&dta);
if(dta==0){
return NULL;
}
ptr->data=dta;
printf("Enter left node of %d\n",ptr->data);
ptr->left=crte();
printf("Enter right node of %d\n",ptr->data);
ptr->right=crte();
return ptr;
}
void pre(struct node *k)
{
if(k!=NULL){
printf("%d\t",k->data);
pre(k->left);
pre(k->right);
}
}
void in(struct node *k)
{
if(k!=NULL)
{
in(k->left);
printf("%d\t",k->data);
in(k->right);
}
}
void post(struct node *k)
{
if(k!=NULL)
{
post(k->left);
post(k->right);
printf("%d\t",k->data);
}
}
void main(){
struct node *root;
root=crte();
printf("\nPreorder Traversal\n");
pre(root);
printf("\ninorder Traversal\n");
in(root);
printf("\npost order Traversal\n");
post(root);

}
