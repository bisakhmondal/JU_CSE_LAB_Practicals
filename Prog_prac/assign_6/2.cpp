#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;
class student{
string roll,name;
float score;
public:
void gen_info(){
    cout<<"Enter details: "<<endl;
    cout<<"roll: ";
    cin>>roll;
    cout<<"name: ";
    cin>>name;
    cout<<"marks: ";
    cin>>score;
}
void print(){
    cout<<"name: "<<name<<endl;
    cout<<"Roll: "<<roll<<endl;
    cout<<"Score: "<<score<<endl;
}
friend class student_list;
};

class student_list{
    student *s;
    int cnt;
    public:
    student_list(int size=0){
        if(size==0){
            s=NULL;
        }else{
            s=new student[size];
        }
        cnt=size;

    }
    student & operator [](int n){
        if(n>=cnt)
        throw "range is out of Bound:";
        return s[n];
    }
};


int main(int argc, char const *argv[])
{
student_list s(10);
int idx;
cout<<"enter index to search"<<endl;
cin>>idx;
try{
s[1].gen_info();
s[idx].print();
}catch(char const *mesg){
    cerr<<mesg<<endl;
    cout<<"but the program flow is uninterrupted"<<endl;
}

s[1].print();

return 0;
}