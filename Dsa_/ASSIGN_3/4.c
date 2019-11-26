#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef struct{
    int arr[15];
    int cursor[15];
    int nan;
    int prev;
} lis;
int ii;
void init_I(lis *l){
    loop(i,0,14){
        l->cursor[i]=i+1;
        l->arr[i]=0;
    }
    l->arr[14]=0;
    l->cursor[14]=-1;
    l->nan=0;
    l->prev=-1;
}
bool empty_I(lis l){
    return l.nan;
}
bool attend_I(lis l){
    if(l.nan==149)
    return true;
    return false;
}
void insert(lis *l,int val){
    ii++;
    int idx=l->nan;
    l->arr[idx]=val;
    if(l->prev!=-1){
    l->cursor[l->prev]=idx;}
    l->prev=idx;
    l->nan=l->cursor[idx];
    l->cursor[l->prev]=-1;
    
    
    if(l->nan==-1){
        printf("List is completed create another\n");
    }
    
    printf("%d\n",ii);                                                                                       
}
void delete(lis *l,int val){
    int i=0,prev=-1;
    while(l->cursor[i]!=-1){

        if(l->arr[i]==val){
            l->cursor[prev]=l->cursor[i];
            l->cursor[i]=l->nan;
            l->nan=i;
            return;
        }
        prev=i;
        i=l->cursor[i];
    }
}
void print(lis l){
    printf("arr  cursor %d %d\n",l.nan,l.prev);
    loop(i,0,15){
        printf("%d  %d\n",l.arr[i],l.cursor[i]);
    }
}


int main(){
    lis l;
    init_I(&l);
    print(l);
    insert(&l,10);
    print(l);
    insert(&l,14);
print(l);    insert(&l,13);
delete(&l,13);
print(l);
    insert(&l,15);
    insert(&l,16);
    print(l);
    return 0 ;


}