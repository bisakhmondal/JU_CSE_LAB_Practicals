#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    FILE* fp;
    fp=fopen("5_op.txt","w");

char a[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int size=sizeof(a)/sizeof(a[0])-1;


int i=0;
srand(time(NULL));
for(;i<100000;i++){

char p[10];

int j=0;
for(;j<10;j++){
int z=rand()%size;
char q[1];
p[j]=a[z];
//q[1]='\0';
//strcat(p,q);

}
int n=0;
for(;n<10;n++){
fprintf(fp,"%c",p[n]);}
fprintf(fp,"\n");
}
return 0;
}
