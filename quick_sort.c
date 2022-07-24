//Quick_sort algorithm

/*
we need to write two functions
1--->Partion(array,left,right)
2--->Quick_sort(array,left,right)

==>partion(array,left,right)
This function takes the first elemnt as the starting pivot.
then find the appropriate place in the array.
the appropriate place is found by sorting it's left and right subarray.
and this returns the appropriate postion of the pivot in the array.

partition(array,left,right)
pivot=a[left]   //get the pivot
i=left , j=right
while i<j
    do
        i++
    while a[i]<=pivot
    do
        j--
    while a[j]>pivot
    if left<right
        swap a[i] and a[j]
end while
swap a[left] and a[j]
return j


==>quicksort(left,right)
this function repetatively breaks the array 
and sort the subarrays by finding new pivots everytime

quicksort(left,right)
if left<right
    mid=partition(left,right)  find the appropriate position of the pivot
    quicksort(left,mid)        sort the left subarray
    quicksort(mid+1,right)     sort the right subarray
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int [],int,int);
void quicksort(int [],int,int);
void swap(int* ,int*);
int a[10000],n=500,left,right,cnt=1;

void main(){
    clock_t start,end;
    while (n<=10000)
    {
        for (int i = 0; i < n; i++){a[i]=rand();}
        
        start=clock();
        quicksort(a,0,n-1);
        for(int j=0;j<50000000;j++){int temp=38/600;}
        end=clock();
        printf("Time for n=%d is %f seconds \n",n,(((double)(end-start))/CLOCKS_PER_SEC));
        n+=500;
    }
}

void quicksort(int a[],int left,int right){
    if (left<right)
    {
        int mid=partition(a,left,right);
        quicksort(a,left,mid-1);
        quicksort(a,mid+1,right);
    }
}

int partition(int a[],int left,int right){
    int pivot=a[left];   
    int i=left,j=right;
    while (i<j)
    {
        while(a[i]<=pivot){i++;};
        while(a[j]>pivot){j--;};
        if (i<j){swap(&a[i],&a[j]);}        
    }
    swap(&a[left],&a[j]);
    return j;
}

void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}