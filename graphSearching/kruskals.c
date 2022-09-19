#include <stdio.h>

void kruskals();
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
  kruskals();
}

void kruskals()
{
  int i, j, u, v, a, b, min, ne = 0, mincost = 0, parent[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  while (ne != n - 1)
  {
    min = 9999;
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (c[i][j] < min)
        {
          min = c[i][j];
          u = a = i;
          v = b = j;
        }
      }
    }

    while (parent[u] != 0)
    {
      u = parent[u];
    }
    while (parent[v] != 0)
    {
      v = parent[v];
    }

    if (u != v)
    {
      printf("%d<->%d--->%d\n", a, b, min);
      ne++;
      mincost += min;
      parent[v] = u;
    }

    c[a][b] = c[b][a] = 9999;
  }
  printf("\nmincost=%d", mincost);
}