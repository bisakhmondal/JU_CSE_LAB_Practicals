#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define bool int
#define true 1
#define false 0
// #include<stdbool.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
int file_no=0;
struct index{
    char c[50];
    int a[5];
    struct index* next;
};
#define index struct index
// typedef struct index index;
index* create(char *cc){
    index* n=(index*)malloc(sizeof(index));
    strcpy(n->c,cc);
    loop(i,0,5){
        n->a[i]=0;
    }
    n->next=NULL;
    return n;
}
void read_file(index **head){
    printf("Enter file name: ");
    char c[50];
    scanf("%s",c);
    FILE *fp=fopen(c,"r+");
   if(fp==NULL){
       printf("file openning error\n");
   }
   else{
    while(!feof(fp)){
        char pick[50];
        bool flag=false;
        fscanf(fp,"%s",pick);
        printf("%s",pick);
        if(feof(fp))
        break;
        // if(*head==NULL){
        //     *head=create(pick);
        //     (*head)->a[file_no]=1;
        //     flag=true;
        // }
        // index* temp=*head;
        
        // while(temp->next!=NULL && flag==false){
        //     if(strcmp(temp->c,pick)==0){
        //         flag=true;
        //         temp->a[file_no]=1;
        //     }
        // }
        // if(flag==false){
        //     temp->next=create(pick);
        //     temp->a[file_no]=1;
        // } 
        fflush(stdin);  
    }
    printf("\nFile read complete\n");
    if(fp!=NULL)fclose(fp);
    file_no++;
   }
}
void print(index*head){
    while(head!=NULL){
        printf("String: %s\t",head->c);
        loop(i,0,sizeof(head->a)/sizeof(head->a[0])){
            printf("%d ",head->a[i]);
        }
        printf("\n");
        head=head->next;
    }
}

int main(){
    index *head=NULL;
    do{
        printf("1: Read file\t 2: print\t 3: exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:read_file(&head);
            break;
            case 2:
            print(head);
            break;
            case 3:
            exit(0);
        }
    }while(true);
}