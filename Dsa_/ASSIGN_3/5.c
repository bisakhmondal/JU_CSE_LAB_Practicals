#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
}node;

node *create(int v){
node *n=(node *)(malloc(sizeof(node)));
n->next=n->prev=NULL;
n->val=v;
return n;
}

void insert(node **head,int v){
    if(*head==NULL){
    *head=create(v);
    return;
    }
    node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=create(v);
    node  *n=temp->next;
    n->prev=temp;
    return;
}
void print(node *head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
}
void delete(node **head,int v){
    node *temp= *head;
    if(*head=NULL){
        *head=temp->next;
        (*head)->prev=NULL;
        free(temp);
        return;
    }
    while(temp->next!=NULL){
        if(temp->val==v){
            node * t=temp;
            temp->prev->next=temp->next;
            if(temp->next!=NULL){
            temp->next->prev=t->prev;}
            free(temp);
        }
        temp=temp->next;
    }
}
void print_rev(node *head)
{
    if(head==NULL)
    return;
    print_rev(head->next);
    printf("%d ",head->val);

}


int main(){
    // node *head=NULL;
    // insert(&head,50);
    // print(head);
    // insert(&head,500);
    // print(head);
    // insert(&head,506);
    // print(head);
    // print(head);
    printf("%lu",sizeof(node));
}