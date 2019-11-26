#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef struct sparse{
    int *row;
    int *col;
    int *val;
    int idx;
}sparse;

void init(sparse *s){
printf("Enter dimension(matrix row and column): ");
int r,c,v;
scanf("%d%d",&r,&c);
printf("Enter Nos of non zero entry: ");
scanf("%d",&v);
s->row=(int *)malloc((v+1)*sizeof(int));
s->col=(int *)malloc((v+1)*sizeof(int));
s->val=(int *)malloc((v+1)*sizeof(int));
s->row[0]=r;
s->col[0]=c;
s->val[0]=v;
s->idx=1;
}
void gen_sparse(sparse*s){
printf("Enter matrix row and column: ");
int r,c,v;
scanf("%d%d",&r,&c);
printf("Enter value: ");
scanf("%d",&v);
s->row[s->idx]=r;
s->col[s->idx]=c;
s->val[s->idx]=v;
s->idx++;
}
int search(sparse s,int v){
    loop(i,1,s.idx){
        if(s.val[i]==v)
        return i;
    }
    return -1;
}
void transpose(sparse *s){
    int *temp=s->row;
    s->row=s->col;
    s->col=temp;
    return;
}
void print(sparse s){
    loop(i,0,s.idx){
        printf("%d %d %d\n",s.row[i],s.col[i],s.val[i]);
    }
}