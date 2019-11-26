  #include<stdio.h>
  #include<stdlib.h>
  #define max(a,b) (a>b)?a:b
  #define min(a,b) (a<b)?a:b
  #define loop(i,a,b) for(int i=a;i<b;i++)
  int* maxi(int *a,int n,int k){
    int *m=(int *)malloc((n-k+1)*sizeof(int));
    loop(i,0,n-k+1){
      int maxi=a[i];
      loop(j,1,k){
        maxi=max(maxi,a[i+j]);
      }
      m[i]=maxi;
    }
    return m;
  } 
    int* mini(int *a,int n,int k){
    int *m=(int *)malloc((n-k+1)*sizeof(int));
    loop(i,0,n-k+1){
      int mini=a[i];
      loop(j,1,k){
        mini=min(mini,a[i+j]);
      }
      m[i]=mini;
    }
    return m;
  } 
  int* mid(int *a,int n,int k){
    int *m=(int *)malloc((n-k+1)*sizeof(int));
    loop(i,0,n-k+1){
      m[i]=a[i+k/2];
    }
    return m;
  } 
    float* avg(int *a,int n,int k){
    float *m=(float *)malloc((n-k+1)*sizeof(float));
    int sum=0;
    loop(i,0,k){
      sum+=a[k];
    }
    m[0]=sum/k;
    loop(i,k,n){
      sum+=a[i]-a[i-k];
      m[i-k+1]=sum/k;
    }
    return m;
  } 

  int main()
  {
  int n;
  printf("Enter The size of the Array\n");
  scanf("%d",&n);
  int *a=(int *)malloc(n*sizeof(int));
  loop(i,0,n){
  scanf("%d",(a+i));}
  int k;
  printf("Enter sliding window size\n");
  scanf("%d",&k);
  if(k>n)exit(2);
  int *ma=maxi(a,n,k);
  int *mi=mini(a,n,k);
  int *midd=mid(a,n,k);
  float *avgg=avg(a,n,k);
  printf("MAX: ");
  loop(i,0,n-k+1) printf("%d ",ma[i]);
  printf("\nMIN: ");
  loop(i,0,n-k+1) printf("%d ",mi[i]);
  printf("\nMEDIAN: ");
  loop(i,0,n-k+1) printf("%d ",midd[i]);
  printf("\nAVERAGE: ");
  loop(i,0,n-k+1) printf("%0.2f ",avgg[i]);


  
  return 0;
}
