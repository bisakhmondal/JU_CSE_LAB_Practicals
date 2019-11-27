#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int val;
    struct node *next;
}node;
node* create(int val){
    node *n=(node*)malloc(sizeof(node));
    n->next=NULL;
    n->val=val;
    return n;
}
void insert_before(node **head,int val){
    if(*head==NULL){
        *head=create(val);
        return;
    }
    node*temp=create(val);
    temp->next=*head;
    *head=temp;
    return;
}
void insert_after(node **head,int val){
    if(*head==NULL){
        *head=create(val);
        return;
    }
    node*temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=create(val);
}

void push_val(node **head,char * c){
   int i=0;
    while(c[i]!='\0'){
        int a=c[i]-'0';
        insert_after(head,a);
        i++;
    }
}



node* addTwoLists (node* first, node* second)  
{  
    node* res = NULL;  
    node *temp, *prev = NULL;  
    int carry = 0, sum;  
  
    while (first != NULL || second != NULL) 
    {  
   
        sum = carry + (first? first->val: 0) + 
                      (second? second->val: 0);  
  
        carry = (sum >= 10)? 1 : 0;  
  
        sum = sum % 10;  
  

        temp = create(sum);  

        if(res == NULL)  
            res = temp;  

        else  
            prev->next = temp;  
    
        prev = temp;  
  
 
        if (first) first = first->next;  
        if (second) second = second->next;  
    }  
  
    if (carry > 0)  
    temp->next = create(carry);  
  
    
    return res;  
}  



void addition(node *head1,node *head2,node **head3){
    int ext=0;
    while(head1!=NULL && head2!=NULL){
        ext+=(head1->val)+head2->val;
        insert_before(head3,ext%10);
        ext/=10;
        head1=head1->next;
        head2=head2->next;

    }
    while(head1!=NULL){
        ext+=(head1->val);
        insert_before(head3,ext%10);
        ext/=10;
        head1=head1->next;
    }
    while(head2!=NULL){
        ext+=(head2->val);
        insert_before(head3,ext%10);
        ext/=10;
        head2=head2->next;
    }
    while(ext!=0){
    insert_before(head3,ext%10);
        ext/=10;
    }

}
void substraction(node *head1,node *head2,node **head3){
    int ext=0,bo=0;
    while(head1!=NULL && head2!=NULL){
        ext=(head1->val)-bo-head2->val;
        bo=0;
        if(ext<0){
            bo++;
            ext+=10;
        }
        insert_before(head3,ext);
        head1=head1->next;
        head2=head2->next;

    }
    while(head1!=NULL){
        ext+=(head1->val);
        insert_before(head3,ext%10);
        ext/=10;
    }
    while(head2!=NULL){
        ext+=(head2->val);
        insert_before(head3,ext%10);
        ext/=10;
    }
    // while(ext!=0){
    // insert_before(head3,ext%10);
    //     ext/=10;
    // }
    if(bo==1){
        int val=(*head3)->val;
        (*head3)=(*head3)->next;
        insert_before(head3,-1*val);
    }

}

void print(node *head){
    while(head!=NULL){
        printf("%d",head->val);
        head=head->next;
    }
    printf("\n");
}
int main(){
    char a[10],b[10];
    scanf("%s",a);
    scanf("%s",b);
    node *head1=NULL,*head2=NULL,*head3=NULL;
    push_val(&head1,a);
    push_val(&head2,b);
    head3=addTwoLists(head1,head2);
    print(head3);
    // head3=NULL;
    // substraction(head1,head2,&head3);
    // print(head3);


}