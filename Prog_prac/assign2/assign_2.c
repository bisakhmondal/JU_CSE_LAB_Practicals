/*
student records storing in file
1:add records
2:display records
3:edit records
4delete records 
Author: Bisakh Mondal, roll-0018105601079 , date-08/08/19*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int i,j;
struct student{
char name[50];
char roll[10];
int marks[5];
};
//printing
void display(struct student s){
printf("name: %s |roll: %s",s.name,s.roll);
printf(" Marks: ");
for(i=0;i<5;i++){
printf("%d ",s.marks[i]);
}
printf("\n");

return;
}

//
struct student s11;
struct student* fiterator(FILE *f,char *roll){
    FILE *fp=f;
    rewind(fp);
    while(fread(&s11,sizeof(struct student),1,fp)!=0){
        if(strcmp(s11.roll,roll)==0){
            return &s11;
        }
    }
    return NULL;
}

int main()
{
FILE *fp =fopen("record.txt","w+");
long int recsize=sizeof(struct student);
//setting layout
do{
char choice;
printf("\n1.add records\n2.search_record\n3.display_records\n4.modify records\n5.Delete records\n6.exit\n");

scanf("%d",&choice);
system("clear");

//add record
if(choice==1){
fseek(fp,0,SEEK_END);

printf("Enter name, Roll and score of 5 subjects\n");
struct student s;
scanf("%s%s",s.name,s.roll);
if(fiterator(fp,s.roll)==NULL){
for(i=0;i<5;i++)
scanf("%d",&s.marks[i]);
fwrite(&s,recsize,1,fp);
printf("New Record Created :)\n");
}
else{
    printf("Roll already exists\n");
}
}

//Display record
if(choice==3){
system("clear");
rewind(fp);
struct student s;
while(fread(&s,recsize,1,fp)!=0)
{
display(s);
}
}
//search record
if(choice==2)
{
system("clear");
printf("Enter Roll to be Searched: ");
char roll[25];
scanf("%s",roll);
struct student *s;
bool flag=false;
if((s=fiterator(fp,roll))!=NULL){
printf("Record found\n");
struct student s1=*s;
display(s1);
flag=true;
}
if(!flag){
printf("No Record found\nCheck the Roll\n");
}
}
//modifying record
if(choice==4){
system("clear");
printf("Enter Roll to be Modified: ");
char roll[25];
scanf("%s",roll);
rewind(fp);
struct student s;
bool flag=false;
while(fread(&s,recsize,1,fp)!=0)
{
if(strcmp(roll,s.roll)==0)
{
flag=true;
printf("what field do you want to modify\n");
do{
int choice1;
printf("change\n0.Roll\n1. name\n2.marks1\n3.marks2\n4.marks3\n5.marks4\n6.marks5\n7.Done\n");
scanf("%d",&choice1);
if(choice1>7 || choice1<0){
printf("enter correct response\n");
continue;}
if(choice1==7)
break;
if(choice1==0 ||choice1==1){
char temp[50];
scanf("%s",temp);
if(choice1==0)
strcpy(s.roll,temp);
else
strcpy(s.name,temp);
}
else{
int temp;
scanf("%d",&temp);
s.marks[choice1-2]=temp;
}
system("clear");
fseek(fp,-recsize,SEEK_CUR);
fwrite(&s,recsize,1,fp);
printf("record modified\n");

}while(1);
}
}
if(!flag){
printf("No Record found\nCheck the Roll\n");
}
}

//delete record
if(choice==5){
system("clear");
printf("Enter Roll to be Deleted: ");
char roll[25];
scanf("%s",roll);
rewind(fp);

FILE *ft=fopen("temp.txt","w+");
struct student s;
bool flag=false;
while(fread(&s,recsize,1,fp)!=0)
{
if(strcmp(roll,s.roll)!=0)
fwrite(&s,recsize,1,ft);
else if(strcmp(roll,s.roll)==0)
flag=true;
}
fclose(fp);
remove("record.txt");
rename("temp.txt","record.txt");
fp=ft;
if(flag)
printf("RECORD DELETED! ;)\n");
else 
printf("No Record found\nCheck the Roll\n");
}


if(choice==6)
break;

}while(1);
fclose(fp);
return 0;
}
