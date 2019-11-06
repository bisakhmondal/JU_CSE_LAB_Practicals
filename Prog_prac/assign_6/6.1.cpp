#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
string add_file(int a=0){
        if(a==0)
        cout<<"Enter book file_name: ";
        if(a==1)
        cout<<"Enter student file_name: ";
        if(a==2)
        cout<<"Enter faculty file_name: ";
        if(a==3)
        cout<<"Enter transaction file_name: ";
        

        string s;
        cin>>s;
        // file_name=s;
        return s+".DAT";
    }
void overwrite(){
    ofstream o;
    o.open("stu.DAT");
    o.close();
    o.open("fac.DAT");
    o.close();
    o.open("tran.DAT");
    o.close();
    o.open("books.DAT");
    o.close();
    return;
}


class book{
char id[20],author[20],name[30];
int sln;
float price;
bool status;
// int sln_gen;
public:
book(){
  status=true;  // sln_gen=0;
}
// int get_sln(){
//     return sln_gen;
// }
void get(){
    cout<<"Enter Name: ";
    cin.ignore();
    // cin.sync();
    // fflush(stdin);
    cin.getline(name,30);
    cout<<"Author: ";
    // cin.ignore();
    // fflush(stdin);
    cin.getline(author,20);
    cout<<"ID: ";
    // fflush(stdin);
    cin>>id;
    // cout<<"Enter price: ";
    // cin>>price;
}
void put(){
    cout<<"Title: "<<name<<" | author: "<<author<<" | ID: "<<id<<" | sln: "<<sln<<" |price: "<<price<<" |status: ";
    (status==true)?cout<<"Not issued"<<endl:cout<<"issued"<<endl;
}
friend class book_list;
};

class member{
    protected:
    char name[20],id[20],email[20];
    char  issued_books[10][30];
    int issue;
    public:
    void get(){
        cout<<"Enter Name: ";
    cin.ignore();
    cin.getline(name,20);
    cout<<"Enter id: ";
    cin>>id;
    cout<<"email: ";
    cin>>email;
    }
    virtual void put(){
        cout<<"Name: "<<name<<" |Id: "<<id<<" |email: "<<email;
    }
};
class student:public member{
    public:
    student(){
        issue=2;
    }
    void put(){
        member::put();
        cout<<" |issue_left: "<<issue<<endl;
        if(issue!=2){
            cout<<setw(20)<<"issued books(id#sln)"<<endl;
            loop(i,0,2-issue){
                    cout<<issued_books[i]<<endl;
            }
        }
    }
    friend class member_list;
};
class faculty:public member{
    public:
    faculty(){
        issue=10;
    }
    void put(){
        member::put();
        cout<<" |issue_left: "<<issue<<endl;
        if(issue!=10){
            cout<<setw(20)<<"issued books(id#sln)"<<endl;
            loop(i,0,10-issue){
                    cout<<issued_books[i]<<endl;
            }
        }
    }
    friend class member_list;
};


class member_list{
    static string st_file;
    static string fac_file;
    static unordered_map <string,pair<int,bool> > id_issue;
    public:

    static int check_id(char *id){
        if(id_issue[id].second==false){
            return -2;
        }
        if(id_issue[id].first==0){
            return -1;
        }
        id_issue[id].first--;
         return 1;
    }
    static void issue(char *mem_id,char *book_id,int sln){
        cout<<"Faculty(F) or student(S) ";
        char choice;
        cin>>choice;
        fstream op;
        if(choice=='f'||choice=='F'){
            if(fac_file==""){
                cout<<"\nadd file first\n";
            fac_file=add_file(2);
            }
            op.open(fac_file,ios::in|ios::out|ios::ate|ios::binary);
            if(op.fail()){
            cout<<"File openning error";
            exit(2);
            }
            op.seekg(0);
            faculty f;
            bool flag=false;
            while(op.read((char* )&f,sizeof f)){
                if(strcmp(f.id,mem_id)==0){
                    flag=true;
                    op.seekp(-sizeof(f),ios::cur);
                    string s=string(book_id)+"#"+to_string(sln);
                    char c[s.length()+1];
                    strcpy(c,s.c_str());
                    strcpy(f.issued_books[10-f.issue],c);
                    f.issue--;
                    op.write((char* )&f,sizeof f);
                    op.close();
                    return;
                }
            }
            return ;
        }
        if(choice=='s'||choice=='s'){
            if(st_file==""){
                cout<<"\nadd file first\n";
            st_file=add_file(1);
            }
            op.open(st_file,ios::in|ios::out|ios::ate|ios::binary);
            op.seekg(0);
            student f;
            bool flag=false;
            while(op.read((char* )&f,sizeof f)){
                if(strcmp(f.id,mem_id)==0){
                    flag=true;
                    op.seekp(-sizeof(f),ios::cur);
                    string s=string(book_id)+"#"+to_string(sln);
                    char c[s.length()+1];
                    strcpy(c,s.c_str());
                    strcpy(f.issued_books[2-f.issue],c);
                    f.issue--;
                    op.write((char* )&f,sizeof f);
                    op.close();
                    return;
                }
            }
        }
    }

