#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define n 8
int q=0;
bool issafe(int x, int y,int sol[n][n]){
   for(int i=0;i<x;i++){
       if(sol[i][y])
       return false;
   for (int i=x, j=y; i>=0 && j>=0; i--, j--)
   if(sol[i][j])
   return false;
    for (int i=x, j=y; i>=0 && j<n; i--, j++)
    if(sol[i][j])
       return false;
   }
   
   return true;

}

void print(int sol[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",sol[i][j]);
        }
        printf("\n");
    }
}
bool utility(int x,int sol[n][n])
{
    if(x>=n){
        for (int i = q; i < n; i++)
        {
            if(sol[0][i]==1){
                q=++i;
                break;

            }
            /* code */
        }
    return true;
    }
    for(int i=0;i<n;i++){
        //xnext=x+i;
        if(issafe(x,i,sol))
        {
            int c=(x==0)?i+q:i;
            sol[x][c]=1;
            if(utility(x+1,sol))
            return true;
            else sol[x][i]=0;
        }

    }
    return false;
}


bool solve()
{
    int sol[n][n];
    for(int i=0;i<n;i++)
    for (int j= 0; j < n; j++)
    {
        sol[i][j]=0;
    }
    if(utility(0,sol)){
        print(sol);
        return true;    
        }
    return false;
}

int main(int argc, char const *argv[])
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    

    solve();
    return 0;
} 
