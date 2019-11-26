#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define N 5

int sol[5][5];


bool issafe(int x,int y,int maze[5][5]){
return x>=0 &&x<5&& y>=0 && y<5 && maze[x][y]==1;
}
void print(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
             printf("%d ",sol[i][j]);
        }
         printf("\n");
    }
}

bool utility(int x,int y,int maze[5][5]){
    //cout<<x<<" "<<y<<" \n";
    if(x==4 && y==4)
    {sol[x][y]=1;
        return true;}
    if(issafe(x,y,maze)){
        sol[x][y]=1;
        if(utility(x+1,y,maze)){
            return true;
        }
        if(utility(x,y+1,maze))
        {
            return true;
        }
        sol[x][y]=0;

    }
    return false;
}


void solve(int maze[5][5])
{
    if(utility(0,0,maze)){
    print();
    return ;
    }
    else
    {
        printf("cant print\n");

    }
    return;
    
}


int main(int argc, char const *argv[])
{

int maze[][5]={   {1, 0, 0, 0, 0},
   {1, 1, 0, 1, 0},
   {0, 1, 1, 1, 0},
   {0, 0, 0, 1, 0},
   {1, 1, 1, 1, 1}};
   solve(maze);

   //print();
    return 0;
}
