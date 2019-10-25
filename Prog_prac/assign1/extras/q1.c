/*program describing pointer and pointer to pointer
Bisakh Mondal, roll-0018105601079 , date-08/08/19*/

#include<stdio.h>
#include<stdlib.h>
int main(){
int n;
printf("Enter a number ");
scanf("%d",&n);//taking an integer input
int* p = &n; //p is a pointer to an integer variable a
int** pp = &p;//pp is a pointer to a pointer p

printf("printing the nuymber n: %d\n",n);//printing the number
printf("printing using single pointer *p %d\n",*p);//printing the number using  single pointer
printf("printing using pointer to pointer**p %d\n",**pp);//printing the number using double pointer	

}
