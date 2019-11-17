#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;

template<typename t>
class array1{
    t *a;
    int cnt;
    public:
    array1(int size=0){
        if(size!=0)
        a=new t[size];
        else a=NULL;
        cnt=size;
    }
    void find_max(){
        t maxi=a[0];
        loop(i,0,cnt){
            if(maxi<a[i]){
                maxi=a[i];
            }
        }
    cout<<maxi<<endl;
    }
    void input(){
        if (cnt==0){
            cout<<"enter number of inputs required: ";
            cin>>cnt;
            a=new t[cnt];
        }
        loop(i,0,cnt){
            cin>>a[i];
        }
    }
    void find_sum(){
        if(sizeof(a[0]==1)){
            string s="";
            loop(i,0,cnt){
                string temp(1,a[i]);
                s+=temp;
            }
            cout<<"sum of elements: "<<s<<endl;
        }else
        {
            t sum;
            loop(i,0,cnt){
                sum+=a[i];
            }
            cout<<"sum of elements: "<<sum<<endl;
        }
        
    }
    void print(){
        // cout<<typeof(a[0])<<endl;
        // cout<<t<<endl;
        string b=to_string(a[0])+to_string(a[1]);
        cout<<b<<endl;
        loop(i,0,cnt){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};

int main(int argc, char const *argv[])
{
array1<int> arr;
arr.input();
arr.find_max();
arr.find_sum();
arr.print();

return 0;
}