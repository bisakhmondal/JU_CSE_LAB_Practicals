#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
bool check_prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int prime_gen(){
while(true){
int pr=(rand()%(100-10))+10;
for(int i=pr*100;i<(pr+1)*100;i++){
    if(check_prime(i)){
        return i;
    }
}
}
}

long int operate(int a){
    int num_d=0;
    int temp=a;
    while(temp>0){
        temp/=10;
        num_d++;
    }
    int mid=num_d/2;
    long int r=pow(10,mid);
    r=a%r;
    long int l=a/pow(10,mid);
    return l+r;
}

int main(){
    char s[20];
    long long unsigned int a=0;
    printf("Enter The text\n");
    scanf("%s",s);
    // printf("%ld",atoi(a));
    for(int i=0;s[i]!='\0';i++){
        int p=(s[i]-'\0');
        a=p>=100?a*1000+p:a*100+p;
        //printf("%ld\n",a);
        

    }
    printf("Juxtaposed ASCII value :%lu\n",a);

    long int t=operate(a);

    int x=7;
    while(x--){
        int p=prime_gen();

        printf("%d | %d\n",p,t%p);

    }



}