#include"string.h"
int main()
{
string s;

do{
printf("1.input\t 2.print\t 3.length\t 4.concatenate\t5.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    input(&s);
}
if(choice==2){
    print(s);
}
if(choice==3)
{
    printf("The length of string : %d\n",getlen(s));
}
if(choice==4)
{
   string s2;
   printf("the the string to be concatenated\n");
   input(&s2);
   string s1=concat(s,s2);
   printf("the concatanated string: ");
   print(s1);
   printf("\n");

}
if(choice==5)
break;
printf("\n---------------------------------------------\n");
}while(1);


return 0;
}