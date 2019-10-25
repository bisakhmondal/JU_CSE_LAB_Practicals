/*Store name and age of number of persons (number provided at run time). Collect the data and display
data in the ascending order of age. Implement without using structure. Write functions for memory
allocation of the list, sorting and display of data.

Author: Bisakh Mondal, roll-0018105601079 , date-08/08/19*/



#include<stdio.h>
#include<stdlib.h>
 
 void swap(int *a,int *b){
     int temp=*a;
     *a=*b;
     *b=temp;
     return;
 }

int* age_allocate(int size){
    int *age=(int *)malloc(size*sizeof(int));
    return age;
}

char** name_allocate(int size){
    char** name=(char **)malloc(size*sizeof(char*));
    for(int i=0;i<size;i++){
        name[i]=(char *)malloc(100*sizeof(char));
    }
    return name;

}

void display(int *age,int *index,char** name,int n){
   for(int i=0;i<n;i++){
       printf("age: %d | name: %s \n",age[i],name[index[i]]);
   }
   return;
}

void sort(int *age,int *index,char** name,int n){
   for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(age[i]>age[j]){
                swap(&age[i],&age[j]);
                swap(&index[i],&index[j]);
            }
        }
    }
    return;


}


int main(){
    int n;

    printf("Enter number of students data\n");
    scanf("%d",&n);

    int *age=age_allocate(n);
    char **name=name_allocate(n);

    for(int i=0;i<n;i++){
        printf("Enter Name\n");
        scanf("%s",name[i]);
        printf("Enter Age\n");
        scanf("%d",&age[i]);
    }
    
    int *index=(int *) malloc(n*sizeof(int));
    for(int j=0;j<n;j++){
        index[j]=j;
    }
    //display(age,index,name,n);

    sort(age,index,name,n);
    display(age,index,name,n);



    return 0;


}