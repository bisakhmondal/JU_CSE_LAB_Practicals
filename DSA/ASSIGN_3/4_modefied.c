#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef struct mode{
    int info;
    int next;
} node;
int prev,nan;
node * init(int n){
node * pool=(node *)malloc(n*sizeof(node));
loop(i,0,n){
    pool[i].info=0;
    pool[i].next=i+1;
}
pool[n-1].next=-1;
prev=-1;nan=0;
return pool;
}
void insert(node *pool,int val){
    pool[nan].info=val;
    if(prev!=-1)
    pool[prev].next=nan;
    prev=nan;
    nan=pool[nan].next;
    pool[prev].next=-1;
}

void print(node * n,int v){
    printf("nan: %d prev: %d \n",nan,prev );
    loop(i,0,v){
        printf("%d %d\n",n[i].info,n[i].next);
    }
}
void delete(node *pool,int val){
    int temp=-1;
    int i=0;
    while(pool[i].next!=-1){
        if(pool[i].info==val){
            if(temp!=-1){
                pool[temp].next=pool[i].next;
            }
            pool[i].next=nan;
            pool[i].info=0;
            nan=i;
            break;
        }
        temp=i;
        i=pool[i].next;
    }
}
int main(){
    node *pool=init(5);
    insert(pool,5);
    print(pool,5);
    insert(pool,15);
    print(pool,5);
    insert(pool,55);
    print(pool,5);
    delete(pool,15);
    print(pool,5);
    insert(pool,64);
    print(pool,5);
}