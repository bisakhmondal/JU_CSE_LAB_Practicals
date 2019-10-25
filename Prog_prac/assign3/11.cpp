#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;
class Student{
    string roll;
    string name;
    string course;
    string admission_date;
    float marks[5];
    static int nos;
    public:
    void getinput(){
        cout<<"hello applicant !"<<endl;
        cout<<"Enter your roll:  ";
        cin>>roll;

        cin.ignore();
        cout<<"Enter your name:  ";
        
         getline(cin,name);
        cout<<"Hi! "<<name<<" Enter your course: ";
        cin>>course;
        cout<<"Admission date: ";
        cin>>admission_date;
        nos++;

    
    }
    string get_roll(){
        return roll;
    }
    void getmarks(){
        cout<<"so you are about to enter your marks: "<<endl;
        loop(i,0,5){
            cout<<"marks on sub "<<i+1<<" : ";
            cin>>marks[i];

        }
    }
    static int getcount(){
        return nos;
    }

    void display(){
        cout<<"Here is your total details: "<<name<<endl;
        cout<<"---------------------------"<<endl;
        cout<<name<<endl;
        cout<<"roll: "<<roll<<endl;
        cout<<"Admission date: "<<admission_date<<endl;
        cout<<"course : "<<course<<endl;
        cout<<" --------------------------------"<<endl;
        cout<<"           MARKSHEET"<<endl;
float total=0.0;
        loop(i,0,5){
            cout<<"marks on sub "<<i+1<<" : "<<marks[i]<<endl;
            total+=marks[i];
        }
        cout<<"total: "<<total<<endl;

    }

};
int Student::nos=0;
int main(int argc, char const *argv[])
{
    vector<Student> v;

    do{

    cout<<"Enter choice to\n1:add Student basic data\n2.add_marks on student\n3:number of applicant\n4.generate_marksheet\n5. exit)\n";
    int choice;
    cin>>choice;
    if(choice==1){
        Student s;
        s.getinput();
        v.push_back(s);
    }
    if(choice==2){
        cout<<"Hey !enter the roll to add marks"<<endl;
        string s;
        cin>>s;
        bool flag=false;
        loop(i,0,v.size()){
            if(v[i].get_roll()==s){
            v[i].getmarks();
            flag=true;
            }
        }
        if(flag==false){
            cout<<"no roll found"<<endl;
        }

        
    }
    if(choice==3){
            cout<<"total student: "<<Student::getcount()<<endl;
    }
    if(choice==4){
        cout<<"Hey !enter the roll to generate marksheet: "<<endl;
        string s;
        cin>>s;
        bool flag=false;
        loop(i,0,v.size()){
            if(v[i].get_roll()==s){
                v[i].display();
            }
        }

    }

    if(choice ==5)
    break;
    cout<<"----------------------------------------"<<endl;

}while(1);




return 0;
}