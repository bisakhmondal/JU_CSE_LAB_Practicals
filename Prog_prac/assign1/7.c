/*7. Maintain a list to store roll, name and score of students. As and when required student record may be
added or deleted. Also, the list has to be displayed. Design suitable functions for different operations.

Author: Bisakh : roll: 001810501079 date:8/8/19"*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char roll[25];
    char name[40];
    int score;
    struct node* next;
};

void push(struct node **head,char *roll,char *name,int score){
    struct node* new_node=(struct node *)malloc(sizeof(struct node));
    new_node->score=score;
    strcpy(new_node->roll,roll);
    strcpy(new_node->name,name);
    new_node->next=*head;
    *head=new_node;


};

int pop(struct node **head,char *troll)
{
    struct node* temp=*head,*prev;
    if(temp!=NULL && strcmp(temp->roll,troll)==0 ){
        *head=temp->next;
        free(temp);
        return 1;
    }
    while(temp!=NULL && strcmp(temp->roll,troll)!=0){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    return -1;
    prev->next=temp->next;
    free(temp);
    return 1;
}

void display(struct node* node){
while(node!=NULL){
printf("name: %s | roll: %s | score: %d\n",node->name,node->roll,node->score);
node=node->next;}
return ;
}

int main(){
    struct node* head=NULL;
    do{
        int choice;
        printf("1.Push\n2.Pop\n3.none\n4.display list\n");
        scanf("%d",&choice);
        if(choice==3)
        break;
        if(choice==1){
            printf("Enter name Roll and score\n");
            char name[40],roll[25];
            int score;
            scanf("%s%s%d",name,roll,&score);
            push(&head,roll,name,score);
        }
        if(choice==2){
            char troll[25];
            printf("Enter the roll to delete specific record: ");
            scanf("%s",troll);
            int z=pop(&head,troll);
            if(z==1)
            printf("Record deleted successfully\n");
            else printf("No record found\n");

        }
        if(choice==4){
            display(head);
        }

    }while(1);

    return 0;
}
