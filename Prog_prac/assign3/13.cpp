#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;


vector<string> cache;
class item{
    string item_code,name;
    float rate;
    int qty;
    public:
    bool get_input(){
        cout<<"Enter item_code: ";
        cin>>item_code;
        loop(i,0,cache.size()){
            if(cache[i]==item_code){
                cout<<"item code already exists"<<endl;
                return false;
            }
        }
        cache.push_back(item_code);
        cout<<"Enter product name: ";
        cin>>name;
        cout<<"Enter rate: ";
        cin>>rate;
        cout<<"Enter qunatity: ";
        cin>>qty;
        return true;

    } 
    string get_code(){
        return item_code;
    }
    void rate_change(){
        cout<<"enter the new rate: ";
        float r;
        cin>>r;
        rate=r;
        cout<<"rate updated\n"<<endl;
    }
    void reissue(){
        cout<<"1:withdraw or 2:deposit ";
        int choice;
        cin>>choice;
        cout<<"enter amount : ";
        int q;
        cin>>q;
        if(choice==1){
            if(q<=qty){
                qty-=q;
                cout<<"Stock updated"<<endl;
            }
            else
            {
                cout<<"stock is in underflow"<<endl;
            }
            
        }
        if(choice==2){
            qty+=q;
            cout<<"stock updated"<<endl;
        }
    }
    void available(){
        if(qty>0){
            cout<<"available"<<endl;
        }
        else cout<<"oops! not available"<<endl;
    }

    void know(){
        cout<<"price :"<<rate<<" quantity: "<<qty<<endl;
    }


};

int main(int argc, char const *argv[])
{
vector<item> v;
item i;
do {
    cout<<"Enter choice to\n1:add input\n2.change rate\n3:update quantity\n4.check availability\n5. display rate and quantity\n6.exit\n";
    int choice;
    cin>>choice;
    if(choice==1){
        bool flag=i.get_input();
        if(flag){
            v.push_back(i);
        }
    }
    if(choice==2){
        string c;
        cout<<"Enter item code : ";
        cin>>c;
        loop(i,0,v.size()){
            if(v[i].get_code()==c){
                v[i].rate_change();
                break;
            }
        }
    }
    if(choice==3){
        string c;
        cout<<"Enter item code : ";
        cin>>c;
        loop(i,0,v.size()){
            if(v[i].get_code()==c){
                v[i].reissue();
            }
        }

    }
    if(choice==4){
                string c;
        cout<<"Enter item code : ";
        cin>>c;
        loop(i,0,v.size()){
            if(v[i].get_code()==c)
                {
                    v[i].available();
                }
        }
    }
    if(choice==5){
                string c;
        cout<<"Enter item code : ";
        cin>>c;
        loop(i,0,v.size()){
            if(v[i].get_code()==c){
                v[i].know();
            }
        }
    }
    if(choice==6){
        break;
    }
    cout<<"----------------------------------"<<endl;

    }while(1);



return 0;
}