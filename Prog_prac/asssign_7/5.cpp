#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define case int t; cin>>t; while(t--)
using namespace std;
class student{
    string roll;
    string name;
    int score;
    static int max_score;
    public:
    void get(){
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter roll: ";
        cin>>roll;
        cout<<"Enter Score: ";
        cin>>score;
        max_score=max(max_score,score);
    }
    string get_name(){
        return name;
    }
    string get_roll(){
        return roll;
    }
    int get_score(){
        return score;
    }
    static int get_max(){
        return max_score;
    }
    void put(){
        cout<<"Name: "<<name<<" |roll: "<<roll<<" |score: "<<score<<endl;
    }
};
int student::max_score=0;

int main(){
    map<string,int> mp;
    do{
        cout<<"1:Enter roll and score\t2:print\t3:exit"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
            string roll;
            int score;
            cout<<"Enter roll: ";
            cin>>roll;
            cout<<"Enter score: ";
            cin>>score;
            mp.insert(make_pair(roll,score));
        }
        if(choice==2){
            for(auto i:mp){
                cout<<"Roll: "<<i.first<<" "<<" |score: "<<i.second<<endl;
            }
        }
        if(choice==3)
        break;

    } while(1);
    return 0;
}