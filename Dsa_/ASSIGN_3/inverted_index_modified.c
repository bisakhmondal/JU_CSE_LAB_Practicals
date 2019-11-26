#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int val;
    struct node *next;
}node;

typedef struct words_lis{
    char word[30];
    struct words_lis*next;
    node * link;
}words_lis;

node*create_n(int val){
    node *n=(node*)malloc(sizeof(node));
    n->next=NULL;
    n->val=val;
    return n;
}
words_lis* create_w(char *c,int v){
    words_lis * w=(words_lis*)malloc(sizeof(words_lis));
    strcpy(w->word,c);
    w->next=NULL;
    w->link=create_n(v);
    return w;
}

void process(char * word,words_lis **head,int file_no){
    if(*head==NULL){
        *head=create_w(word,file_no);
        return;
    }
    words_lis *temp=*head;
    while(temp->next!=NULL){
        if(strcmp(temp->word,word)==0){
            node *temp1=temp->link;
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=create_n(file_no);
            return;
        }
        temp=temp->next;
    }
    temp->next=create_w(word,file_no);
    return;
}

void print(words_lis *head){
    while(head!=NULL){
        printf("word: %s  |",head->word);
        node*temp=head->link;
        while(temp!=NULL){
            printf("%d | ",temp->val);
            temp=temp->next;
        }
        printf("\n");
        head=head->next;
    }
}
int file_no=1;
int main(){

    words_lis *head=NULL;
       int ch;
    do{
    char file_name[20];
    scanf("%s",file_name);
    FILE *fp;
    fp=fopen(file_name,"r");
    char c;
    char word[30];
    int count=0;
    while((c=fgetc(fp))!=EOF){
        
        
        if(c==' '||c=='\n'){
            // if(count==0){
            //     continue;
            // }
            word[count]='\0';
            printf("%s\n",word);
            process(word,&head,file_no);
            count=0;

        }
        else {
            word[count]=c;
            count++;
        }
        
    }
    print(head);
    fclose(fp);
    printf("add another: ");
    file_no++;
    fflush(stdin);
    scanf("%d",&ch);
    }while(ch==1);
}