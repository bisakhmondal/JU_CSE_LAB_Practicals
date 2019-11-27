#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define num 80000
void rand_gen(FILE* fp){
    // int ini=(rand()%20)<<31;
for(int i=0;i<num;i++){
    int new=/*ini-*/rand()%200;
fprintf(fp,"%d\n",new);
// ini=new;
}
}

int main(){
    FILE *fp;
    fp=fopen("1.txt","w");
    rand_gen(fp);
}