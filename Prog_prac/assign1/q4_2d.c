/*Implement the programs in Q.2 and 3 breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation, 
iii) accepting the values and 
iv) printing the values.
Author: Bisakh Mondal, roll-0018105601079 , date-08/08/19*/


#include<stdio.h>
#include<stdlib.h>

void get_dim(int *r,int *c){//getting the dimension of an array
int i=0;
printf("Enter size of an array: row-> ");
scanf("%d",r);
printf("Enter size of an array:column->");
scanf("%d",c);
return;
}

int** allocate(int r,int c){//allocating the memory dynamically
int **a = (int**)malloc(r*sizeof(int*));
for(int i=0;i<r;i++){
    a[i]=(int*)malloc(c*sizeof(int));
}
return a;
}
void taking_input(int **a,int r,int c){
int i=0;
printf("Enter the inputs\n");
for(i=0;i<r;i++){
int j=0;
for(;j<c;j++){
scanf("%d",(*(a+i)+j));
}
}
return;
}
void print(int** a,int r,int c){//printing the elements of an array
int i;
printf("Printing the elements\n");
for(i=0;i<r;i++){
int j=0;
for(;j<c;j++){
printf("%d ",*(*(a+i)+j));
}
printf("\n");
}
return;
}
int main(){
int r,c;
get_dim(&r,&c);
int** a = allocate(r,c);
taking_input(a,r,c);
print(a,r,c);
}
