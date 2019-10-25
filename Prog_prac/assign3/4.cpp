#include<bits/stdc++.h>
using namespace std;

float tax(float income,float taxrate=10.0){
return (income*taxrate)/100.0;}

int main(){
cout<<"Enter income"<<endl;
float income,taxrate;
cin>>income;
cout<<"have any income rate: 1:true 2:go with default(10%)"<<endl;
int i;
cin>>i;
if(i==1)
{
cout<<"so enter taxrate"<<endl;
cin>>taxrate;
cout<<"tax: "<<tax(income,taxrate)<<endl;
}
else cout<<"tax: "<<tax(income)<<endl;
return 0;
}
