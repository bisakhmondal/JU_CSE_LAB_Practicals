#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define init ios_base::sync_with_stdio(false);cin.tie(NULL);
#define case int t; cin>>t; while(t--)
using namespace std;
class node{
    public:
    int key;
    node*prev,*next;
};
node* newnode(int key){
node* n=new node;
n->key=key;
n->prev=n->next=NULL;
return n;
}
// node* insert(node* root,int val){
// if(root==NULL){
//     return newnode(val);
//     else
// }
// }
class st{
    node*head;
    int size;
    public:
    st(){
        size=0;
        head=NULL;
        cout<<"stack initiated"<<endl;
    }
    void push(int val){
        size++;
        if(head==NULL){
            head=newnode(val);
            // top=head;
           
        }
        else {
            head->next=newnode(val);
            head->next->prev=head;
            head=head->next;
            // top=head;

        }
        cout<<head->key<<" head->key"<<endl;
    }
    int top(){
        return head->key;
    }
    int getsize(){
        return size>0?size:0;
    }
    void pop(int val){
        size--;
        node* temp=head;
        if(head==NULL){
            cout<<"stack is in Underflow"<<endl; 
            return;
          }
        while(temp!=NULL){
            if(temp->key==val){
                if(temp==head){
                    temp->prev!=NULL?temp->prev->next=NULL:temp->prev=NULL;
                    head=head->prev;
                }
                else{
                temp->next->prev=temp->prev;
                temp->prev!=NULL?(temp->prev->next=temp->next):temp->prev=NULL;
                }
                delete temp;
                cout<<"popped successfully "<<val<<endl;  
                return;
            }
            temp=temp->prev;
        }
        if(temp==NULL){
            cout<<"key is not present\n";
        }

    }

};

int main(int argc, char const *argv[])
{
st s;

loop(i,0,5){
    s.push(5+i);
}
cout<<s.getsize()<<endl;
cout<<"top element of stack "<< s.top()<<endl;
loop(i,0,9)
s.pop(5+i);
s.pop(8);
s.pop(9);
cout<<"size of stack "<<s.getsize()<<endl;

return 0;
}