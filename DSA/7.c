#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

struct node{
int cap;
int *init;
struct node * next;    
};
typedef struct node node;

node* create(int n){
node *nn=(node *)malloc(sizeof(node));
nn->cap=n;
nn->init=(int *)malloc(n*sizeof(int));
return nn;
}

void insert(node **head_main){
    printf("space for how many ints: ");
    int n;
    scanf("%d",&n);
    if(*head_main==NULL){
        printf("Memory allocated successfully\n");
                *head_main=create(n);
    }
    node *temp=*head_main;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=create(n);
    printf("Memory allocated successfully\n");
    return;
    
}

int main(){

    return 0;
}