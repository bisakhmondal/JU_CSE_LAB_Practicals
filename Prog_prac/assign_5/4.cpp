#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;
class cricketer{
    protected:
    string name,dob;
    int matches_played;
    public:
    void gen_cric(){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"DOB: ";
        cin>>dob;
        cout<<"total match played: ";
    }
    void print(){
        cout<<name<<endl;
        cout<<"DOB: "<<dob<<endl;
        cout<<"matches played: "<<matches_played<<endl;

    }
};
class batsman:virtual public cricketer{
    protected:
 int total_run;
 float avg_score;
 public:
 void get_details(){
     gen_cric();
     cout<<"Enter total Run: ";
     cin>>total_run;
     cout<<"avg_Score: ";
     cin>>avg_score;
 }
 void print(){
     cricketer::print();
     cout<<"Total Run: "<<total_run<<endl;
     cout<<"avg_Score: "<<avg_score<<endl;

 }

};
class bowler:virtual public cricketer{
    protected:
    int wickets;
    float avg_economy;
    public:
    void get_details(){
        gen_cric();
     cout<<"Enter wickets: ";
     cin>>wickets;
     cout<<"avg_economy: ";
     cin>>avg_economy;
 }
 void print(){
     cricketer::print();
     cout<<"wickets: "<<wickets<<endl;
     cout<<"avg_economy: "<<avg_economy<<endl;

 }

};
class allrounder:public batsman,public bowler{
    public:
    void get_details(){
     bowler::get_details();
     batsman::get_details();
 }
 void print(){
     batsman::print();
     bowler::print();
 }
};

class wicket_pair{
    bowler b[100];
    batsman c[100];
    int cnt;
    public:
    wicket_pair(){
        cnt=0;
    }
    void get_details(){
        cout<<"Enter details of bowler"<<endl;
        b[cnt].get_details();
        cout<<"Enter details of batsman"<<endl;
        c[cnt].get_details();
    }
    void op(){
        loop(i,0,cnt){
            cout<<"Bowler details: "<<endl;
            b[i].print();
            cout<<"batsman details: "<<endl;
            c[i].print();
            cout<<"------------------------------"<<endl;

        }
    }
};


int main(int argc, char const *argv[])
{
vector<batsman> bat;
vector<bowler> bow;
vector<allrounder> all;
vector<wicket_pair> wp;
do{
    cout<<"1:BAT\n2:BOWL\n3:ALL\n4:Wicket_pair"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
        batsman b;
        b.get_details();
        bat.push_back()
    }
}

return 0;
}