#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}

int main(){
    FILE *fp=fopen("6_in.txt","r"),*fu=fopen("6.sorted.txt","w");
    char s[200][30];
    int x=1;
    while(!feof(fp)){
        char c=fgetc(fp);
        if(c=='\n')
        x++;
    }
    //printf("%d\n",x);
    rewind(fp);
    for (int i = 0; i < x; i++)
    {
    fscanf(fp,"%s",s[i]);
    }

    int *a=(int *) malloc(x*sizeof(int));
    int max=0,maxi,min=40,mini;
    for (int i = 0; i < x; i++)
    {

        a[i]= strlen(s[i]);
        if(a[i]>max)
        {
            max=a[i];
            maxi=i;
        }
        if(a[i]<min){
            min=a[i];
            mini=i;
        }
    }
    printf("max_length_name: %s\nmin_length_name: %s\n",s[maxi],s[mini]);

    //sort
    int *index=(int *) malloc(x*sizeof(int));
    for(int i=0;i<x;i++){
        index[i]=i;
    }

    for(int i=0;i<x;i++){
        for(int j=i+1;j<x;j++){
            if(a[j]<=a[i])
            {swap(&a[i],&a[j]);
            swap((index+i),(index+j));
        }}
    }

    for(int i=0;i<x;i++){
        fprintf(fu,"%s\n",s[index[i]]);
    }


    
    
}