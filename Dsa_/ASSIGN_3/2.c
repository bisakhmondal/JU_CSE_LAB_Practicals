#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
node *create(int val){
    node * n=(node*)malloc(sizeof(node));
    n->val=val;
    n->next=NULL;
    return n;
}
void insert_after(node **head,int val){
    if(*head==NULL)
    *head=create(val);
    else{
        node *curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=create(val);

    }
}
void insert_bef(node **head,int val){
    if(*head==NULL){
        *head=create(val);
    }
    else{
        node *t=create(val);
        t->next=*head;
        *head=t;
    }
}
void show(node *head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}
void reverse(node **head){
    node *curr=NULL,*prev=NULL,*nxt=*head;
    while(nxt!=NULL){
        curr=nxt;
        nxt=nxt->next;
        curr->next=prev;
        prev=curr;
    }
    *head=curr;
    
}
void sort(node *head){
node *ptr1=head,*ptr2;
while(ptr1!=NULL && ptr1->next!=NULL){
    ptr2=ptr1->next;
    while(ptr2!=NULL){
        if(ptr2->val<=ptr1->val){
            int temp=ptr1->val;
            ptr1->val=ptr2->val;
            ptr2->val=temp;
        }
        ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
}
}
#define loop(i,a,b) for(int i=a;i<b;i++)

int main()
{

FILE *fp=fopen("2.txt","r");
node*head=NULL,*head2=NULL;
// node*curr=head;
while(!feof(fp)){
    int val;
    fscanf(fp,"%d",&val);
    // node *target=create(val);
    insert_after(&head,val);
    insert_bef(&head2,val);
}
show(head);
reverse(&head);
sort(head);
show(head);

return 0;
}