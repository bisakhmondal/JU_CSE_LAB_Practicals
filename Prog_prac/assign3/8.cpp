#include<bits/stdc++.h>
#include<sstream>
using namespace std;
class TIME{
string hr,min,sec,ap;
public:
//constructor
TIME(){
int ch;
cout<<"enter the choice\n1:in AM/PM Format\n2.in 24 hrs\n";
cin>>ch;
if(ch==1)
inputAM();
else input24();
cout<<"---------------------------------"<<endl;
}


void inputAM(){
cout<<"enter hr min sec in 12 hr format"<<endl;
cin>>hr>>min>>sec;
cout<<"AM/PM\n";
cin>>ap;
cout<<"input recorded"<<endl;
}

void input24(){
cout<<"enter hr min sec in 24 hr format"<<endl;
cin>>hr>>min>>sec;
cout<<"input recorded"<<endl;
}


void displayAM(){
    int h;
    stringstream(hr)>>h;
    if(ap!="")
cout<<hr<<" : "<<min<<" : "<<sec<<" "<<(h>=12?"PM":"AM")<<endl;
if(ap==""){
    int x=h>12 ?h-12:h;
    cout<<x<<" : "<<min<<" : "<<sec<<" "<<(x==h?"AM":"PM")<<endl;

}
}

void display24(){
        int h;
    stringstream(hr)>>h;
    if(ap=="")
cout<<hr<<" : "<<min<<" : "<<sec<<endl;
else{
    int x=ap=="PM"?h+12:h;
        cout<<x<<" : "<<min<<" : "<<sec<<endl;
}
}

void not_sure(){
    cout<<"In 24 hr format: ";
display24();
cout<<"\nIn 12 hr format ";
displayAM();
}

void add_min(){
    int mi;
    cout<<"how much"<<endl;
    cin>>mi;
    int h,m;
    stringstream(hr)>>h;
    stringstream(min)>>m;
    h+=(m+mi)/60;
    m=(m+mi)%60;
    // cout<<h<<" "<<m;
    stringstream s1,s2;
    s1<<h;s2<<m;
    s1>>hr;s2>>min;
    
}

}
;
int main(){
TIME t;
cout<<"display result\n1:in 24 hrs\n2:in AM/PM\n3:not sure\n"<<endl;
int choice;
cin>>choice;
if(choice==1)
t.display24();
if(choice==2)
t.displayAM();
if(choice==3)
t.not_sure();
cout<<"want to add minutes?\n1.yes\n2.No\n";
int p;
cin>>p;
if(p==1){
t.add_min();
t.not_sure();
}
return 0;
}
 

