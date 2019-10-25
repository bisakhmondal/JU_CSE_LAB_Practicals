#include"list.h"

int main()
{
    node*head=NULL;
do{
printf("1.insert\t 2.print\t 3.delete\t 4.search\t5.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    int val;
    printf("enter value to be inserted: ");
    scanf("%d",&val);
    insert(&head,val);
}
if(choice==2){
    print(head);
}
if(choice==3)
{
    int val;
    printf("enter value to be deleted: ");
    scanf("%d",&val);
    pop(&head,val);
}
if(choice==4)
{
    int val;
    printf("enter value to be searched\n");
    scanf("%d",&val);
    int res=search(head,val);
    if(res==-1){
        printf("No entry found\n");
    }
    else printf("Found\n");
}
if(choice==5)
break;
printf("---------------------------------------------\n");
}while(1);




return 0;
}