// Knapsack problem
// create a table of n+1 and m+1 rows and columns respectively
// n--->number of objects
// m--->max weight of the knapsack
// k is the 2 dimensional matrix which consists of all combination of weights

#include <stdio.h>
#include <stdlib.h>
int n, i, m, w[10], p[10], k[10][10];

void knapsack(int[], int[], int, int);
int max(int, int);

void main()
{
  printf("\nEnter the number of objects in the problem:\t");
  scanf("%d", &n);
  printf("\nEnter the weight of objects in the problem:\t");
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &w[i]);
  }

  printf("\nEnter the profit of each objects in the problem:\t");
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &p[i]);
  }
  printf("\nEnter the max capacity of the knapsack:\t");
  scanf("%d", &m);
  knapsack(w, p, m, n);
}

void knapsack(int weight[], int profit[], int m, int n)
{
  int x[10];
  for (int i = 0; i <= n; i++)
  {
    for (int w = 0; w <= m; w++)
    {
      if (i == 0 || w == 0)
      {
        k[i][w] = 0;
      }
      else if (weight[i] <= w)
      {
        k[i][w] = max(p[i] + k[i - 1][w - weight[i]], k[i - 1][w]);
      }
      else
      {
        k[i][w] = k[i - 1][w];
      }
    }
  }

  printf("\nOptimal solution:%d", k[n][m]);

  printf("\ntable:\n");
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      printf("%d\t", k[i][j]);
    }
    printf("\n");
  }

  int i = n-1, j = m-1;
  while (i >= 0 && j >= 0)
  {
    if (k[i][j] = k[i - 1][j])
    {
      printf("0\t");
      i--;
    }
    else
    {
      printf("%d\t", i);
      i--;
      j = j - w[i];
    }
  }
}

int max(int a, int b)
{
  if (a < b)
  {
    return b;
  }
  return a;
}