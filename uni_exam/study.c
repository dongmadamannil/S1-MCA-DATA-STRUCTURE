#include <stdio.h>
int a[15][15], in[10],vis[10];
void main()
{
    int i, j,inn,x=0;
    printf("Enter the adjacency matrix");
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
        {
            scanf("%d", &a[i][j]);
        }
        for(i=0;i<4;i++){
            vis[i]=0;
        }
    while(x<4){
//calculate in degree
inn=0;
for(i=0;i<4;++i){
for(j=0;j<4;++j){
    if(a[j][i]==1)
    {
        inn++;
    }
}
in[i]=inn;inn=0;
}
for(j=0;j<4;++j){
if(in[j]==0&&vis[j]==0){
    printf("%d\n",j);
    vis[j]=1;
    break;
}}
for(i=0;i<4;i++){
    if(a[j][i]==1){
        a[j][i]=0;
    }
}
x++;

    }



}