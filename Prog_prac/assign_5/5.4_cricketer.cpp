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
        cin>>matches_played;
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
//      gen_cric();
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
//         gen_cric();
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
     cricketer::print();
          cout<<"Total Run: "<<total_run<<endl;
     cout<<"avg_Score: "<<avg_score<<endl;
     cout<<"wickets: "<<wickets<<endl;
     cout<<"avg_economy: "<<avg_economy<<endl;

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
        b[cnt].gen_cric();
        b[cnt].get_details();
        cout<<"Enter details of batsman"<<endl;
        c[cnt].gen_cric();
        c[cnt].get_details();
        cnt++;
    }
    void op(){
        loop(i,0,cnt){
            cout<<"Bowler details: "<<endl;
            b[i].print();
            cout<<"------------------------------"<<endl;
            cout<<"batsman details: "<<endl;
            c[i].print();
            

        }
    }
};


int main(int argc, char const *argv[])
{
vector<batsman> bat;
vector<bowler> bow;
vector<allrounder> all;
wicket_pair wp;
do{
    cout<<"1:add BATSMAN\n2:add BOWLER\n3:add ALLROUNDER\n4:add Wicket_pair\n5:print_all\n6:Done_end"<<endl;
    int choice;
    cin>>choice;
    if(choice==1){
        batsman b;
        b.gen_cric();
        b.get_details();
        bat.push_back(b);
    }
    if(choice==2){
        bowler b;
        b.gen_cric();
        b.get_details();
        bow.push_back(b);
    }
    if(choice==3){
        allrounder c;
        c.gen_cric();
        c.get_details();
        all.push_back(c);
    }
    if(choice==4){
        wp.get_details();
    }
    if(choice==5){
        cout<<"batsman: "<<endl;
        for(auto i: bat){
            i.print();
        }
        cout<<"-------------------------"<<endl;
        cout<<"\nBowler: "<<endl;
        for(auto i: bow){
            i.print();
        }
         cout<<"-------------------------"<<endl;
        cout<<"\nAllrounder: "<<endl;
        for(auto i: all){
            i.print();
        }
         cout<<"-------------------------"<<endl;
        cout<<"\nwicket_pair: "<<endl;
        wp.op();
         cout<<"-------------------------"<<endl;
    }
    if(choice==6) break;
}while(true);

return 0;
}