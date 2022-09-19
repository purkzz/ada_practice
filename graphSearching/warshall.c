// warshall algorithm
// it is used to find all the transitive clouser of a matrix

#include <stdio.h>
#include <stdlib.h>

int n, a[10][10];
void warshall();

void main()
{
  printf("\nEnter number of vertices:\t");
  scanf("%d", &n);
  printf("\nEnter adjacency matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  warshall();
}

void warshall()
{
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if ((a[i][j]) || (a[i][k] && a[k][j]))
        {
          a[i][j] = 1;
        }
      }
    }
  }
  printf("\nthe transitive clouser of the matrix is:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
  }
}