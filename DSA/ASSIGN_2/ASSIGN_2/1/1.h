#include<stdio.h>
#include<stdlib.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<=(b))?(a):(b)

typedef struct {
    int degree;
    float *coeff;
}poly;
poly ans;
void get_degree(poly *p){

printf("enter the degree of polynomial\n");
scanf("%d",&p->degree);
p->coeff=(float *)malloc((p->degree+1)*sizeof(float));
loop(i,0,p->degree+1){
    p->coeff[i]=0;
}
}

void getinput(poly *p){
int a;
float b;
printf("Enter the degree and coeff\n");
scanf("%d%f",&a,&b);
p->coeff[a]=b;
}
void print(poly p){
printf("polynomial is: ");
loop(i,0,p.degree+1){
    if(p.coeff[i]!=0 && i!=p.degree){
        printf("( %.1f )X^%d + ",p.coeff[i],i);
    }
    if( p.coeff[i]!=0 && i==p.degree){
        printf("( %.1f )X^%d ",p.coeff[i],i);
    }
}
printf("\n");
}

void add(){
printf("%d %d",p.degree,q.degree);
ans.degree=max(p.degree,q.degree);
if(p.degree<q.degree){
    loop(i,0,p.degree+1){
        ans.coeff[i]=p.coeff[i]+q.coeff[i];
    }
    loop(i,p.degree+1+1,q.degree+1){
        ans.coeff[i]=q.coeff[i];
    }
}
else if(p.degree==q.degree)
{
    loop(i,0,p.degree+1){
        ans.coeff[i]=p.coeff[i]+q.coeff[i];
    }
}
else{
    loop(i,0,q.degree+1){
        ans.coeff[i]=p.coeff[i]+q.coeff[i];
    }
    loop(i,q.degree+1+1,p.degree+1){
        ans.coeff[i]=q.coeff[i];
    }
}
}

void multiply(poly p,int q){
    ans.degree=p.degree;
    loop(i,0,p.degree+1){
        ans.coeff[i]=p.coeff[i]*q;
    }
    return;
}
void substract(poly p,poly q){
    
}



