//Tower Of Hanoi Problem
//3-->pegs  
//many number of disks(n)
//Time Complexity-->O(2^n)
//number of moves required is (2^n)-1


//Algorithm
/*
Toh(n,src,dest,aux)
if(n=1)
move disk from source to destination
else
TOH(n-1,src,aux,dest)
move disk from source to destination
TOH(n-1,aux,dest,src)
*/

#include<stdio.h>
#include<stdlib.h>

void TOH(int,char,char,char);

void main(){
    int n;
    printf("\nEnter the number of disks:\t");
    scanf("%d",&n);
    TOH(n,'A','C','B');
}

void TOH(int n,char src,char dest,char aux){
    if(n==1){
        printf("\nmove disk 1 from %c to %c",src,dest);
    }
    else{
        TOH(n-1,src,aux,dest);
        printf("\nmove disk %d from %c to %c",n,src,dest);
        TOH(n-1,aux,dest,src);
    }
}