    static int return_(char *mem_id,char *book_id,int sln){
        cout<<"Faculty(F) or student(S) ";
        char choice;
        cin>>choice;
        fstream op;

        if(choice=='f'||choice=='F'){
            if(fac_file==""){
                cout<<"\nadd file first\n";
            fac_file=add_file(2);
            }
            op.open(fac_file,ios::in|ios::out|ios::ate|ios::binary);
                    if(op.fail()){
            cout<<"File openning error";
            exit(2);
        }
            op.seekg(0);
            faculty f;
            bool flag=false;
            while(op.read((char* )&f,sizeof f)){
                if(strcmp(f.id,mem_id)==0){
                    
                    op.seekp(-sizeof(f),ios::cur);
                    string s=string(book_id)+"#"+to_string(sln);
                    char c[s.length()+1];
                    strcpy(c,s.c_str());
                    loop(i,0,10-f.issue){
                        if(strcmp(f.issued_books[i],c)==0){
                            flag=true;
                            swap(f.issued_books[i],f.issued_books[(10-f.issue)-1]);
                            f.issue++;
                            op.write((char* )&f,sizeof f);
                    op.close();
                    return 1;
                        }
                    }
                    
                }
            }
            op.close();
            return -1;
        }
        if(choice=='s'||choice=='S'){
            if(fac_file==""){
                cout<<"\nadd file first\n";
            st_file=add_file(1);
            }
            op.open(st_file,ios::in|ios::out|ios::ate|ios::binary);
            op.seekg(0);
            student f;
            bool flag=false;
            while(op.read((char* )&f,sizeof f)){
                if(strcmp(f.id,mem_id)==0){
                    
                    op.seekp(-sizeof(f),ios::cur);
                    string s=string(book_id)+"#"+to_string(sln);
                    char c[s.length()+1];
                    strcpy(c,s.c_str());
                    loop(i,0,2-f.issue){
                        if(strcmp(f.issued_books[i],c)==0){
                            flag=true;
                            swap(f.issued_books[i],f.issued_books[2-f.issue-1]);
                            f.issue++;
                            op.write((char* )&f,sizeof f);
                    op.close();
                    return 1;

                        }
                    }
    
                    op.close();
                    return -1;
                }
            }
        }

        return -1;
    }
    member_list(){
        st_file="";
        fac_file="";
    }
    private:
    template<class t>
    void utility2(t f,string s){
      ifstream op;
        op.open(s,ios::in|ios::binary);
                if(op.fail()){
            cout<<"File openning error";
            exit(2);
        }
        while(op.read((char*)&f,sizeof(f))){
            id_issue[f.id].second=true;
            id_issue[f.id].first=f.issue;
        }
        op.close();

    }

    public:
    void load_map(){
        faculty f;
        student s;
                    if(fac_file==""){
                cout<<"\nadd file first\n";
            fac_file=add_file(2);
            }
            utility2(f,fac_file);

                        if(st_file==""){
                cout<<"\nadd file first\n";
            st_file=add_file(1);
            }
            utility2(s,st_file);
    }


    void add_member(){
        if(id_issue.empty()){
            load_map();
        }
        cout<<"Faculty(F) or student(S) ";
        char choice;
        cin>>choice;
        fstream op;

        if(choice=='f'||choice=='F'){
            if(fac_file==""){
                cout<<"\nadd file first\n";
            fac_file=add_file(2);
            }
            op.open(fac_file,ios::in|ios::out|ios::ate|ios::binary);
                    if(op.fail()){
            cout<<"File openning error";
            exit(2);
            }
            faculty f;
            f.get();
            if(id_issue[f.id].second==false){
                id_issue[f.id].second=true;
            id_issue[f.id].first=f.issue;
            }
            else{
                cout<<"\nSame id already exists\n\n";
                op.close();
                return;
            }
            op.write((char*)&f,sizeof f);
            op.close();
            
            return;
            
        }
        if(choice=='s'||choice=='S'){
            if(st_file==""){
                cout<<"\nadd file first\n";
            st_file=add_file(1);
            }
            op.open(st_file,ios::in|ios::out|ios::ate|ios::binary);
                    if(op.fail()){
            cout<<"File openning error";
            exit(2);
        }
            student s;
            s.get();

            if(id_issue[s.id].second==false){
                id_issue[s.id].second=true;
            id_issue[s.id].first=s.issue;
            }
            else{
                cout<<"\nSame id already exists\n";
                op.close();
                return;
            }
            op.write((char*)&s,sizeof s);
            op.close();
            return;
        }

    }

