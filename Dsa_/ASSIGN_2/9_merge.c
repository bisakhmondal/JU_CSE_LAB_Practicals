#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
int * merge(int *a,int m,int *b,int n){
int *ans=(int*)malloc((m+n)*sizeof(int));
int p=0,q=0,r=0;
while(p<m&&q<n){
    if(a[p]<=b[q])
    ans[r++]=a[p++];
    else ans[r++]=b[q++];
}   
while(p!=m){
    ans[r++]=a[p++];
}
while(q!=n)
ans[r++]=b[q++];
return ans;
}
int main()
{

int m,n;
printf("Enter the size of the 2 arrays: ");
scanf("%d%d",&m,&n);
int *a=(int*)malloc(m*sizeof(int));
int *b=(int*)malloc(n*sizeof(int));

loop(i,0,m){
    scanf("%d",(a+i));
}
loop(i,0,n){
    scanf("%d",(b+i));
}

int *ans=(int*)malloc((m+n)*sizeof(int));
ans=merge(a,m,b,n);

loop(i,0,m+n){
    printf("%d ",ans[i]);
}
return 0;
}