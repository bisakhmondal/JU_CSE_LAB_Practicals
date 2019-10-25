#include<bits/stdc++.h>
using namespace std;
void f(int a,int b){
cout<<"inside int int"<<endl;
}
void f(char a, int b){
cout<<"inside char int"<<endl;
}
int main(){
int a=5;
float b=5.6;
char c='a';
cout<<"f(int,int)"<<endl;
f(a,a);
cout<<"f(char,int)"<<endl;
f(c,a);
cout<<"f(char,char)"<<endl;
f(c,c);
cout<<"f(int,float)"<<endl;
f(a,b);
cout<<"f(float,float)"<<endl;
f(b,b);
return 0;
}
