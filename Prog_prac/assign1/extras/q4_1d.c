/*Implement the programs in Q.2 and 3 breaking it into functions for 
i) getting the dimensions from user,
ii) dynamic memory allocation, 
iii) accepting the values and 
iv) printing the values.
Author: Bisakh Mondal, roll-0018105601079 , date-08/08/19*/


#include<stdio.h>
#include<stdlib.h>

void get_dim(int *a){//getting the dimension of an array
int i=0;
printf("Enter size of an array ");
scanf("%d",a);
}

int* allocate(int n){//allocating the memory dynamically
int *a = (int*)malloc(n*sizeof(int));
return a;
}
void taking_input(int *a,int n){
int i=0;
printf("Enter the inputs\n");
for(i=0;i<n;i++){
scanf("%d",(a+i));
}
return;
}
void print(int* a,int n){//printing the elements of an array
int i;
printf("Printing the elements\n");
for(i=0;i<n;i++){
printf("%d ",*(a+i));
}

return;
}
int main(){
int r;
get_dim(&r);
int* a = allocate(r);
taking_input(a,r);
print(a,r);
}
