#include "1.h"

poly input(poly* p){
 get_degree(p);
printf("Enter number of terms in the polynomial\n");
int a;
scanf("%d",&a);
loop(i,0,a){
    getinput(p);
}
return *p;
}

int main()
{
poly p,q;
p=input(&p);
print(p);

// printf("Enter the second polynomial similarly\n");
// get_degree(&q);

// printf("Enter number of terms in the polynomial\n");
// scanf("%d",&a);
// loop(i,0,a)
//     getinput(&q);

// print(q);

// poly ans;
// add(p,q,&ans);
// printf("%d  %f\n",ans.degree,ans.coeff[0]);
// print(ans);
// return 0;
// }
printf("Enter choice you want\n"-----------------------------------------"\n1.add 2 poly\n2.substract 2 poly\n3.multiply 2 poly\n4.exit\n\n");
int choice;
scanf("%d",&choice);
switch(choice){
    case 1:add(p,q);
            print(ans);
            break;
    case 2: sub(p,p);
            print(ans);
            break;
    case 3:int k;
            printf("Enter the constant term to multiply\n");
            multiply(p,k);
            print(ans);
            break;
    case 4:
        return 0;
        break;
}

}
