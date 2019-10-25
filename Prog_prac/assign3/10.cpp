#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define init ios_base::sync_with_stdio(false);cin.tie(NULL);
#define case int t; cin>>t; while(t--)
using namespace std;
class node;
class APPLICANT{
    int id;
    string name;
    int score;
    static int nos;
    static int id_cache;
    public:
    void get_input(){
        cout<<"hello applicant ! your application id: "<<id_cache<<endl;
        cin.ignore();
        cout<<"Enter your name:  ";
        
         getline(cin,name);
        // cin>>name;
        cout<<"Hi "<<name<<" !enter your marks:  ";
        cin>>score;

        id=id_cache;
        id_cache+=1;
        nos+=1;

    }
    string get_name(){
       return name;
    }
    static int getsize(){
        return nos;
    }
    void display(){
        cout<<"-----------------------------------------------"<<endl;
        cout<<"Application id: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Score: "<<score<<endl;
                cout<<"-----------------------------------------------"<<endl;

    }

};
class node{
    public:
    APPLICANT s;
    node*prev,*next;
};
node* newnode(){
    APPLICANT s1;
    node* n= new node;
    s1.get_input();
    n->s=s1;
    n->prev=n->next=NULL;
    return n;


}
int APPLICANT::nos=0;
int APPLICANT::id_cache=abs(rand()<<6);
int main(int argc, char const *argv[])
{
// APPLICANT s;
node * head=NULL;

do{

    cout<<"Enter choice to\n1:add Applicant\n2:search applicant\n3:number of applicant\n4. exit)\n";
    int choice;
    cin>>choice;
    if(choice==1){
        if(head==NULL){ 
            head=newnode();
            // head->next->prev=heelse ad;
        }
        else{
            head->next=newnode();
            head->next->prev=head;
            head=head->next;
        }
    }
    if(choice==2){
        cout<<"enter Name: ";
        string s;
        cin>>s;
        node *temp=head;
        while(temp!=NULL){
            if(temp->s.get_name()==s)
            {
                    temp->s.display();
            }
            temp=temp->prev;
        }
    }
    if(choice==3){
            cout<<"total aplicant: "<<APPLICANT::getsize()<<endl;
    }
    if(choice ==4)
    break;
    cout<<"----------------------------------------"<<endl;

}while(1);



return 0;
}