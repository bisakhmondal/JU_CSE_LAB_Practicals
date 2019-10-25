#include<stdio.h>
#include<stdlib.h>
typedef struct {
  int coeff;
  int expo;
}poly;
//DECLARING POLYNOMIALS
poly p1[50],p2[50],p3[50];
void take_input(poly p1[50],int degree){
  for(int i=0;i<=degree;i++){
    printf("Enter coefficient of x^(%d): ",i);
    scanf("%d",&p1[i].coeff);
   }
   printf("\nThe Polynomial is:\n");
   for(int i=0;i<=degree-1;i++){
     printf("%dx^(%d)+",p1[i].coeff,i);
   }
   printf("%dx^(%d)",p1[degree].coeff,degree);
}
void add_poly(poly p1[50], poly p2[50], int deg1, int deg2, poly p3[50]){
  int k=0;
  if(deg1 > deg2){
    for(int i=0;i<=deg2;i++){
      p3[k].coeff = p1[i].coeff + p2[i].coeff;
      //p3[k].expo = p2[i].expo;
      k++;
    }
    for(int i=deg2+1;i<=deg1;i++){
      p3[k].coeff = p1[i].coeff;
      //p3[k].expo = p1[i].expo;
      k++;
    }
  }
  else if(deg1 < deg2){
    k = 0;
    for(int i=0;i<=deg1;i++){
      p3[k].coeff = p1[i].coeff + p2[i].coeff;
      //p3[k].expo = p1[i].expo;
      k++;
    }
    for(int i=deg1+1;i<=deg2;i++){
      p3[k].coeff = p2[i].coeff;
      //p3[k].expo = p3[k].coeff;
      k++;
    }
  }
  else{
    for(int i=0;i<=deg1;i++){
      p3[k].coeff = p1[i].coeff + p2[i].coeff;
      k++;
    }
  }
  printf("\nThe Resulting polynomial after addition is :\n");
  for(int i=0;i<k-1;i++){
    printf("%dx^(%d)+",p3[i].coeff,i);
  }
   printf("%dx^(%d)",p3[k-1].coeff,k-1);
}
void subtract_poly(poly p1[50], poly p2[50], int deg1, int deg2, poly p3[50]){
  int k=0;
  if(deg1 > deg2){
    for(int i=0;i<=deg2;i++){
      p3[k].coeff = p1[i].coeff - p2[i].coeff;
      k++;
    }
    for(int i=deg2+1;i<=deg1;i++){
      p3[k].coeff = p1[i].coeff - p2[i].coeff;
      k++;
    }
  }
  else if(deg1 < deg2){
    k = deg2;
    for(int i=0;i<=deg1;i++){
      p3[k].coeff = p1[i].coeff - p2[i].coeff;
      k++;
    }
    for(int i=deg1+1;i<=deg2;i++){
      p3[k].coeff = p2[i].coeff;
      k++;
    }
  }
  else{
    for(int i=0;i<=deg1;i++){
      p3[k].coeff = p1[i].coeff - p2[i].coeff;
      k++;
    }
  }
  printf("\n\nThe Resulting polynomial after subtraction is :\n");
  for(int i=0;i<k-1;i++){
    printf("%dx^(%d)+",p3[i].coeff,i);
  }
   printf("%dx^(%d)",p3[k-1].coeff,k-1);
}
void multiply_pol(poly p1[50], poly p2[50], int deg1, int deg2, poly p3[100]){
  poly k[deg1+deg2-1];
  for(int i=0;i<=deg1+deg2;i++){
    k[i].coeff = 0;
  }
  for(int i=0;i<=deg1;i++){
    for(int j=0;j<=deg2;j++){
      k[i+j].coeff += p1[i].coeff * p2[i].coeff;
    }
  }
  printf("The Result after Multiplication is :\n");
  for(int i=0;i<deg1+deg2;i++){
    printf("%dx^(%d)+",k[i].coeff,i);
  }
  printf("%dx^(%d)",k[deg1+deg2].coeff,deg1+deg2);
}
int main(){
  printf("\nAddition of 2 polynomials\n");
  int deg1,deg2;
  printf("Enter highest degree of polynomial 1 : ");
  scanf("%d",&deg1);
  take_input(p1,deg1);
  printf("\n\n");
  printf("Enter highest degree of polynomial 2 : ");
  scanf("%d",&deg2);
  take_input(p2,deg2);
  printf("\n\n");
  add_poly(p1,p2,deg1,deg2,p3);
  printf("\n\n");
  subtract_poly(p1,p2,deg1,deg2,p3);
  printf("\n\n");
  multiply_pol(p1,p2,deg1,deg2,p3);
  printf("\n");
}
