#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
struct node{
    int val;
    struct node* next;
};
typedef struct node node;

node* create(int val){
node* newnode=(node*)malloc(sizeof(node));
        newnode->val=val;
        newnode->next=NULL;
        return newnode;
}
void insert(node **head,int val){
    node*temp=*head;
    if(temp==NULL){
        
        *head=create(val);
    }
    else{
        while(temp->next!=NULL)temp=temp->next;
        temp->next=create(val);
    }
}

void print(node *head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}
void pop(node **head,int val){
    node*temp=*head;
    if(temp->val==val){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        if(temp->next->val==val){
            node*temp1=temp->next;
            temp->next=temp->next->next;
            free(temp1);
            return;
        }
        temp=temp->next;
    }
}
int search(node*head,int val){
    while(head!=NULL){
        if(head->val==val){
            return 1;
        }
    head=head->next;
    }
    return -1;
}