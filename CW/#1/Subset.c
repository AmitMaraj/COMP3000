#include<stdio.h>
int main()
{   
    FILE*in = fopen("subset.txt","r");
    int N,M;
    fscanf(in," %d %d",&N,&M);
    int nums[N+1],i,j,ispossible[N+1][M+1];
    for(i=1;i<=N;i++)
        fscanf(in," %d",&nums[i]);
    
    for(i=0;i<=N;i++)
        for(j=0;j<=M;j++)
            ispossible[i][j]=0;//initialising to 0
    for(i=0;i<=N;i++)
        ispossible[i][0]=1;
    for(i=1;i<=N;i++)
    {
        for(j=0;j<=M;j++)
        {
            if(ispossible[i-1][j]==1)
                ispossible[i][j]=1;
            if(j-nums[i]>=0 && ispossible[i-1][j-nums[i]]==1)
                ispossible[i][j]=1;
        }
    }
    if(ispossible[N][M]==1)
        printf("Yes");
    else
        printf("No");
    return 0;
}