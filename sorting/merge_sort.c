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

void merge(int [],int,int,int);
void merge_sort(int [],int,int);

void main(){
    int a[]={10,9,8,7,6,5,4,3,2,1,0},n=11,i;
    for(i=0;i<11;i++)
        printf("%d\t",a[i]);
    merge_sort(a,0,10);
    printf("\n");
    for(i=0;i<11;i++)
        printf("%d\t",a[i]);
}
// void merge(int a[],int l,int m,int r){
//     int n1=m+1-l,n2=r-m;
//     int L[n1],R[n2];
//     for(int i=0;i<n1;i++){L[i]=a[l+i];}
//     for(int j=0;j<n2;j++){R[j]=a[m+1+j];}
//     int i=0,j=0,k=0;
//     while (i<n1 && j<n2)
//     {
//         if (L[i]<=R[j])
//         {
//             a[k]=L[i];
//             i++;
//         }
//         else
//         {
//             a[k]=R[j];
//             j++;
//         }
//         k++;
//     }
//     while (i<n1)
//     {
//         a[k]=L[i];
//         i++;
//         k++;
//     }
//     while (j<n2)
//     {
//         a[k]=R[j];
//         j++;
//         k++;
//     }
// }
void merge_sort(int a[],int l,int r){
    if (l<r)
    {
        int mid=(l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);
    }
    
}
void merge(int a[],int low,int mid,int high)
{
    int c[15000],i,j,k;
    i=k=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j]){
            c[k]=a[i];
            i++;
            }
        else{
            c[k]=a[j];
            j++;
            }
            k++;
    }
    while(j<=high)
    {
        c[k]=a[j];
        k++;
        j++;
        }
    while(i<=mid){
        c[k]=a[i];
        k++;
        i++;
            }
    for(i=low;i<=high;i++){
        a[i]=c[i];
    }
}