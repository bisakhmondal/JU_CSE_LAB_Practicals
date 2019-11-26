#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

struct string {
    char c[1024];
};
typedef struct string string;
// void init(string *s,int size=1024){
// s->c=(char *)malloc(size*sizeof(char));
// }
void input(string *s){
    fflush(stdin);
    gets(s->c);
}
void print(string s){
    printf("%s",s.c);
}
int getlen(string s){
    int i=0;
    while(s.c[i]!='\0'){
        i++;
    }
    return i;
}
string concat(string s1,string s2){
// init(&op,getlen(s1)+getlen(s2)+1);
int i=getlen(s1),j=0;
while(s2.c[j]!='\0'){
s1.c[i++]=s2.c[j++];
}
s1.c[i]='\0';
return s1;
}