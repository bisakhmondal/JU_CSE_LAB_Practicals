/*Implement Q.5 using structure.
Author: Bisakh Mondal, roll-0018105601079 , date-08/08/19*/


#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[50];
    int age;
};


struct student* allocate(int n){
struct student*  s=(struct student*)malloc(n*sizeof(struct student));

return s;
}

void sort(struct student *s,int n){
    struct student temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i].age>s[j].age){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }

    return;
}
void display(struct student *s,int n){
    for(int i=0;i<n;i++){
        printf("age :%d | Name: %s\n",s[i].age,s[i].name);
    }
    return;
}

int main(){
 int n;
printf("Enter number of students data\n");
scanf("%d",&n);
struct student *s=allocate(n);

for(int i=0;i<n;i++){

    printf("Enter Name ");
    scanf("%s",s[i].name);
     printf("Enter Age ");
    scanf("%d",&s[i].age);
}

sort(s,n);
display(s,n);
return 0;
}