    private:
    template<class t>
    void utility(t f,string s){
        ifstream op;
        op.open(s,ios::in|ios::binary);

                if(op.fail()){
            cout<<"File openning error";
            exit(2);
        }
        while(op.read((char*)&f,sizeof(f))){
            f.put();
        }
        op.close();
    }

    public:
    void show_member(){
        cout<<setw(15)<<"\n\nSTUDENTS\n\n";

        if(st_file==""){
            cout<<"\nadd file first\n";
            st_file=add_file(1);
        }
        
        student s;
        faculty f;
        utility(s,st_file);

        cout<<setw(15)<<"\n\nFACULTIES\n\n";

        if(fac_file==""){
            cout<<"\nadd file first\n";
            fac_file=add_file(1);
        }
        utility(f,fac_file);


    }

};

string member_list::fac_file;
string member_list::st_file;
unordered_map <string,pair<int,bool> > member_list::id_issue;

class book_list{
    static string file_name;
    // fstream op;
    static unordered_map<string,pair<int,vector<int> > > id_sl; // string is id: pair.first= total sln issud, vector is available books
    public:
    static void book_ret(char *id,int sln){
        fstream op;
        id_sl[id].second.push_back(sln);
        op.open(file_name,ios::in|ios::out|ios::ate|ios::binary);
        op.seekg(0);
        book b;
        while(op.read((char*)&b,sizeof b)){
            if(strcmp(b.id,id)==0 && b.sln==sln){
                op.seekp(-sizeof(b),ios::cur);
                b.status=true;
                op.write((char*)&b,sizeof b);
                break;
                
            }
        }
        op.close();
    }
    static int get_sln(char *id){
        if(id_sl[id].first==0){
            return -2;
        }
        if(id_sl[id].second.empty()){
            return -1;
        }
        int c= id_sl[id].second[id_sl[id].second.size()-1];
        id_sl[id].second.pop_back();
        fstream op;
        op.open(file_name,ios::in|ios::out|ios::ate|ios::binary);
        op.seekg(0);
        book b;
        while(op.read((char*)&b,sizeof b)){
            if(strcmp(b.id,id)==0 && b.sln==c){
                op.seekp(-sizeof(b),ios::cur);
                b.status=false;
                op.write((char*)&b,sizeof b);
                break;
                
            }
        }
        op.close();

        return c;


    }
    book_list(string s){
        file_name=s+".DAT";
    }
    book_list(){
        file_name="";
    }
    void load_map(){
        if(file_name==""){
        cout<<"add file first\n "<<endl;
        file_name=add_file();
        }
        ifstream o1;
        o1.open(file_name,ios::in|ios::binary);
                if(o1.fail()){
            cout<<"File openning error";
            exit(2);
        }
        book b1;
        while(o1.read((char*)&b1,sizeof b1 )){
            id_sl[b1.id].first=max(id_sl[b1.id].first,b1.sln);
            if(b1.status==true){
                id_sl[b1.id].second.push_back(b1.sln);
            }
        }
        o1.close();

    }
    void add_book(){

        if(file_name==""){
        cout<<"add file first\n "<<endl;
        file_name=add_file();
        }

        if(id_sl.empty()){
            load_map();
        }
        fstream op;
        op.open(file_name,ios::in|ios::out|ios::ate|ios::binary);
        if(op.fail()){
            cout<<"fatal error"<<endl;
            return;
        }
        book b;
        b.get();
        b.sln=++id_sl[b.id].first;
        id_sl[b.id].second.push_back(b.sln);
        op.write((char*)&b,sizeof b);
        op.close();


    }

