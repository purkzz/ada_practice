//Binary search algorithm
/*

Time Complexity-->O(log n)

you search Binarily
you break the array and search
bin_srch(array,low,high,key)
if low>high
    return -1
mid=(low+high)/2
if array[mid]==key
    return mid
else
    if a[i]>key
        bin_srch(array,mid+1,high,key)
    else
        bin_srch(array,low,mid-1,key)
    
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bin_search(int [],int,int,int);
int a[10000000],n=10,key,low,high,status=0;

void main(){
    clock_t start,end;
    while(n!=1000000){
        for(int i=0;i<n;i++){a[i]=rand();}        //assigning random numbers to the array
        key=a[n-1];
        
        start=clock();                            //starting the timer
        status=bin_search(a,low,high,key);        //calling the function
        for(int j=0;j<50000;j++){int temp=9/89;}  //producing delay
        end=clock();                              //end the time

        if(status!=-1){
            printf("\nInput Size: %d\t Time: %f",n,(((double)(end-start))/CLOCKS_PER_SEC));
        }
        n+=1000;
    }
}
int bin_search(int a[],int low,int high,int key){
    int mid;
    if(low>high){
        return -1;
    }
    mid=(low+high)/2;
    if(a[mid]==key){
        return mid;
    }
    if(a[mid]>key){
        bin_srch(a,mid+1,high,key);
    }
    else{
        bin_srch(a,low,mid-1,key);
    }
}