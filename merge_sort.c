//Merge_sort algorithm

/*
we need to write two functions
1--->Mergesort(array,left,right)
2--->Merge(array,left,middle,right)

==>Mergesort(array,left,right)
this function divides the array into subarrays 
and calls the main merge function that does the sorting of the array.
first the array is divided in the left and then right

if left<right
middle->(left+right)/2
Mergesort(array,left,middle)
Mergesort(array,middle+1,right)
Merge(array,left,middle,right)



==>Merge(array,left,middle,right)
the main function does the sorting,
we need to create two left and right subarrays
and the fill those arrays,
here we rewrite the initial array with as the final sorted array.
left-subarray     middle    right-subarray
_______________   ______    ____________

left_subarray_size==>middle+1-left
right_subarray_size==>right-middle

Merge(array,left,middle,right)
left_subarray[left_size],right_subarray[right_size]

initializing the final array pointers 
i==>0 left_subarray pointer
j==>0 right_subarray pointer
k==>1 final array pointer

while i<left_subarray_size && j<right_subarray_size
    if left[i]<right[j]      append the smallest one onto the final array
        a[k]=left[i]
        i++ k++
    else              append the smallest one onto the final array   
        a[k]=right[j]
        j++ k++
end of while loop

if any of the subarrays has content left then append it to the final array
if i<left_subarray_size                   if j<right_subarray_size
    a[k]=left[i]                               a[k]=right[j]    
    i++ k++                                 j++ k++ 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge_sort(int [],int,int);
void merge(int [],int,int,int);
int a[100000],n=0,l,m,r;

void main(){
    clock_t start,end;
    while (n<=10000)
    {
        for (int i = 0; i < n; i++){a[i]=rand();}

        start=clock();
        merge_sort(a,0,n-1);
        for(int j=0;j<50000000;j++){int temp=38/600;}
        end=clock();
        printf("Time for n=%d is %f seconds \n",n,(((double)(end-start))/CLOCKS_PER_SEC));

        n+=1000;
    }   
}

void merge_sort(int a[],int l,int r){
    if (l<r)
    {
        m=(l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void merge(int a[],int l,int m,int r){
    int lsubarr =m+1-l;  //left subarray size
    int rsubarr =r-m;    //right subarray size
    int left[lsubarr],right[rsubarr];
    for (int i = 0; i < lsubarr; i++){left[i]=a[l+i];}
    for (int i = 0; i < rsubarr; i++){right[i]=a[m+1+j];}
    int i=0,j=0,k=1;  
    //initializing final sorted array pointers  
    //i--->left_sub_arr  j--->right_sub_arr  k--->final array pointer

    while (i<lsubarr && j<rsubarr)
    {
        if(left[i]<=right[j]){
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<lsubarr)
    {
        a[k]=left[i];
        k++;
        i++;
    }
    while(j<rsubarr)
    {
        a[k]=right[j];
        k++;
        j++;
    }
}