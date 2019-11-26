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

void push(node **head,int n)
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

int pop(node **head)
{
    if(!empty(*head))
    {
        node *temp=*head;
        *head=(*head)->next;
        int value=temp->value;
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
        printf("%d ",head->value);
        head=head->next;
    }
}

int isDigit(char n)
{
    return (n>='0'&&n<='9');
}

char peek(node *head)
{
    if(!empty(head))
    {
        return head->value;        
    }
    return '\0';
}


int postfix_evaluation(node *head,char postfix[])
{
    int n=strlen(postfix);
    int i;
    int count=0;
    for(i=0;i<n;i++)
    {
        if(postfix[i] == ' ')continue;  
        if(isDigit(postfix[i]))
        {
            int  num=0;
            while(isDigit(postfix[i]))
            {
                num=num*10+(postfix[i]-'0');
                i++;
            }
            i--;
            push(&head,num);
        }
        else
        {
            int val1 = pop(&head);  
            int val2 = pop(&head);  
              
            switch (postfix[i])  
            {  
            case '+': push(&head, val2 + val1); break;  
            case '-': push(&head, val2 - val1); break;  
            case '*': push(&head, val2 * val1); break;  
            case '/': push(&head, val2/val1); break;  
        }

    }}
    return pop(&head);
}

int main() 
{ 
    node * head=init_s();
    char exp[100] = "100 200 + 2 / 5 * 7 +"; 
    printf("\n%d\n",postfix_evaluation(head,exp)); 
    return 0; 
} 