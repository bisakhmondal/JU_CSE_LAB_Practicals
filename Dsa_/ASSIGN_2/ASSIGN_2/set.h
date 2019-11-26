#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define INIT_SET(x) set x={.idx=0};
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sort(int *a,int n){
loop(i,0,n){
    loop(j,i+1,n){
        if(a[i]>a[j])swap(&a[i],&a[j]);
    }
}
}

typedef struct{
    int a[100];
    int idx;

}set;
void insert(set *s,int val){
for(int i=s->idx;i>=0;i--){
    if(s->a[i]==val)
    return;
}
s->a[s->idx++]=val;
sort(s->a,s->idx);
}
void print(set s){
    loop(i,0,s.idx){
        printf("%d ",s.a[i]);
    }
}
int getsize(set s){
    return s.idx;
}
int is_empty(set s){
    if(s.idx==0){
        return 1;
    }
    return 0;
}