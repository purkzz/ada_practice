#include<stdio.h>

void topo(int,int [10][10]);

void main(){
    int n,a[10][10];
    printf("\nNodes\t");
    scanf("%d",&n);
    printf("\nAdjace\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    topo(n,a);
}

void topo(int n,int a[10][10]){
    int i,j,k,u,v,s[10],t[10],indeg[10],sum,top=-1;
    //counting the indegree
    for ( i = 0; i < n; i++)
    {
        sum=0;
        for ( j = 0; j < n; j++)
        {
            sum+=a[j][i];
        }
        indeg[i]=sum;
    }
    
    //put into s[10]
    for ( i = 0; i < n; i++)
    {
        if (indeg[i]==0)
        {
            s[++top]=i;
        }
        
    }
    
    k=0;
    //putting things on the table
    while (top!=-1)
    {
        u=s[top--];
        t[k++]=u;
        for ( v = 0; v < n; v++)
        {
            if (a[u][v]==1)
            {
                indeg[v]=indeg[v]-1;
                if (indeg[v]==0)
                {
                    s[++top]=v;
                }
                
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",t[i]);
    }
    
}