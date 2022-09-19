//GCD problem

/*
take two integer inputs

GCD(m,n)
if(n==0)
    return m
else
    GCD(n,m%n)

    ----OR----

while(n!=0)
    m=n
    n=m%n
return m
*/

#include<stdio.h>
#include<stdlib.h>

int GCD(int,int);

void main(){
    int i=0;
    while (i<=20)
    {
        int m=rand(),n=rand();
        printf("\nGCD of %d %d is\t%d",m,n,GCD(m,n));
        i++;
    }   
}
int GCD(int m,int n){
    if(n!=0){
        GCD(n,m%n);
    }
    return m;
}