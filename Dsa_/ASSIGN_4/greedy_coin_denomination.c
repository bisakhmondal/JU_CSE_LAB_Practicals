#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void greedy1(int *a,int siz,int n,int*op){
for(int i=siz;i>=0;i--){
    while(n>=a[i]){
        op[i]++;
        n-=a[i];
    }
    if(n==0){
        for(int j=0;j<siz;j++){
            printf("%d ",op[j]);
        }
        return;
    }
    if(n<0){
        printf("Cant print");
        return;
    }
}
}

int main(){

int n;
printf("Enter n: ");
scanf("%d",&n);
int a[]={1,5,10,25,50};
int op[5];
memset(op,0,sizeof(op));
greedy1(a,5,n,op);

}