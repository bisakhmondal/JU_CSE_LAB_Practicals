#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;

class sub_i{
    string name;
    string code;
    public:
    void get_info(){
        cout<<"Enter sub name: ";
        cin>>name;
        cout<<"Enter sub code: ";
        cin>>code;
    }
    friend class subs;
    friend class students;
};
class subs{
    sub_i s[15];
    static int n;
    public:
    subs(){
        n=0;
    }
    static int get_n(){
     return n;   
    }
    void get_data(){
        cout<<"Enter number of subs: ";
        cin>>n;
        loop(i,0,n){
            s[i].get_info();
        }
    }
    void print_i(int i){
        cout<<"name: "<<s[i].name<<" code: "<<s[i].code<<endl;
    }
    friend class students;
};
int subs::n;
class student{
    string roll,name,phone;
    int chk[15];
    public:
    student(){
        memset(chk,0,sizeof(chk));
    }
void get_info(subs s){
    cout<<"roll ";
    cin>>roll;
    cout<<"name ";
    cin>>name;
    // cout<<"phone ";
    // cin>>phone;
    phone=(rand()>>10);

    int n=subs::get_n();

    cout<<"choose between subs: "<<endl;
    loop(i,0,n){
        char c;
        s.print_i(i);
        cout<<"Enter Y or y to add else type anything"<<endl;
        cin>>c;
        if(c=='Y' || c=='y'){
            chk[i]=1;
        }

    }


}
friend class students;
};
class students{
    student s[100];
    int n;
    public:
    students(){
        n=0;
    }
    void get_data(subs su){
        cout<<"Enter Number of students: ";
        int p;
        cin>>p;
        n=p;
        loop(i,0,p){
            s[i].get_info(su);
        }
    }
    void get_subjects(subs su){
        string roll;
        cout<<"Enter roll to search: "<<endl;
        cin>>roll;
        bool flag=false;
        loop(i,0,n){
            if(s[i].roll==roll){
                flag=true;
                loop(j,0,15){
                    if(s[i].chk[j]==1){
                        su.print_i(j);
                    }
                }
                break;
            }
            
        }
        if(flag==false){
            cout<<"No matching roll found"<<endl;
        }
    }
    void get_roll(subs su){
        string sub_c;
        cout<<"enter the subject code"<<endl;
        cin>>sub_c;
        int i=-1;
        loop(j,0,subs::get_n()){
            if(su.s[j].code==sub_c){
                i=j;
                break;
            }

        }
        if(i==-1){
            cout<<"No match found \n";
            return;
        }
        loop(j,0,n){
            if(s[j].chk[i]==1){
                cout<<s[j].roll<<endl;
            }
        }

    }
//     students(){
//         cout<<"Enter number of students: ";
//         int siz;
//         cin>>siz;
//         size=siz;
//         if(size!=0) stud=new student[size];
//         else stud=NULL;
//         loop(i,0,size){
//             stud[i].get_info();
//         }
//     }

//  friend class st_list;
//  friend class final;

    
};

int main(int argc, char const *argv[])
{
subs s;
s.get_data();
students st;
st.get_data(s);
st.get_roll(s);
st.get_subjects(s);

return 0;
}