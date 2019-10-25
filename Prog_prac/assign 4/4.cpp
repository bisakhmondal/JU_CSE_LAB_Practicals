#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define init ios_base::sync_with_stdio(false);cin.tie(NULL);
#define case int t; cin>>t; while(t--)
using namespace std;

class stringg{
    char *str;
    int len;
    public:
    friend istream& operator >>(istream & i,stringg &s);
    friend ostream& operator <<(ostream & o,stringg &s);
    int get_len(){
        return len;
    }
    stringg(const stringg &s1){
        len=s1.len;
        str=new char[len+1];
        loop(i,0,len)
        str[i]=s1.str[i];
        str[len]='\0';
    }
    stringg(){}
    stringg(const char *s){
        int len=0;
        while(s[len]!='\0'){
            len++;
        }
        this->len=len;
        str=new char[len+1];
        loop(i,0,len)
        str[i]=s[i];
        str[len]='\0';

    }
    stringg& operator +(stringg &s){
        int size=s.len+len;
        stringg *s1=new stringg;
        s1->len=size;
        s1->str=new char[size+1];
        loop(i,0,len){
            s1->str[i]=str[i];
        }
        loop(i,0,s.len){
            s1->str[len+i]=s.str[i];
        }
        s1->str[size]='\0';
        return *s1;
    }
        bool operator ==(stringg &s1){
        if(len!=s1.len)
        return false;
        loop(i,0,len){
            if(str[i]!=s1.str[i]){
                return false;
            }
        }
        return true;
        
    }
    ~stringg(){
        delete [] str;
    }


};
istream& operator >>(istream & i,stringg &s){
char *c=new char[150];
i.getline(c,150);
int j=0;
loop(i,0,150){
    if(c[i]=='\0')
    break;
    j++;
}

s.len=j;
s.str=new char[j+1];
loop(i,0,j){
    s.str[i]=c[i];
}
s.str[j]='\0';
delete [] c;
return i;
}
ostream& operator <<(ostream & o,stringg &s){
    o<<s.str;
    o<<"\n";
    return o;
}

int main(int argc, char const *argv[])
{
    stringg s1,s2;
    cout<<"string 1: ";
    cin>>s1;
    cout<<"string 2: ";
    cin>>s2;
    // string s3;
    cout<<"string after concat : ";
    cout<<s1+s2;
    int z=s1==s2;
    cout<<"using strig compare : "<<(z==0?"false":"true")<<endl;

    char s[50];
    cout<<"overload from array pointer: ";
   cin>>s;
   stringg s4(s);
   cout<<s4;



return 0;
}