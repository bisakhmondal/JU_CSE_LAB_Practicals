#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;

class employee{
    protected:
    string id,name,desig;
    float basic_pay,salary;
    public:
    // employee(){

    // }
    void gen_emp(){
        cout<<"enter id: ";
        cin>>id;
        name="Employee_"+id;
        cout<<"Enter basic_pay: ";
        cin>>basic_pay;
    }
    friend class employee_list;
};
class permanent:public employee{
    float hra,da;
public:

void gen_salary(){
    hra=0.3*basic_pay;
    da=0.8*basic_pay;
    salary=basic_pay+hra+da;
}
permanent(){
    gen_emp();
    gen_salary();   
}
};
class contractual:public employee{
    float allowance;
    public:
    void gen_salary(){
        cout<<"enter allowance: ";
        cin>>allowance;
        salary=basic_pay+allowance;
    }
    contractual(){
    gen_emp();
    gen_salary();
}
    
}; 

class employee_list{
    employee emp[100];
    int cnt;
    public:
    employee_list(){
        // emp=NULL;
        cnt=0;
    }
    bool check_id(employee p){
        loop(i,0,cnt){
            if(emp[i].id==p.id){
                return false;
            }
        }
        return true;
    }
    void gen_emp(){
        cout<<"permanent or contracual"<<endl;
        char c;
        cin>>c;
        if(c=='p'){
            permanent* p=new permanent; 
            if(check_id(*p)==true){
            emp[cnt]=*p;
            cnt++;}
            else{
                cout<<"Id already exits: "<<endl;
            }
        }
        else if(c=='c'){
            contractual*c=new contractual;
            if(check_id(*c)==true){
            emp[cnt]=*c;
            cnt++;}
            else{
                cout<<"Id already exits: "<<endl;
            }
        }
    }

    void get_salary(){
        loop(i,0,cnt){
            cout<<emp[i].name<<endl;
            cout<<"Employee id: "<<emp[i].id<<endl;
            cout<<"salary: "<<emp[i].salary<<endl;
            cout<<"--------------------------"<<endl;
        }
    }


};

int main(int argc, char const *argv[])
{
employee_list l;
cout<<"Enter total members"<<endl;
int n;
cin>>n;
loop(i,0,n){
    l.gen_emp();
}l.get_salary();


return 0;
}