    void show_books(){
                if(file_name==""){
        cout<<"add file first\n "<<endl;
        file_name=add_file();
        }
        cout<<"Enter serial no or For all books type all: ";
        string t;
        cin>>t;
        ifstream ip;
        book b;
        ip.open(file_name,ios::in|ios::binary);
        if(ip.fail()){
            cout<<"File openning error";
            exit(2);
        }
        if(t=="all"||"ALL"){
            while(ip.read((char*)&b,sizeof b)){
                b.put();
            }
        }
        else{
            while(ip.read((char*)&b,sizeof b)){
                if(t==string(b.id))
                b.put();
            }
        }
        ip.close();
    }
//     void issue_books(){
// ;
//     }
};
string book_list::file_name;
unordered_map<string,pair<int,vector<int> > > book_list::id_sl;
class transaction{
    char mem_id[20],book_id[20],q;
    int sln;
    public:
    transaction(){
        sln=-1;
    }
    void issue(){
        cout<<"Enter member id: ";
        cin>>mem_id;
        cout<<"Enter book id: ";
        cin>>book_id;
        q='i';
    }
    void return_(){
        cout<<"Enter member id: ";
        cin>>mem_id;
        cout<<"Enter book id: ";
        cin>>book_id;
        cout<<"Enter sln: ";
        cin>>sln;
        q='r';
            }
    void put(){
        cout<<" |member_id: "<<mem_id<<" |book_id:"<<book_id<<" |sln: "<<sln<<endl;
    }
friend class transaction_list;
};

class transaction_list{
    string tran_file;
    public:
    transaction_list(){
        tran_file="";
    } 


    void make_transaction(){
        if(tran_file==""){
            cout<<"\nadd file first\n";
            tran_file=add_file(3);
        }
        fstream op;
        transaction t;
        cout<<"issue(i) or return(r) :";
        char choice;
        cin>>choice;
        if(choice=='i'||choice=='I'){
            t.issue();
            int c=book_list::get_sln(t.book_id);
            if(c==-2){
                cout<<"cant issue book: the book is not found"<<endl;
                return;
            }
            if(c==-1){
                cout<<"cant issue book : all book issued "<<endl;
                return;
            }
            int p=member_list::check_id(t.mem_id);
            if(p==-2){
                cout<<"member not found "<<endl;
            return;
            }
            if(p==-1){
                cout<<"all books quota exhausted : return books first "<<endl;
            return;
            }
            else t.sln=c;
            member_list::issue(t.mem_id,t.book_id,t.sln);
            cout<<"\nbook issued\n";

        }
        else if(choice=='r'||choice=='R'){
            t.return_();
            int p=member_list::check_id(t.mem_id);
            if(p==-2){
                cout<<"member not found how can you return??"<<endl;
            return;
            }

            int c1=member_list::return_(t.mem_id,t.book_id,t.sln);
            if(c1==-1){
                cout<<"You are trying to return others book\n";
                return;
            }
            book_list::book_ret(t.book_id,t.sln);

            cout<<"\nBOOK returned\n"<<endl;


        }
        else cout<<"Enter corrct choice"<<endl;

              op.open(tran_file,ios::in|ios::out|ios::ate|ios::binary);
              op.write((char*)&t,sizeof(t));
              op.close();
              return;
    }

    void show_transaction(){
       if(tran_file==""){
            cout<<"\nadd file first\n";
            tran_file=add_file(3);
        }
        ifstream op;
                if(op.fail()){
            cout<<"File openning error";
            exit(2);
        }
        op.open(tran_file,ios::in|ios::binary);
        transaction t;
        while(op.read((char* )&t,sizeof t))
        {
            if(t.q=='i'){
                cout<<"issued: ";
                t.put();
            }
            if(t.q=='r'){
                cout<<"returned: ";
                t.put();
            }

        }
    }
};

class library{
    book_list bl;
    member_list ml;
    transaction_list tl;
    public:
    void start(){

        int choice;
        do{
            cout<<"\n-1:load\n0:overwrite files(fac.DAT,stu.DAT,tran.DAT,books.DAT)\n1:Add books\n2:show books\n3:add_members\n4:show members\n5:make_transaction\n6:show_transactions\t9:EXIT\n\nenter your choice: ";
            cin>>choice;
            switch(choice){
                case -1:
                bl.load_map();
                ml.load_map();
                break;
                case 0:
                overwrite();
                break;
                case 1:bl.add_book();
                break;
                case 2:
                bl.show_books();
                break;
                case 3:
                ml.add_member();
                break;
                case 4:
                ml.show_member();
                break;
                case 5:
                tl.make_transaction();
                break;
                case 6:
                tl.show_transaction();
                break;
                case 9:return;
                default:cout<<"\nEnter correct response\n\n";
            }
        }while(true);
    }
};
int main(int argc, char const *argv[])
{
    library l;
    l.start();
return 0;
}