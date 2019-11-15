#include<bits/stdc++.h>

using namespace std;

#define book_max 1000
#define member_max 1000
#define transaction_max 10000

class transaction_list;

class book{
    protected:
    string title;
    string author;
    string publisher;
    float price;
    int id;
    public:
    int sln;
    friend class bookList;

    public:
    void createbook(){
        cout<<"Enter title : ";
        cin>>title;
        cout<<"Enter author : ";
        cin>>author;
        cout<<"Enter publisher : ";
        cin>>publisher;
        cout<<"Enter id : ";
        cin>>id;
        cout<<"Enter Price: ";
        cin>>price;
    }

    void setSerial(int num)
    {
        sln = num;
    }

    bool comparebook(book b)
    {
        if(b.title == title && b.author == author && b.id == id && b.sln == sln && b.publisher == publisher)
        {
            return true;
        }
        return false;
    }

    void print()
    {

        cout<<"TITLE : "<<title<<"\n"<<"AUTHOR : "<<author;
    }
};

class bookList{

    static int curr_books;
    string _books[book_max][4];
    int b_id[book_max][3];

    public:void addNewbook(book& b)
    {
        bool found = false;
        for(int i = 0 ; i < curr_books ; i++ )
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher )
            {
                _books[i][3] = _books[i][3] + '1';
                b_id[i][1]++;
                b_id[i][2]++;
                found = true;
                break;
            }

        }
        if(found == false)
        {
            curr_books++;
            if(curr_books <= book_max)
            {
                _books[curr_books - 1][0] = b.title;
                _books[curr_books - 1][1] = b.author;
                _books[curr_books - 1][2] = b.publisher;
                _books[curr_books - 1][3] = "1";
                b_id[curr_books - 1][0] = b.id;
                b_id[curr_books - 1][1] = 1;
                b_id[curr_books - 1][2] = 1;

            }
        }
    }

    int getbooksln(book& b)
    {
        for(int i = 0 ; i < curr_books ; i++)
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher && b_id[i][2] != 0)
            {

                for(int j = 0 ; j < _books[i][3].length() ; j++)
                {
                    if(_books[i][3][j] == '1')
                    {
                        return j;
                    }
                }
            }

        }
        return -1;

    }

    bool bookExists(book& b)
    {
            for(int i = 0 ; i < curr_books ; i++)
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher && b_id[i][2] != 0)
            {
                    return true;

            }
        }
    return false;
    }

   void removebook(book& b)
   {
       int j = returnbookID(b);
       int k = getbooksln(b);
       _books[j][3][k] = '0';
       b_id[j][2]--;
       b.setSerial(k);
   }

    void returnbook(book b)
    {
        int j = returnbookID(b);
        int k = b.sln;
        _books[j][3][k] = '1';
        b_id[j][2]++;
    }

    int returnbookID(book b)
    {
            for(int i = 0 ; i < curr_books ; i++)
        {
            if(_books[i][0] == b.title && _books[i][1] == b.author && _books[i][2] == b.publisher)
            {
                    return i;

            }
        }
        return -1;

    }

   void printbookList()
   {
       for(int i = 0 ; i < curr_books ; i++)
       {
          cout<<"TITLE : "<<_books[i][0]<<"\n"<<"AUTHOR : "<<_books[i][1]<<"\n"<<"PUBLISHER : "<<_books[i][2]<<"\n"<<"book_ID : "<<b_id[i][0]<<"\n";
       }
   }



};

 int bookList::curr_books = 0;

class Member{
    protected:
    string name;
    string id;
    int issued_books;
    int total_books;
    friend class member_list;

    public:
    bool compareMembers(Member m)
    {
        if(m.id == id && m.name == name)
            return true;
        return false;
    }

    void createMember()
    {
    cout<<"Enter Name : ";
    cin>>name;
    cout<<"Enter member id : ";
    cin>>id;
    issued_books = 0;
    }

    void print()
    {
        cout<<"NAME : "<<"\n"<<"ID : "<<"\n";
    }

    bool eligiblility()
    {
        if(issued_books < total_books)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

    void update(int num)
    {
        issued_books-=num;
    }

};

class Student: public Member{
public:
    Student(){
        issued_books = 0;
        total_books = 2;
    }
};

class Faculty: public Member{
public:
    Faculty(){
        issued_books = 0;
        total_books = 10;
    }
};

class member_list{
    static int curr_member_size;
    Member _members[member_max];

    public:
    bool validateMember(Member m)
    {
        for(int i = 0 ; i < curr_member_size ; i++)
        {
            if(m.name == _members[i].name && m.id == _members[i].id)
            {
                return true;
            }
        }
        return false;
    }

    int findID(Member m)
    {
        for(int i = 0 ; i < curr_member_size ; i++)
        {
            if(m.name == _members[i].name && m.id == _members[i].id)
            {
                return i;
            }
        }
        return -1;

    }

    Member& returnMember(member_list& m1, int i)
    {
        return m1._members[i];
    }


    int addNewMember(Member m)
    {
        if(curr_member_size <= member_max && validateMember(m) == false )
        {
            _members[curr_member_size] = m;
            curr_member_size++;
            return 0;
        }
        else
        {
            return -1;
        }
    }

    void printMembers()
    {
        for(int i = 0 ; i < curr_member_size ; i++)
        {
            _members[i].print();
        }
    }

};
class Date{
    int month;
    int day;
    int year;

