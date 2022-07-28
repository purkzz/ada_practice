#include<stdio.h>

int dfs(int,int);
int vis[]={0,0,0,0,0,0,0,0,0,0},a[10][10];

void main(){
    int n,src;
    printf("\nnodes:\t");
    scanf("%d",&n);
    printf("\nadjace:\n");
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    printf("\nsrc:\t");
    scanf("%d",&src);
    int res=dfs(n,src);
    if (res==1)
    {
        printf("\ngraph is conneted");
    }
    else
    {
        printf("\ngraph is not connected");
    }
    
}

int dfs(int n,int src){
    int j;
    vis[src]=1;
    for (int j = 1; j <=n; j++)
    {
        if (a[src][j]==1 && vis[j]!=1)
        {
            dfs(n,j);
        }
    }

    for (int i = 1; i <=n; i++)
        {
            if (vis[i]!=1)
            {
                return 0;
            }
            
        }
        return 1;
        
    
}