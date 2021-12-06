#include<stdio.h>
void main(){
int i,j,n,m,a[10],b[10],res[50],k=0;
printf("Enter size of 1st array\n");
scanf("%d",&n);
printf("ENter %d elements",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("ENter size of 2nd array\n");
scanf("%d",&m);
printf("ENter %d elements",m);
for(i=0;i<m;i++)
scanf("%d",&b[i]);
i=0;j=0;
while(i<m&&j<n){
if(a[i]<b[j]){
res[k]=a[i];
i++;k++;
}
else
{
res[k]=b[j];
j++;
k++;
}
}
while(i<m)
res[k++]=a[i++];
while(j<n)
res[k++]=b[j++];

printf("ARRAY AFTER SORTING");
for(i=0;i<k;i++)
printf("%d\n",res[i]);
}
