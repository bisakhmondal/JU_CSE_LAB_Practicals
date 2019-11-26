#include"sparse.h"
int main()
{

sparse s;

do{
printf("1.generate\t 2.print\t 3.transpose\t 4.search\t5.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    init(&s);
    loop(i,0,s.val[0]){
        gen_sparse(&s);
    }
}
if(choice==2){
    print(s);
}
if(choice==3)
{
    transpose(&s);
}
if(choice==4)
{
    int val;
    printf("enter value to be searched\n");
    scanf("%d",&val);
    int res=search(s,val);
    if(res==-1){
        printf("No entry found\n");
    }
    else printf("Found at row : %d col: %d \n",s.row[res],s.col[res]);
}
if(choice==5)
break;
printf("---------------------------------------------\n");
}while(1);


return 0;
}