    public:
    void getDate()
    {
        cout<<"Enter date in dd/mm/yyyy format ";
        cin>>day>>month>>year;
    }

    void printDate()
    {
        cout<<day<<" "<<month<<" "<<year<<"\n";
    }


};

class Transaction{

    Date d;
    protected:
    Member m;
    book b;

    public:
    void initiate_tr(member_list m1, bookList b1){
        d.getDate();
        m.createMember();
        if(m1.validateMember(m))
        {
            b.createbook();
            if(b1.bookExists(b))
            {
                printf("transaction in progress\n");
            }
            else
            {
                printf("book not available.\nTry again Later\n");
            }


        }
        else
        {
            printf("Member does not exist.\nPlease register\n");
        }
    }

    void initializeDate()
    {
        d.getDate();
    }

    void printTransaction() {
            m.print();
            cout << " ";
            b.print();


    }

    friend class transaction_list;
};

class Issue:public Transaction{
    public:
    void issuebook(member_list& m1, bookList& b1, transaction_list& t1);
    void initiate_tr(member_list m1, bookList b1){
        initializeDate();
        m.createMember();
        if(m1.validateMember(m))
        {
            b.createbook();
            if(b1.bookExists(b))
            {
                printf("transaction in progress\n");
            }
            else
            {
                printf("book not available.\nTry again Later\n");
            }


        }
        else
        {
            printf("Member does not exist.\nPlease register\n");
        }
    }

};

class Return:public Transaction{
    public:
    void returnbook(member_list& m1, bookList& b1, transaction_list& t1);

    int  initiate_tr(member_list m1, bookList b1){
        initializeDate();
        m.createMember();
        if(m1.validateMember(m))
        {
            b.createbook();
            int i = b1.returnbookID(b);
            if(i == -1)
            {
                printf("Sorry no Book on this name. \n");
                return -1;
            }
            else
            {
                printf("transaction in progress.\n");
                return 0;
            }
        }
        else
        {
            printf("Member does not exist.\nPlease register\n");
            return -1;
        }
    }

};

int member_list::curr_member_size = 0;



class transaction_list{
    Transaction _transactions[transaction_max];
    string status[transaction_max];
    static int curr_transaction_size;

    public:
    void addTransaction(Issue i)
    {
        _transactions[curr_transaction_size] = i;
        status[curr_transaction_size] = "Issued";
        curr_transaction_size++;
    }

    void addTransaction( Return r)
    {
        if(existsTransaction( r) != -1)
        {
            int i = existsTransaction( r);
            if(status[i] == "Issued")
            {
                status[i] = "Returned";
                printf("List Updated\n");
            }

        }
        else{
            printf("Wrong book returned. Try again\n");
        }
    }

    void printAllTransactions()
    {
        for(int i = 0 ; i < curr_transaction_size ; i++)
        {
            _transactions[i].printTransaction();
            cout << " " << status[i] << '\n';
        }
    }

    int existsTransaction( Return r)
    {
        for(int i = 0 ; i < curr_transaction_size ; i++)
        {
            if(_transactions[i].m.compareMembers(r.m) && _transactions[i].b.comparebook(r.b) && status[i] == "Issued")
            {
               return i;

            }
        }
        return -1;
    }

};

int transaction_list::curr_transaction_size = 0;

void Issue::issuebook(member_list& m1, bookList& b1, transaction_list& t1)
{
        initiate_tr(m1, b1);
        int i = m1.findID(m);
        if(m1.returnMember(m1, i).eligiblility())
        {
            if(b1.bookExists(b))
            {
            b1.removebook(b);
            printf("Your book has been issued\n");
            m1.returnMember(m1, i).update(-1);
            cout << "Serial Number : " << b.sln << "\n";
            t1.addTransaction(*this);
            }
        }
        else
        {
            printf("You have already borrowed maximum number of books\n");
        }

}

void Return::returnbook(member_list& m1, bookList& b1, transaction_list& t1)
{
        if(initiate_tr(m1, b1) != -1)
        {
            int i;
            cin >> i;
            b.setSerial(i);
            b1.returnbook(b);
            int j = m1.findID(m);
            Member& final_m = m1.returnMember(m1, j);
            final_m.update(1);
            t1.addTransaction(*this);
        }

}


class Library{
    public:
    void start(){
        bookList bl1;
        member_list ml1;
        transaction_list tl1;

            int choice;
        do{
            cout << "1. Add a new book\n2. Add a new member\n3. Issue a book\n4. Return a book\n5. Show all transactions till now\n6. Exit Library\n";
            cout << "Choice : ";
            cin>>choice;
            if(choice == 1)
            {
                book b;
                b.createbook();
                bl1.addNewbook(b);
            }
            else if(choice == 2)
            {
                cout << "Enter member type : ";
                string s;
                cin >> s;
                if(s == "student")
                {
                    Student s1;
                    s1.createMember();
                    ml1.addNewMember(s1);
                }
                else if(s == "faculty")
                {
                    Faculty f;
                    f.createMember();
                    ml1.addNewMember(f);
                }

            }
            else if(choice == 3)
            {
                Issue i;
                i.issuebook(ml1, bl1, tl1);
            }

            else if(choice == 4)
            {
                Return r;
                r.returnbook(ml1, bl1, tl1);

            }
            else if(choice == 5)
            {
                tl1.printAllTransactions();
            }
        }while(choice != 6);
    }
};

int main()
{

    Library l;
    l.start();
}
