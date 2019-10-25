/*Implement a one dimensional array of integers where array size of the array will be provided during
runtime. Accept the value for the elements and print those using pointers.

author: Bisakh Mondal, roll-0018105601079 , date-08/08/19*/


#include<stdio.h>
#include<stdlib.h>


int main(){
int n;
printf("Enter number of elements in an array ");
scanf("%d",&n);
int i=0;//declaring A pointer statically
if(n<0){
printf("wrong dimension \n");
exit(1);
}

int a[n];//declaring an array of size n
for(i=0;i<n;i++){
scanf("%d",(a+i));//taking input of the elements of the array
}

printf("The elements in an array are \n");
for(i=0;i<n;i++){
printf("%d ",*(a+i));}//printing the elements of the array

return 0;
}

