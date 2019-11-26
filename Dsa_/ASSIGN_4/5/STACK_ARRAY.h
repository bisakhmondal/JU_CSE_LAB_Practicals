#include<stdio.h>
#include<malloc.h>
#define MAX_SIZE 1024
typedef struct stack
{
    int top;
    int array[MAX_SIZE];
}stack;
typedef stack* stack;
void init_s(stack s)
{
    s=(stack *)malloc(sizeof(stack));
    (s)->top=-1;
}
int empty(stack s)
{
    return s->top==-1;
}

int overflow(stack s)
{
    return s->top==MAX_SIZE-1;
}

void push(stack s,int x)
{
    if(!overflow(s))
    {
        s->array[++s->top]=x;
        printf("Pushed\n");
    }
    else
    {
        printf("Overflow!!");
    }
    
}

int pop(stack s)
{
    if(!empty(s))
    {
        return s->array[s->top--];
    }
    else
    {
        printf("Underflow\n");
        return -1;
    }
    
}

void print(stack s)
{
    int i;
    for(i=0;i<=s->top;i++)
    {
        printf("%d ",(s->array)[s->top-i]);
    }
    printf("\n");
}

void print_rev(stack s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d ",(s->array)[i]);
    }
    printf("\n");

}

void print_with_pop(stack s)
{
    while(!empty(s))
    {
        printf("%d ",pop(s));
    }
    printf("\n");
}

void print_rev_using_pop(stack s)
{
    if(empty(s))
    {
        return;
    }
    else
    {
        {
            int v=pop(s);
            printf("Popped value is %d\n",v);
            print_rev_using_pop(s);
            printf("%d ",v);
        }
    }
    
}
int equal(stack s1,stack s2)
{
    int n1=s1->top;
    int n2=s2->top;
    printf("%d %d",s1->top,s2->top);
    if(n1!=n2)
    {
        return 0;
    }
    else
    {
        n1=0;
        n2=0;
        while(n1<=s1->top && n2<=s2->top)
        {
            if(s1->array[n1]!=s2->array[n2])
            {
                return 0;
            }
            n1++;
            n2++;
            printf("HI");
        }
        if(n1==s1->top && n2>s2->top)
        {
            return 0;
        }
        else if(n1>s1->top && n2==s2->top)
        {
            return 0;
        }
        return 1;
    }
    
}