//selection_sort algorithm

/*

Time Complexity-->O(n^2)


make two loops
one loop for checking the next highest element
second loop for arranging that elemnt in the array
it creates two parts in the array sorted one and unsorted one
for i->0 to n-1
    for j->i+1 to n
        get the next least number
        a[i]<a[j]
        new-high->j
    end second loop
    swap a[i] with a[j]
end first loop
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sel_sort(int,int []);
int a[100000],n=100,min;

void main(){
    clock_t start,end;
    while (n!=10000)
    {
        for (int i = 0; i < n; i++){a[i]=rand();}

        start=clock();
        sel_sort(n,a);
        for(int j=0;j<50000000;j++){int temp=38/600;}
        end=clock();
        printf("Time for n=%d is %f seconds \n",n,(((double)(end-start))/CLOCKS_PER_SEC));

        n+=1000;
    }   
}

void sel_sort(int n,int a[]){
    for (int i = 0; i < n-1; i++)
    {
        min=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;        
    }
}