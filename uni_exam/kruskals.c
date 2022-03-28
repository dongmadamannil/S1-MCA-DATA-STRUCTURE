#include<stdio.h>
int parent[9],g[9][9],vr;
int find(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}
void main(){
    int i,j,edge_v=0,u,v,total=0,min,a,b;
printf("Enter number of vertices");
scanf("%d",&vr);
printf("Enter adjacency matrix:\n");
for(i=0;i<vr;i++)
    for(j=0;j<vr;++j)
    {
        scanf("%d",&g[i][j]);
        if(g[i][j]==0){
            g[i][j]=999;
        }
    }
while(edge_v<vr-1){
    min=999;
    for(i=0;i<vr;i++)
        for(j=0;j<vr;++j){
            if(g[i][j]<min){
                min=g[i][j];
                a=u=i;
                b=v=j;
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("%d-%d=%d\n",a,b,g[a][b]);
            total+=g[a][b];
           
            edge_v++;
        }
         g[a][b]=g[b][a]=999;
}
printf("total cost:%d",total);
}