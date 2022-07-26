
#include<stdio.h>

void bfs(int,int);
int a[10][10];

void main(){
    int n,src;
    printf("\nEnter the number of nodes in the graph:\t");
    scanf("%d",&n);
    printf("\nAdjacency matrix\n");
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    
    printf("\nsrc\t");
    scanf("%d",&src);
    bfs(src,n);
}

void bfs(int src,int n){
    int queue[10],visited[]={0,0,0,0,0,0,0,0,0,0},r=0,f=0;
    visited[src]=1;
    queue[r]=src;

    while (f<=r)
    {
        int i=queue[f++];
        for (int j = 1; j <=n; j++)
        {
            if (visited[j]!=1 && a[i][j]==1)
            {
                visited[j]=1;
                queue[++r]=j;
            }
            
        }
        
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]==1)
        {
            printf("\nNode %d is reachable",i);
        }
        else
        {
            printf("\nNode %d is not reachable",i);
        }
    }
            printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",queue[i]);
    }
    
}