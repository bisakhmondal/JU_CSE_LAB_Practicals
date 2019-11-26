#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
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
void showf(node *head){
    while(head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}
void show_rev(node *head){
    if(head==NULL)
    return;
    show_rev(head->next);
    printf("%d ",head->val);
}
int count(node*head){
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}
bool equal(node *head1,node*head2){
    if(count(head1)!=count(head2))
    return false;
    while(head1!=NULL || head2!=NULL){
        if(head1->val!=head2->val)
        return false;
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}
node *search_un(node **head,int val){
    if((*head)->val==val){
        node *curr=*head;
        *head=curr->next;
        curr->next=NULL;
        return curr;
    }
    node *curr=*head;
    while(curr->next!=NULL){
        if(curr->next->val==val){
            node*temp=curr->next;
            curr->next=temp->next;
            temp->next=NULL;
            return temp;
        }
        curr=curr->next;
    }
    return NULL;

}
node *search_ord(node **head,int val){
    if((*head)->val==val){
        node *curr=*head;
        *head=curr->next;
        curr->next=NULL;
        return curr;
    }
    node *curr=*head;
    int cache=curr->val;
    while(curr->next!=NULL){
        if(curr->next->val==val){
            node*temp=curr->next;
            curr->next=temp->next;
            temp->next=NULL;
            return temp;
        }
        if(curr->next->next!=NULL && ((curr->next->next->val>=curr->next->val && curr->next->val>=cache)||(curr->next->next->val<=curr->next->val && curr->next->val<=cache))){
            return NULL;
        }
        curr=curr->next;
        cache=curr->val;
    }
    return NULL;

}
void remove_dup_unsorted(node *head){
    node *ptr1,*ptr2;
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->val==ptr2->next->val){
                node *temp=ptr2->next;
                ptr2->next=temp->next;
                free(temp);
            }
            else ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}
void remove_dup_order(node *head){
    if(head==NULL)
    return;
    while(head->next!=NULL){
        if(head->val==head->next->val){
            node *temp=head->next;
            head->next=temp->next;
            free(temp);
        }
        else head=head->next;
    }
    
}
void l_move(node**head){
    node *curr=*head;
    if(curr->next==NULL)
    return;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    node *temp=curr->next;
    curr->next=NULL;
    temp->next=*head;
    *head=temp;
}
void delete(node *head){
    while(head!=NULL){
        node *curr=head;
        head=head->next;
        free(curr);
    }
    return;
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
void rotate(node **head,int pt){
   if(pt==0)
   return;
   node *curr=*head;
   while(curr!=NULL && pt!=0){
       pt--;
       curr=curr->next;
   }
   if(pt!=0){
       printf("Change point, size is larger than the list\n");

   }
   node *temp=curr;
   while(curr->next!=NULL){
       curr=curr->next;
   }
   curr->next=*head;
   *head=temp;
   return;
}
void sort(node *head){
node *ptr1=head,*ptr2;
while(ptr1!=NULL && ptr1->next!=NULL){
    ptr2=ptr1->next;
    while(ptr2!=NULL){
        if(ptr2->val>=ptr1->val){
            int temp=ptr1->val;
            ptr1->val=ptr2->val;
            ptr2->val=temp;
        }
        ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
}
}

void swap_pair(node *head){
 node *ptr1=head;
 if(ptr1->next==NULL)return;
 while(ptr1->next!=NULL ){
     node *ptr2=ptr1->next;
     int temp=ptr1->val;
            ptr1->val=ptr2->val;
            ptr2->val=temp;
    ptr1=ptr1->next->next!=NULL?ptr1->next->next:ptr1->next;
 }

}
void append(node **prev,node *app){
    node *curr=*prev;
    while(curr->next!=NULL)
    curr=curr->next;
    curr->next=app;
    return;
}
void del_N(node **head,int n){
    node *curr=*head,*prev;
    int p=0;
    if(n==0){
        node *cu=*head;
        *head=cu->next;
        free(cu);
    }
    while(curr->next!=NULL){
        prev=curr;
        curr=curr->next;
        p++;
        if(p==n-1)break;
    }
    if(p==n-1)
    {node *temp=curr->next;
    curr->next=temp->next;
    free(temp);
    }
    if(curr->next==NULL && p!=n-1){
       node *temp=curr;
    prev->next=NULL;
    free(temp); 
    }

}

void merge(node**head1,node *head2){
    if((*head1)->val>head2->val)
    {
        insert_bef(head1,head2->val);
        head2=head2->next;
    }
    node*curr=head1,*prev;
    while(curr->next!=NULL && head2->next!=NULL){
        prev=curr;
        if(curr->val>head2->val){
            prev->next=create(head2->val);
            prev->next->next=curr;
            head2=head2->next;
        }
        else{
        prev=curr;
        curr=curr->next;
        }
    }
    if(head2->next!=NULL){
        prev->next=head2;
    }

    
}
bool check_sorted(node *head){
    int f=-1;
    bool flag=true;
    while(head->next!=NULL){
        if(head->val==head->next->val){
            flag=true;
            continue;
        }
        if(head->val>head->next->val && (f==0||f==-1)){
            f=0;
            flag=true;
            continue;
        }
        if(head->val<head->next->val && (f==1||f==-1)){
            f=1;
            flag=true;
            continue;
        }
        flag=false;
        if(!flag)
        break;
    
    }
    return flag;
}

int main()
{



return 0;
}