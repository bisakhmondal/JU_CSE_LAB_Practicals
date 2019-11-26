#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#include "set.h"
int main()
{
INIT_SET(s);
do{
printf("1.insert\t 2.print\t 3.Size of set\t 4.Check If Empty\t5.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    int val;
    scanf("%d",&val);
    insert(&s,val);
}
if(choice==2){
    print(s);
}
if(choice==3)
{
    printf("\n Container size %d \n",getsize(s));
}
if(choice==4)
if(is_empty(s)){
    printf("\nContainer is empty\n");
}
else printf("Not Empty\n");
if(choice==5)
break;
printf("---------------------------------------------\n");
}while(1);



return 0;
}