#include<stdio.h>
#include<malloc.h>
#include<string.h>


typedef struct node
{
    int value;
    struct node *next;
}node;

node * init_s()
{
    return NULL;
}
node *new_node(int n)
{
    node *p;
    p=(node *)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Malloc error");
        return NULL;
    }
    p->value=n;
    p->next=NULL;
    return p;
}

void push(node **head)
{
    int n;
    printf("\nEnter value to insert:");
    scanf("%d",&n);
    node *temp=*head;
    *head=new_node(n);
    if(*head==NULL)
    {
        printf("\nOverflow!!!!!!\n");
        return;
    }
    (*head)->next=temp;
    printf("\nInserted!!!!!\n");
}
int empty(node *head)
{
    return head==NULL;
}

int pop(node **head)
{
    if(!empty(*head))
    {
        node *temp=*head;
        *head=(*head)->next;
        int value=temp->value;
        free(temp);
        printf("\nDeleted\n");
        return value;
    }
    printf("\nUnderflow!!!!\n");
    return -1;
}

void print(node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->value);
        head=head->next;
    }
}

void print_rev(node *head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        print_rev(head->next);
        printf("%d ",head->value);
    }
}
void print_using_pop(node **head)
{
    if((*head)==NULL)
    {
        return;
    }
    else{
        int val=pop(head);
        printf("%d ",val);
        print_using_pop(head);
    }
}
void print_rev__using_pop(node **head)
{
    if((*head)==NULL)
    {
        return;
    }
    else{
        int val=pop(head);
        print_using_pop(head);
        printf("%d ",val);
    }
}
int equal(node *head1,node *head2)
{
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->value!=head2->value)
        {
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
    if(!empty(head1)&&empty(head2))
    {
        return 0;
    }
    if(!empty(head2)&&empty(head1))
    {
        return 0;
    }
    return 0;

}
