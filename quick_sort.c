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

void quic(int [],int,int);
int part(int [],int,int);
void swap(int *,int *);
void printit();

void main(){
    int a[]={11,10,9,8,7,6,5,4,3,2,1,0};
    printit(a,12);
    quic(a,0,11);
    printf("\n");
    printit(a,12);
}

void quic(int a[],int l,int r){
    if (l<r)
    {
        int pivot=part(a,l,r);
        quic(a,l,pivot-1);
        quic(a,pivot+1,r);
    }
}
int part(int a[],int l,int r){
    int i=l,j=r,pivot=a[l];
    while (i<j)
    {
        while(a[i]<=pivot){i++;}
        while(a[j]>pivot){j--;}
        if(i<j){swap(&a[i],&a[j]);}
    }
    swap(&a[l],&a[j]);
    return j;
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void printit(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",a[i]);
    }
}