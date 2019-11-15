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
struct compare{
    bool operator()(student &p1,student &p2){
        return p1.get_score()>p2.get_score();
    }
};
int student::max_score=0;
int main(){
   priority_queue<student,vector<student>,compare> s_list;
   do{
       cout<<"1:add student\t2:print\t3:exit"<<endl;
       int choice;
       cin>>choice;
if(choice==1){
    student s;
    s.get();
    s_list.push(s);
}
if(choice==2){
    while(!s_list.empty()){
        student ss=s_list.top();
        ss.put();
        s_list.pop();
    }
}
if(choice>2)break;
   }while(1);
   return 0;
}