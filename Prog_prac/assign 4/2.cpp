#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

class complex{
    float r,i;
    public:
    void get_data(){
        cout<<"Enter The real and imaginary values of complex number"<<endl;
        cout<<"Real: ";
        cin>>r;
        cout<<"Imaginary: ";
        cin>>i;
    }
    void print(){
        cout<<"complex Number is: "<<r<<" + i*"<<i<<endl;
    }
    complex operator +(complex c1){
        complex c2;
        c2.i=i+c1.i;
        c2.r=r+c1.r;
        return c2;
    }
    complex operator -(complex c1){
        complex c2;
        c2.i=i-c1.i;
        c2.r=r-c1.r;
        return c2; 
    }
};
int main(int argc, char const *argv[])
{
complex s1,s2;
 do{
printf("1.Enter Complex 1\t 2.enter Complex 2\t3.Add 2 Complex\t4.Substract 2 complex\t5.exit\n");
int choice;
scanf("%d",&choice);
if (choice==1){
    s1.get_data();
    s1.print();
}
if(choice==2){
    s2.get_data();
    s2.print();
}
if(choice==3)
{
    complex op=s1+s2;
    op.print();
}
if(choice==4){
complex op;
op=s1-s2;
op.print();
}

if(choice==5)
break;
printf("---------------------------------------------\n");
}while(1);

   
    



return 0;
}
