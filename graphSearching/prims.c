
#include <stdio.h>

void prims();
int c[10][10], n;

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
  prims();
}

void prims()
{
  int i, j, u, v, min, ne = 0, mincost = 0, visited[10];

  for (int i = 1; i <= n; i++)
  {
    visited[i] = 0;
  }
  visited[1] = 1;
  while (ne != n - 1)
  {
    min = 9999;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (visited[i] == 1)
        {
          if (c[i][j] < min)
          {
            min = c[i][j];
            u = i, v = j;
          }
        }
      }
    }

    if (visited[v] != 1)
    {
      printf("%d<->%d-->%d\n", u, v, min);
      visited[v] = 1;
      ne++;
      mincost += min;
    }
    c[u][v] = c[v][u] = 9999;
  }
  printf("\nmincost is %d", mincost);
}