#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)


using namespace std;
class node{
    public:
    int key;
    node* prev,*next;
};
node* newnode(int val){
    node* n=new node;
    n->key=val;
    n->prev=n->next=NULL;
    return n;
}
class lis{
    node* head;
    static int size;
    public:
    lis(){
        head=NULL;
    }
    void insert(){
        cout<<"enter value to add in node"<<endl;
        int val;
        size++;
        cin>>val;
                if(head==NULL){
            head=newnode(val);
           
        }
        else {
            node*n=newnode(val);
            head->next=n;
            n->prev=head;
            head=n;
            // top=head;

        }
    }
    static int get_size(){
        return size;
    }
    void pop(int val){
        node* temp=head;
        while(temp!=NULL){
            if(temp->key==val){
                size--;
                if(temp==head){
                    if(head->prev==NULL){
                        head=NULL;
                    }
                    else {head->prev->next=head->next;
                    head=head->prev;
                    }
                    delete temp;
                }
                else
                    {   if(temp->prev!=NULL){
                      temp->prev->next=temp->next;
                      temp->next->prev=temp->prev;}
                      else temp->next->prev=NULL;
                      delete temp;
                    }
                    
            }
            temp=temp->prev;
        }
    }
    void display(){
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->key<<" ";
                temp=temp->prev;
            }
        }
    };
    int lis::size=0;
int main(int argc, char const *argv[])
{
    lis l;
do{
    cout<<"Enter choice to\n1:add node\n2.delete ndoe\n3:number of node\n4.display whole list\n5. exit)\n";
    int choice;
    cin>>choice;
    if(choice==1){
        l.insert();
        cout<<"node inserted"<<endl;
    }
    if(choice==2){
        int key;
        cin>>key;
        l.pop(key);
    }
    if(choice==3)
    cout<<"total node : "<<lis::get_size()<<endl;
    if(choice==4)
    l.display();
    if(choice==5)
    break;
    cout<<"-----------------------------------"<<endl;

}while(1);



return 0;
}