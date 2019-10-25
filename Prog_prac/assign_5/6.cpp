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
class node {
    public:
    sub_i s;
    node * next;
};
node* create(){
    node *n=new node;
    n->s.get_info();
    n->next=NULL;
    return n;
};

class subs{
    node *s;
    static int n;
    public:
    subs(){
        s=NULL;
        n=0;
    }
    static int get_n(){
     return n;   
    }
    void get_data(){
        cout<<"Enter number of subs: ";
        cin>>n;
        s=create();
        node * temp=s;
        loop(i,1,n){
            temp->next=create();
            temp=temp->next;

        }
    }
    void print_i(int i){
        node *temp=s;
i--;
        while(i--&& !temp->next){
            temp=temp->next;
        // cout<<"name: "<<s[i].name<<" code: "<<s[i].code<<endl;
        }
        cout<<"name: "<<temp->s.name<<"code: "<<temp->s.code<<endl;
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
class node1{
    public:
    student s;
    node1 *next;


};
node1 *create1(subs su){
    node1 *n=new node1;
    n->s.get_info(su);
    n->next=NULL;
    return n;
}
class students{
    // student s[100];
    node1 *s;
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
        s=create1(su);
        node1*temp=s;
        loop(i,1,p){
            // s[i].get_info(su);
            temp->next=create1(su);
            temp=temp->next;
        }
    }
    void get_subjects(subs su){
        string roll;
        cout<<"Enter roll to search: "<<endl;
        cin>>roll;
        bool flag=false;
        node1 *temp=s;
        while(temp->next==NULL){
            if(temp->s.roll==roll){
                flag=true;
                loop(j,0,15){
                    if(temp->s.chk[j]==1){
                        su.print_i(j);
                    }
                }
                break;
            }
            temp=temp->next;
            
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
        node *temp=su.s;
        loop(j,0,subs::get_n()){
            if(temp->s.code ==sub_c){
                i=j;
                break;
            }
            temp=temp->next;
        }
        if(i==-1){
            cout<<"No match found \n";
            return;
        }
        node1 *temp2=s;
        loop(j,0,n){
            if(temp2->s.chk[i]==1){
                // cout<<s[j].roll<<endl;
                //
                cout<<temp2->s.roll<<endl;
            }
            temp2=temp2->next;
        }

    }
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