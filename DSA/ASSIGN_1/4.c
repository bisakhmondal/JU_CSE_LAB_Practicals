#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


int main(){

FILE *fp;
fp=fopen("4_op.txt","w");

srand(time(NULL));
int range=100000;
int a[100000]={0};
int cnt=0;
while(cnt<range){
    int t=rand()%range +1;
    if(a[t-1]==0){
        cnt++;
        a[t-1]=1;
        fprintf(fp,"%d\n",t);
    }
}
fclose(fp);



return 0;}


