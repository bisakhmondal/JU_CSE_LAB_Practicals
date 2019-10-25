#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
int checksorted(int *a,int n,bool flag){
    if(n==0)
    return 1;
    if(a[0]<=a[1]  && flag==true)
    return checksorted(a+1,n-1,true);
    if(a[0]>=a[1] && flag==false)
    return checksorted(a+1,n-1,false);
    return -1;
}
int main()
{
int m;
printf("Enter the size of the array: ");
scanf("%d",&m);
int *a=(int*)malloc(m*sizeof(int));
loop(i,0,m){
    scanf("%d",(a+i));
}
bool asc=true;
if(a[0]>a[m-1])
asc=false;

int p=checksorted(a,m-1,asc);
 if(p==1){
     printf("sorted");
     asc==true?printf(" ascending"):printf(" descending");
 }   
 else
 printf("not sorted");


return 0;
}