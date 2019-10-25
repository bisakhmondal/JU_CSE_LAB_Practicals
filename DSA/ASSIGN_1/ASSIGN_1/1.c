#include<stdio.h>
#include<stdlib.h>

long int fact_rec(int n){
if(n==1)
return 1;
return n*fact_rec(n-1);
}

long int fact_it(int n){
long int fact=1;
while(n>=1){
fact*=n;
n--;}
return fact;}



int main(){
int n;
scanf("%d",&n);
long int z1=fact_rec(n),z2=fact_it(n);
printf("%ld\n%ld\n",z1,z2);
return 0;}

