#include <stdio.h>
#include <stdbool.h>
#define inf 1000
int v;
int g[50][50];
void mst(bool span[])
{printf("Edge =Cost\n");
    int e_count = 0, cost, i, j,x,y,total=0;
    span[0]=1;
    while (e_count < v-1)
    {
        cost = inf;
        for (i = 0; i < v ; i++)
        {
            if(span[i]){
                for(j=0;j<v;++j){
                    if(!span[j]&&g[i][j])
                    {
                        if(g[i][j]<cost){
                            cost=g[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }



            }
        }
        printf("%d -%d=%d\n",x,y,g[x][y]);
        total+=g[x][y];
        span[y]=1;
        e_count=e_count+1;
    }
}

void main()
{
    int i, j;
    printf("Enter total number of vertices");
    scanf("%d", &v);
    printf("ENter adjacency matrix");
    for (i = 0; i < v; ++i)
        for (j = 0; j < v; ++j)
            scanf("%d", &g[i][j]);
    for (i = 0; i < v; ++i)
        g[i][i] = 0;
    bool span[v];
    for (i = 0; i < v; ++i)
        span[i] = 0;
    mst(span);
}