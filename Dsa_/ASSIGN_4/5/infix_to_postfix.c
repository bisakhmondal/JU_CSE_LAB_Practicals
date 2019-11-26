#include<stdio.h>
#include<malloc.h>
#include<string.h>


typedef struct node
{
    char value;
    struct node *next;
}node;

node * init_s()
{
    return NULL;
}
node *new_node(char n)
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

void push(node **head,char n)
{
    //char n;
    //printf("\nEnter value to insert:");
    //scanf("%d",&n);
    node *temp=*head;
    *head=new_node(n);
    if(*head==NULL)
    {
        printf("\nOverflow!!!!!!\n");
        return;
    }
    (*head)->next=temp;
    printf("\nInserted  %c!!!!!\n",n);
}
int empty(node *head)
{
    return head==NULL;
}

char pop(node **head)
{
    if(!empty(*head))
    {
        node *temp=*head;
        *head=(*head)->next;
        char value=temp->value;
        free(temp);
        printf("\nDelted\n");
        return value;
    }
    printf("\nUnderflow!!!!\n");
    return NULL;
}

void print(node *head)
{
    while(head!=NULL)
    {
        printf("%c ",head->value);
        head=head->next;
    }
}


int isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

char peek(node *head)
{
    if(!empty(head))
    {
        return head->value;        
    }
    return '\0';
}
int Priority(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 
  
    case '*': 
    case '/': 
        return 2; 
  
    case '^': 
        return 3; 
    } 
    return -1; 
} 

void infix_to_postfix(node *head,char infix[])
{
    int n=strlen(infix);
    int i;
    char postfix[n];
    int count=0;
    for(i=0;i<n;i++)
    {
        if(infix[i]=='(')
        {
            push(&head,infix[i]);
        }
        else if(isOperand(infix[i]))
        {
            postfix[count++]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(!empty(head)&&peek(head)!='(')
            {
                postfix[count++]=pop(&head);
            }
            if(peek(head)=='(')
            {
                pop(&head);
            }
        }
        else
        {
            while (!empty(head) && Priority(infix[i]) <= Priority(peek(head))) 
            postfix[count++] = pop(&head); 
            push(&head,infix[i]); 
        }

    }
     while (!empty(head)) 
    postfix[count++] = pop(&head); 
    n=sizeof(postfix);
    printf("\n%s\n",postfix);
}

int main() 
{ 
    node *head=init_s();
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    infix_to_postfix(head,exp); 
    return 0; 
} 