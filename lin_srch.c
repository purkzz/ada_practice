//Linear search algorithm
/*
Time Complexity-->O(n)

you search linearly
*/

//Linear search algorithm
/*
Time Complexity-->O(n)

you search linearly
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int lin_search(int [],int,int,int);
int a[10000],n=1000,key,status=0;

void main(){
    clock_t start,end;
    while(n<=10000){
        for(int i=0;i<n;i++){a[i]=rand();}        //assigning random numbers to the array
        key=a[n-1];
        
        start=clock();                            //starting the timer
        status=lin_search(a,0,n,key);               //calling the function
        for(int j=0;j<5000000;j++){int temp=9/89;}  //producing delay
        end=clock();                              //end the time

        if(status!=-1){
            printf("\nInput Size: %d\t Time: %f",n,(((double)(end-start))/CLOCKS_PER_SEC));
        }
        n+=1000;
    }
}
int lin_search(int a[],int i,int size,int key){
    if(i>size)
        return -1;
    else if(a[i]==key)
        return i;

    else
        return lin_search(a,i+1,size,key);    
}