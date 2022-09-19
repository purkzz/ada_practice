//selection_sort algorithm

/*
make one for loop and one while loop
for loop   -->complete problem
while loop -->to change the position of the elements in the array
while loop for checking the next highest element
it creates two parts in the array sorted one and unsorted one
for i->1 to n
    key=a[i]
    j=i-1
    while(key<a[j] && j>=0)
        shift the numbers to the right and decrement j counter
        a[j++]=a[j]
        --j
    end while loop
    put the key value back to the array at right place in the array
    a[j+1]=key  
end for loop
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ins_sort(int,int []);
int a[100000],n=100,min;

void main(){
    clock_t start,end;
    while (n!=10000)
    {
        for (int i = 0; i < n; i++){a[i]=rand();}

        start=clock();
        ins_sort(n,a);
        for(int j=0;j<50000000;j++){int temp=38/600;}
        end=clock();
        printf("Time for n=%d is %f seconds \n",n,(((double)(end-start))/CLOCKS_PER_SEC));

        n+=1000;
    }   
}

void ins_sort(int n,int a[]){
    int key,j;
    for (int i = 1; i < n; i++)
    {
        key=a[i];
        j=i-1;
        while (key<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}