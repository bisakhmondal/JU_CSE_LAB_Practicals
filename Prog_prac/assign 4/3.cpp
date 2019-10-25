#include<iostream>
#include<cstring>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define init ios_base::sync_with_stdio(false);cin.tie(NULL);
#define case int t; cin>>t; while(t--)
using namespace std;

class array{
    int size;
    int *a;
    public:
    array(int sie=0){
        size=sie;
        // cout<<"Enter size"
        if(size!=0)
        a=new int[size];
        if(size==0){
            a=NULL;
        }
        loop(i,0,size){
            a[i]=0;
        }
    }
    void get_info(){
        cout<<" Enter array details of size "<<size<<endl;
        loop(i,0,size){
            // cout<<"a[ "<<i<<" ] ";
            cin>>a[i];
        }
    }
    void print(){
        loop(i,0,size){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    array(const array &a1){
        size=a1.size;
        if(size!=0){
            a=new int[size];
        }
        loop(i,0,size){
            a[i]=a1.a[i];
        }
        if(size==0) a=NULL;
    
    }
   array(int *b){
       int s=0;
       while(b[s]!=INT32_MAX)
       s++;
       size=s;
       if(s==0)
       a=NULL;
       else a=new int[s];
       loop(i,0,s){
           a[i]=b[i];
       }

    }

    int operator[](int idx){
        if(idx>size){
            cout<<"array is out of Bound"<<endl;
            return INT32_MAX;
        }
        else
        return a[idx];

    }
    array& operator+(array p){
        if(size!=p.size)
        cout<<"cant be processed as array size is not same"<<endl;
        else{
            array *a3=new array(size);
            loop(i,0,size){
                a3->a[i]=a[i]+p.a[i];

            }
            return *a3;
        }
    }
    array & operator=(array &p){
            
            size=p.size;
            loop(i,0,size){
                a[i]=p.a[i];
            }
            return *this;
    }
    array& operator*(int c){
            array *a3=new array(size);
            loop(i,0,size){
                a3->a[i]=a[i]*c;

            }
            return *a3;
        
    }
    friend array operator*(int k,array a);

};
array operator*(int k,array c){
    array c3(c.size);
    loop(i,0,c.size){
        c3.a[i]=c.a[i]*k;
    }
    return c3;

}

int main(int argc, char const *argv[])
{
int siz;
cout<<"enter size"<<endl;
cin>>siz;
array a(siz);
a.get_info();
a.print();
cout<<"calling copy const."<<endl;
array b=a;
cout<<"b: ";b.print();
cout<<"Change b: ";
b.get_info();
cout<<"addition via a+b ";
array a1=a+b;
a1.print();
int p[]={1,7,8,9,6};
p[5]=INT32_MAX;
cout<<"assigning an int array {1 7 8 9 6}:  ";
array a5=p;
a5.print();
cout<<"accessing array index using [] a[1]: "<<a[1]<<endl;
array a3= a*5;
cout<<" a*5: ";
a3.print();
cout<<" 5*a: ";
array a4=5*a;
a4.print();

return 0;
}