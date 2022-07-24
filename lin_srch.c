//Linear search algorithm
/*
you search linearly
*/

//Linear search algorithm
/*
you search linearly
*/

//Linear search algorithm
/*
you search linearly
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int lin_search(int [],int,int);
int a[10000000],n=10,key,status=0;

void main(){
    clock_t start,end;
    while(n!=1000000){
        for(int i=0;i<n;i++){a[i]=rand();}        //assigning random numbers to the array
        key=a[n-1];
        
        start=clock();                            //starting the timer
        status=lin_search(a,n,key);               //calling the function
        for(int j=0;j<50000;j++){int temp=9/89;}  //producing delay
        end=clock();                              //end the time

        if(status!=-1){
            printf("\nInput Size: %d\t Time: %f",n,(((double)(end-start))/CLOCKS_PER_SEC));
        }
        n+=1000;
    }
}
int lin_search(int a[],int size,int key){
    for(int i=0;i<size;i++){
        if(a[i]==key){
            return 1;
        }
    }
    return -1;
}