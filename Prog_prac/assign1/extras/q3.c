/*Implement a two dimensional array of integers using 
a) pointer to an array and 
b) array of pointers.
Accept the value for the elements and print those.
author: Bisakh Mondal, roll-0018105601079 , date-08/08/19
*/


#include<stdio.h>
#include<stdlib.h>
int main(){
int r,c;//row and columns
printf("Enter number of rows in an array ");
scanf("%d",&r);
printf("Enter number of columns in an array ");
scanf("%d",&c);

int a[r][c];//initializing arary of size r*c


for(int i=0;i<r;i++){
for(int j=0;j<c;j++)
scanf("%d",(*(a+i)+j));
}

int (*p)[c]=a;//statically allocating pointer to an array
printf("Using pointer to an array \n");
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
printf("%d ",*(*(p+i)+j));//printing the elements of an array
}
printf("\n");
}
printf("Using array of pointer \n");
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
printf("%d ",*(*(a+i)+j));//printing the elements of an array
}
printf("\n");
}
}
