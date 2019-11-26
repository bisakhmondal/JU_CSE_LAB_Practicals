#include<stdio.h>
#include<stdlib.h>
//#include<algorithm.h>

 void swap(float *a,float *b){
     float temp=*a;
     *a=*b;
     *b=temp;
     return;
 }

 void sort(float *f,int n){
   for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(f[i]>f[j]){
                swap(&f[i],&f[j]);
            }
        }
    }
    return;


}

int linear_search(float *a,int n,float val){
int i=0;
for(;i<n;i++){
if(a[i]==val)
return i;
}
return -1;}

int binary_search(float *a,int s,int e, float val){
if(e>=s){
int mid=(s+e)/2;
if(a[mid]==val)
return mid;
if(a[mid]>val)
return binary_search(a,s,mid-1,val);
else 
return binary_search(a,mid+1,e,val);
}
return -1;}

int main(){
int n;
scanf("%d",&n);
//printf("choose between 1.int 2.float 3.char\n");
//int res;
//scanf("%d",&res);
float *a=(float *)malloc(n*sizeof(float));
int i=0;
for(;i<n;i++)
scanf("%f",(a+i));
float val;
scanf("%f",&val);

int z1,z2;
z1=linear_search(a,n,val);

sort(a,n);
z2=binary_search(a,0,n-1,val);

if(z1!=-1)
printf("linear_search: %d\n",z1);
else
printf("not present\n");

if(z2!=-1)
printf("binary_search: %d\n",z2);
else
printf("not present\n");





return 0;}

