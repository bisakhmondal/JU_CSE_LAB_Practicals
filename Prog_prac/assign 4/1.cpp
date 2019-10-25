#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define today "12/09/2019"
#define random "12/08/2008"
using namespace std;
class withdraw;
class account{
    string acc;
    int balance;
    string last_update;
    public:
    account()
{
    last_update=random;
}   
 friend class withdraw;
    void get_data(vector<account>b){
        cout<<"enter The account Details\n1.account _number"<<endl;
        cin>>acc;
        for(auto i:b){
            if(i.acc==acc)
            {
                cout<<"account Number already exists"<<endl;
                return;
            }
        }
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
class withdraw{
    string acc_no;
    string date;
    float amnt;
    public:
    withdraw(){
        date=today;
    }
    void trans(vector<account> &b){
        cout<<"enter The account Details\n1.account _number"<<endl;
        cin>>acc_no;
        bool flag=false;
        account *b1;
        loop(i,0,b.size()){
            if(b[i].acc==acc_no){
                cout<<"Welcome\n your last transaction date: "<<b[i].last_update<<endl;
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

            if(b1->balance<amnt){
                cout<<"Sorry Insufficient Fund to Continue"<<endl;
            }
            else
            {
                b1->balance-=amnt;
                cout<<"balance Updated"<<endl;
            } 
        b1->last_update=date;


    }
};


int main(int argc, char const *argv[])
{

vector<account> b;
do{
printf("1.Create Account\t 2.Search Account Details\t3.Make a withdraw\t4.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    account b1;
    b1.get_data(b);
    b.push_back(b1);
}
if(choice==2){
    cout<<"Enter account Number: ";
    string ac;
    cin>>ac;
    bool flag=false;
    for(auto i:b){
        if(i.get_acc()==ac){
            i.print();
            flag=true;
            break;
        }
    }
    if(!flag)cout<<"No account Details Found"<<endl;

}
if(choice==3)
{
    withdraw t;
    t.trans(b);
}

if(choice==4)
break;
printf("---------------------------------------------\n");
}while(1);



return 0;
}