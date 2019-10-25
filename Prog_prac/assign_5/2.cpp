#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;

class book{
    string id,sln,title,author,pub;
    float price;
    bool avail;
    public:
    book(){
        avail=true;
    }
    void display(){
        cout<<" id "<<id;
        cout<<" sln "<<sln<<endl;
        cout<<"name: "<<title<<" author"<<author<<" publisher"<<pub<<endl;
    }
    void get_book(){
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter serial: ";
        cin>>sln;
        title="$";
        author="$";
        pub="$";
        price=100;
    }
    friend class book_list;
};
class node{
    public:
    book b;
    node *next;
};
node *create_book(book val){
    node* n=new node;
    n->b=val;
    n->next=NULL;
    return n;
}
class book_list{
    node *head;
    int count;
    public:
    book_list(){
        head=NULL;
        count=0;
    }
    void list_book(){
        book boi;
        boi.get_book();
        if(head==NULL){
            head=create_book(boi);
            count++;
        }
        else {
            node *temp=head;
            bool flag=true;
            while(temp->next!=NULL){
                if(temp->b.id==boi.id|| temp->b.sln==boi.sln){
                    cout<<"Same book with same copy akready exists :"<<endl;
                    flag=false;
                    break;
                }
                temp=temp->next;
            }
            if(flag){
                temp->next=create_book(boi);
            }
        }


        
    }
};

class member{
    protected:
    string id,name,mail,addr;
    public:

};
class student:public member{
    int quota;
    book taken[2];
    static int cnt;
    public:
    student(){
        quota=2;
    }
    void get_stu(){
        id=rand()%100;
        cnt++;
        name="student_"+to_string(cnt);
    }

};
int student::cnt=0;
class faculty:public member{
    int quota;
    book taken[10];
    static int cnt;
    public:
    faculty(){
        quota=10;
    }
        void get_fac(){
        id=rand()%100;
        cnt++;
        name="faculty_"+to_string(cnt);
    }


};
int faculty::cnt=0;
struct node_stu{
    student s;
    node_stu *next;
};
struct node_fac{
    faculty s;
    node_fac *next;
};
node_stu * create(student st){
    node_stu*n=new node_stu;
    n->s=st;
    n->next=NULL;
    return n;
}
node_fac * create(faculty st){
    node_fac*n=new node_fac;
    n->s=st;
    n->next=NULL;
    return n;
}
class users{
    node_stu *shead;
    node_fac *fhead;
    public:
    users(){
        shead=NULL;
        fhead=NULL;
    }
    private:
    void add_Stu(){
        student s;
        s.get_stu();
        if(shead==NULL){
            shead=create(s);
        }
        else {
            node_stu *temp=shead;
            // bool flag=true;
            while(temp->next!=NULL){
              temp=temp->next;
            }
                temp->next=create(s);
        }
        
    }
    void add_Fac(){
        faculty s;
        s.get_fac();
        if(fhead==NULL){
            fhead=create(s);
        }
        else {
            node_fac *temp=fhead;
            // bool flag=true;
            while(temp->next!=NULL){
              temp = temp->next;
            }
                temp->next=create(s);
        }
    }
    public:
    void add_member(){
        cout<<"student or faculty(S or F)"<<endl;
        char c;
        cin>>c;
        if(c=='s'||'S'){
            add_Stu();
        }
        else if(c=='F'||'f'){
            add_Fac();
        }
    }
    

};
#define today "24/10/2019"
class transaction{
    string date,member_id,book_id,sln;
    bool returned;
    public:
    transaction(){
        returned=true;
    }
    void make_transaction(){
        date=today;

    }

}


int main(int argc, char const *argv[])
{


return 0;
}