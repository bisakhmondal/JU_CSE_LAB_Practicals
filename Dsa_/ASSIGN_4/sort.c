#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#define num 10000
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int *a,int nu){
    for(int i=0;i<nu;i++){
        for(int j=0;j<nu-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}
void selection_sort(int*a,int nu){
    for(int i=0;i<nu;i++){
        for(int j=i+i;j<nu;j++){
            if(a[i]>a[j]){
                swap(&a[i],&a[j]);
            }
        }
    }
}
void insertion_sort(int *a,int nu){
    for(int i=1;i<nu;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void merge(int *a,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int i=0, j=0, k=0; 
      int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[mid + 1+ j]; 

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) { 
        a[k++] = L[i++];
    } 
    while (j < n2) { 
        a[k++] = R[j++]; 
    } 

}

void mergesort(int *a,int l,int r){
if(l<r){
    int mid=(l+r)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,r);
    merge(a,l,mid,r);
}
}

void heapify(int *a,int nu,int i){
int large=i;
int l=2*i+1;
int r=2*i+2;
if(l<nu && a[l]>a[large]){
    large=l;
}
if(r<nu && a[r]>a[large]){
    large=r;
}
if(large!=i){
    swap(&a[i],&a[large]);
    heapify(a,nu,large);
}
}
void heap_sort(int *a,int nu){
    for(int i=nu/2-1;i>=0;i--){
        heapify(a,nu,i);
    }
    for(int i=nu-1;i>=0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}
int partition(int *a,int l,int r){
    int pivot=a[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}
void quick_sort(int *a,int l,int r){
    if(l<r){
        int p=partition(a,l,r);
        quick_sort(a,l,p-1);
        quick_sort(a,p+1,r);
    }
}

int main(){
    int a[num];
    FILE*fp=fopen("1.txt","r");
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&a[i]);
    }
    clock_t start ,end;
    start=clock();
    bubble_sort(a,num);
    end=clock();
    double time_taken=((double)(end-start)/CLOCKS_PER_SEC);
    printf("bubble_sort : %lf\n",time_taken);


    fp=fopen("1.txt","r");
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&a[i]);
    }
    start=clock();
    selection_sort(a,num);
    end=clock();
    time_taken=((double)(end-start)/CLOCKS_PER_SEC);
    printf("selection_sort : %lf\n",time_taken);
    
    
    fp=fopen("1.txt","r");
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&a[i]);
    }
    start=clock();
    insertion_sort(a,num);
    end=clock();
   time_taken=((double)(end-start)/CLOCKS_PER_SEC);
   printf("insertion_sort : %lf\n",time_taken);

   fp=fopen("1.txt","r");
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&a[i]);
    }
    start=clock();
    mergesort(a,0,num-1);
    end=clock();
    time_taken=((double)(end-start)/CLOCKS_PER_SEC);
   printf("merge_sort : %lf\n",time_taken);

   fp=fopen("1.txt","r");
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&a[i]);
    }
    start=clock();
    heap_sort(a,num);
    end=clock();
    time_taken=((double)(end-start)/CLOCKS_PER_SEC);
   printf("heap_sort : %lf\n",time_taken);
   
   fp=fopen("1.txt","r");
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&a[i]);
    }
    start=clock();
    quick_sort(a,0,num-1);
    end=clock();
    time_taken=((double)(end-start)/CLOCKS_PER_SEC);
   printf("quick_sort : %lf\n",time_taken);
}