#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define today "12/09/2019"
#define random "12/08/2008"
using namespace std;
class transact;
class balancee{
    string acc;
    int balance;
    string last_update;
    public:
    balancee()
{
    last_update=random;
}   
 friend class transact;
    void get_data(){
        cout<<"enter The account Details\n1.account _number"<<endl;
        cin>>acc;
        cout<<"Enter Balance"<<endl;
        cin>>balance;
    }
    void print(){
        cout<<"Account number: "<<acc<<endl;
        cout<<"Remaining Balance"<<balance<<endl;
        cout<<"Last Tranaction date"<<last_update<<endl;
        cout<<"------------------------------------------\n";
    }
    string get_acc(){
        return acc;
    }
};
class transact{
    string acc_no;
    string date;
    float amnt;
    char type;
    public:
    transact(){
        date=today;
    }
    void trans(vector<balancee> &b){
        cout<<"enter The account Details\n1.account _number"<<endl;
        cin>>acc_no;
        bool flag=false;
        balancee *b1;
        loop(i,0,b.size()){
            if(b[i].acc==acc_no){
                cout<<"Welcome\n your last Transaction date: "<<b[i].last_update<<endl;
                b1=&b[i];
                    flag=true;                break;
            }
        }
        if(!flag){
            cout<<"No details found ! sorry"<<endl;
            return;
        }
        cout<<"Enter amount"<<endl;
        cin>>amnt;
        cout<<"W: Withdraw D:Deposite (Select Between Two)\n";
        cin>>type;
        if(type=='D'){
        b1->balance+=amnt;
        cout<<"balance Updated"<<endl;
        }
        else{
            if(b1->balance<amnt){
                cout<<"Sorry Insufficient Fund to Continue"<<endl;
            }
            else
            {
                b1->balance-=amnt;
                cout<<"balance Updated"<<endl;
            } 
        }
        b1->last_update=date;


    }
};


int main(int argc, char const *argv[])
{

vector<balancee> b;
do{
printf("1.Create Account\t 2.print Account Details\t3.Make a Transaction\t4.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    balancee b1;
    b1.get_data();
    b.push_back(b1);
}
if(choice==2){
    cout<<"Enter account Number: ";
    string ac;
    cin>>ac;
    bool flag=false;
    loop(i,0,b.size()){
        if(b[i].get_acc()==ac){
            b[i].print();
            flag=true;
            break;
        }
    }
    if(!flag)cout<<"No account Details Found"<<endl;

}
if(choice==3)
{
    transact t;
    t.trans(b);
}

if(choice==4)
break;
printf("---------------------------------------------\n");
}while(1);



return 0;
}