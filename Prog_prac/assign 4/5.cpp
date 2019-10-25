#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;
class stringg{
    int len;
    char *str;
    int *ref_count;
    public:
    stringg(int size=0){
        len=size;
        if(len==0){str=NULL;
        ref_count=NULL;
        }
        else{
            str=new char[len+1];

            ref_count=new int;
            *ref_count=1;
            // cout<<"here"<<endl;
        }
    }
    stringg(const stringg &s){
        len=s.len;
        str=s.str;
        *ref_count+=1;
        cout<<*ref_count<<endl;
    }
    ~stringg(){
        if(str!=NULL)
    *ref_count--;
    if(*ref_count==1)
    {
        delete [] str;
        delete ref_count;
    }
    }
};

int main(int argc, char const *argv[])
{
stringg s(10);
// cout<<1;
{stringg s1=s;
// cout<<1;
}
stringg s2=s;

return 0;
}