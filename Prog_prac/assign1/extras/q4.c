/*program to allocate array size at the runtime and print thye value using pointers dynamically
Shubham Kumar, roll-0018105601089 , date-08/08/19*/
#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("Enter number of elements in an array ");
scanf("%d",&n);
int *p,i=0;//pointer to an array
p = (int*)malloc(n*sizeof (int));//dynamically allocating the size of the pointer
for(i=0;i<n;i++){
scanf("%d",(p+i));//taking input of the elements of the array
}
printf("The elements in an array are \n");
for(i=0;i<n;i++){
printf("%d ",*(p+i));//printing the elements of the array
}

}
