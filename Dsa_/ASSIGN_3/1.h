#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define loop(i,a,b) (for(int i=a;i<b;i++))
struct node{
    int val;
    struct node*next;
};
typedef struct node node;

node *init_I(){
    return NULL;
}
bool empty_I(node *head){
    return (head==NULL);
}
bool atend_I(node *curr){
    if(curr==NULL)
    return 0;
    return (curr->next==NULL);
}
node *create(int val){
    node * n=(node*)malloc(sizeof(node));
    n->val=val;
    n->next=NULL;
    return n;
}
void insert_front(node **head,node *target){
target->next=*head;
*head=target;
}
void insert_after(node*target,node*prev){
    target->next=prev->next;
    prev->next=target;
}

void delete_front(node **head){
    if(*head==NULL)
    return;
    node *curr=*head;
    *head=(*head)->next;
    free(curr);
}
void delete_after(node *prev){
    if(atend_I(prev)==0)
    return;
    node* curr=prev->next;
    prev->next=curr->next;
    free(curr);
}

void print(node *head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}
