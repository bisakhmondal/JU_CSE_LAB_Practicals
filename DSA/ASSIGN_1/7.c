#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdint.h>
#define ll long long

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

int main(){
    srand(time(0));
    int x;
    printf("Enter number sets of long integers required\n");
    scanf("%d",&x);
    while(x--){
        uint64_t l=rand();
       
        l=(l<<32)|rand();
       // l=(l%(5000-2000))+2000;
        printf("%lld\n",l);
        for(int i=0;i<7;i++){
        int p=prime_gen();
        printf("%lld | %d | %d\n",l,p,l%p);
        
    }
}
return 0;
}