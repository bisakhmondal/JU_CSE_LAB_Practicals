#include<stdio.h>
#include<stdlib.h>

long int fibo_rec(int n){
if(n==1 || n==0)
return 1;
return fibo_rec(n-1)+fibo_rec(n-2);
}

long int fibo_it(int n){
//long unsigned int *fibo=(long unsigned int *)malloc((n+1)*sizeof(int));
long int fibo[n+1];
fibo[0]=fibo[1]=1;
int i=2;
for(;i<=n;i++)
fibo[i]=fibo[i-1]+fibo[i-2];
long int ans=fibo[n];
//free(fibo);
return ans;}



int main(){
int n;
printf("enter input for fibonacci calculation\n");
scanf("%d",&n);
long int z1=fibo_rec(n),z2=fibo_it(n);
printf("%d th fibonacci number is\nfibo_rec : %ld\nfibo_itr %ld\n",n,z1,z2);
int i=0;
for(;i<100;i++){
//printf("fib %d : %ld\n",i,fibo_it(i));
if(fibo_it(i)<0)
{printf("break at: %d\n",i);
break;}
}
return 0;}

