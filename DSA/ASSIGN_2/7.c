  #include<stdio.h>
  #include<stdlib.h>
  #define loop(i,a,b) for(int i=a;i<b;i++)
  int oo(int **a,int **f,int n,int ix,int jx){
      int x=ix-n/2,y=jx-n/2;
    //   printf("%d %d",a[0][0],f[1][1]);                          
      int sum=0;
      loop(i,0,n){
          loop(j,0,n){
              int p=x+i,q=y+j;
            //   printf("here %d %d %d %d %d \n",i,j,sum,p,q);
              if(p>=0 &&q>=0 &&q<128 &&p<128){
                //   printf("%d %d %d %d\n",p,q,i,j);
                  sum+=(f[i][j]*a[p][q]);
              }
            //   printf("here\n");
          }
      }
    //   printf("%d ",sum);
      return sum;
  }
  void matrix_mul(int **a,int **op,int **f,int n){
     
      loop(i,0,128){
          loop(j,0,128){
              op[i][j]=oo(a,f,n,i,j);

          }
      }
  }
  int main(){
      srand(time(NULL));
      int **a=(int**)malloc(128*sizeof(int*));
      loop(i,0,128){
          a[i]=(int *)malloc(128*sizeof(int));
          loop(j,0,128)
          a[i][j]=rand()%10;
      }
      int n;
      printf("Enter the sizeof filter: ");
      scanf("%d",&n);
      int **f=(int**)malloc(n*sizeof(int*));
      loop(i,0,n){
          f[i]=(int *)malloc(n*sizeof(int));
          loop(j,0,n)
          f[i][j]=rand()%5;
      }
      int **p=(int**)malloc(128*sizeof(int*));
      loop(i,0,128)p[i]=(int*)malloc(128*sizeof(int));
      printf("here\n");
      matrix_mul(a,p,f,n);
      loop(i,0,128){
      loop(j,0,128)
      printf("%d ",p[i][j]);
      printf("\n");
      }
      return 0;
  }