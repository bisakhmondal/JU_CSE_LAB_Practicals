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
    static int get_max(){
        return max_score;
    }
    void put(){
        cout<<"Name: "<<name<<" |roll: "<<roll<<" |score: "<<score<<endl;
    }
};
bool compare(student s,student p){
    return s.get_roll()<p.get_roll();
}
int student::max_score=0;
int main(int argc, char const *argv[])
{
    vector<student> s_list;
    cout<<"Size of List: "<<s_list.size()<<endl;
    student s;
    s.get();
    s_list.push_back(s);
    cout<<"\nNow Size of List: "<<s_list.size()<<endl;
    cout<<"add another object"<<endl;
    student s2;
    s2.get();
    s_list.push_back(s2);
    cout<<"\nNow Size of List: "<<s_list.size()<<endl;
    cout<<"Max score till now: "<<student::get_max()<<endl;
    cout<<"wanna find a name? Enter substring"<<endl;
    string s1;
    cin>>s1;
    bool falg=false;
    for(auto i: s_list){
        if(i.get_name().find(s1)!=string::npos){
            falg=true;
            cout<<"string found: "<<i.get_name()<<endl;
            break;
        }
    }
    cout<<"String without any match"<<endl;
    for(auto i: s_list){
        if(i.get_name().find(s1)==string::npos){

cout<<i.get_name()<<endl;
        }
    }

    cout<<"Now sorted list: "<<endl;
    sort(s_list.begin(),s_list.end(),compare);
    for(auto i: s_list){
        i.put();
    }


    cout<<"Enter roll to delete"<<endl;
    string roll;
    cin>>roll;
    for(auto it=s_list.begin();it!=s_list.end();it++){
        if(it->get_roll()==roll){
            s_list.erase(it);
            break;
        }
    }
    cout<<"Now new list: "<<endl;
    for(auto i: s_list){
        i.put();
    }
cout<<"add another details"<<endl;
student s3;
s3.get();
s_list.push_back(s3);
    cout<<"another list "<<endl;
    vector<student> ss;
    ss.insert(ss.end(),s_list.begin(),--s_list.end());
    ss.insert(ss.end(),s_list.begin(),s_list.end());

    cout<<"New list after combining"<<endl;
    for(auto i: ss){
        i.put();
    }

return 0;
}