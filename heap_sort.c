// heap sort
// we create a max heap
// and delete the root of the array
// continuosly deleting the root will give us the sorted array

// heapify
// 3 inputs
// heapify(a,n,i){
// largest ->i,left->2*i,right->2*i+1
// 3 if conditions
// if(left<N&&arr[left]>arr[larget]){
// largest=left
//  }
// if(right<N&&arr[right]>arr[larget]){
// largest=right
//  }
// if(largest!=i){
// swap(arr[i],arr[largest])
// heapify(a,n,largest)
//  }
// }

// heapsort(arr,n){
// 2 for loops
// for(i->n/2;i>=0;i--){
// heapify(arr,n,i)
//  }
// for(i->n-1 to i>=0 i--){
// swap(arr[0],arr[i])
// heapify(arr,i,0)
//  }
// }

#include <stdio.h>
#include <stdlib.h>

void heapify(int[], int, int);
void heapsort(int[], int);
void printarray(int[], int);
void swap(int *, int *);

void main()
{

  int a[11] = {10,9,8,7,6,5,4,3,2,1,0};
  printarray(a, 11);
  printf("\n");
  heapsort(a, 11);
  printarray(a, 11);
}

void heapsort(int a[], int n)
{
  for (int i = n / 2; i >= 0; i--)
  {
    heapify(a, n, i);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    swap(&a[0], &a[i]);
    heapify(a, i, 0);
  }
}

void heapify(int a[], int n, int i)
{
  int largest = i, left = 2 * i, right = (2 * i) + 1;
  if (left < n && a[left] > a[largest])
  {
    largest = left;
  }
  if (right < n && a[right] > a[largest])
  {
    largest = right;
  }
  if (largest != i)
  {
    swap(&a[i], &a[largest]);
    heapify(a, n, largest);
  }
}

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
void printarray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\t", a[i]);
  }
}