#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<algorithm.h>
void sort(int *a,int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];a[j]=temp;
            }
        }
    }
}
void sortf(float *a,int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j])
            {
                float temp=a[i];
                a[i]=a[j];a[j]=temp;
            }
        }
    }
}
void sorts(char **a,int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(strcmp(a[i],a[j])>0)
            {
                char temp[25];
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
            }
        }
    }
}

int linear_search(int *a,int n,int val){
int i=0;
for(;i<n;i++){
if(a[i]==val)
return i;
}
return -1;}
int linear_searchf(float *a,int n,float val){
int i=0;
for(;i<n;i++){
if(a[i]==val)
return i;
}
return -1;}

int binary_search(int *a,int s,int e, float val){
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
int binary_searchf(float *a,int s,int e, float val){
if(e>=s){
int mid=(s+e)/2;
if(a[mid]==val)
return mid;
if(a[mid]>val)
return binary_searchf(a,s,mid-1,val);
else 
return binary_searchf(a,mid+1,e,val);
}
return -1;}

int binary_searchs(char* *a,int s,int e, char* val){
if(e>=s){
int mid=(s+e)/2;
if(strcmp(a[mid],val)==0)
return mid;
if(strcmp(a[mid],val)>0)
return binary_searchs(a,s,mid-1,val);
else 
return binary_searchs(a,mid+1,e,val);
}
return -1;}

int linear_searchs(char **a,int n,char *val){
int i=0;
for(;i<n;i++){
if(strcmp(a[i],val)==0)
return i;
}
return -1;}


int main(){
int n;
printf("enter array size\n");
scanf("%d",&n);
printf("choose between 1.int 2.float 3.word\n");
int res;
scanf("%d",&res);
if(res==1){
int *a=(int *)malloc(n*sizeof(int));
int i=0;
for(;i<n;i++)
scanf("%d",(a+i));

printf("Enter value to be checked\n");
int val;
scanf("%d",&val);

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
}
if(res==2)
{
    float *a=(float *)malloc(n*sizeof(float));
int i=0;
for(;i<n;i++)
scanf("%f",(a+i));

printf("Enter value to be checked\n");
float val;
scanf("%f",&val);

int z1,z2;
z1=linear_searchf(a,n,val);
sortf(a,n);
z2=binary_searchf(a,0,n-1,val);

if(z1!=-1)
printf("linear_search: %d\n",z1);
else
printf("not present\n");

if(z2!=-1)
printf("binary_search: %d\n",z2);
else
printf("not present\n");
}
if(res==3){
    
    char **a=(char **)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        a[i]=(char*) malloc(10*sizeof(char));
    }
int i=0;
for(;i<n;i++)
scanf("%s",a[i]);

printf("Enter value to be checked\n");
char val[25];
scanf("%s",val);

int z1,z2;
z1=linear_searchs(a,n,val);
sorts(a,n);
z2=binary_searchs(a,0,n-1,val);

if(z1!=-1)
printf("linear_search: %d\n",z1);
else
printf("not present\n");

if(z2!=-1)
printf("binary_search: %d\n",z2);
else
printf("not present\n");

}





return 0;}

