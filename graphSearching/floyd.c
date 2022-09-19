// floyds algorithm
// it finds all th eshortest path between all pair of vertices

#include <stdio.h>
#include <stdlib.h>

int n, a[10][10];
void floyd();
int min(int, int);

void main()
{
  printf("\nEnter number of vertices:\t");
  scanf("%d", &n);
  printf("\nEnter cost matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  floyd();
}

int min(int a, int b)
{
  return (a < b) ? a : b;
}

void floyd()
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  printf("\nthe shortest path between every pair is:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}