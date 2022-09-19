#include <stdio.h>

void dijkstras();
int c[10][10], n, src;

void main()
{
  int i, j;
  printf("\nenter the no. of vertices:\t");
  scanf("%d", &n);
  printf("\nenter the cost matrix:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &c[i][j]);
    }
  }
  printf("\nenter the src:\n");
  scanf("%d", &src);
  dijkstras();
}

void dijkstras()
{
  int i, u, visited[10], dis[10], count = 1, min;
  for (int i = 0; i <= n; i++)
  {
    dis[i] = c[src][i];
    visited[i] = 0;
  }
  visited[1] = 1;
  dis[src] = 0;
  count++;
  while (count != n)
  {
    min = 9999;
    for (int i = 1; i <= n; i++)
    {
      if (dis[i] < min && visited[i] != 1)
      {
        min = dis[i];
        u = i;
      }
    }
    count++;
    visited[u] = 1;
    for (int i = 1; i <= n; i++)
    {
      if (c[u][i] + min < dis[i] && visited[i])
      {
        dis[i] = min + c[u][i];
      }
    }
    for (int i = 1; i <= n; i++)
    {
      printf("\n%d-->%d=%d", src, i, dis[i]);
    }
  }
}