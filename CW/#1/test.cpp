#include <iostream>
#include <cstring>

using namespace std;

const int maxN=1000;
int memo[maxN];
int pi[maxN];

int main(){
    int a[]={7,8,5,1,4};
    memset(memo,-1,sizeof memo);
    memset(pi,-1,sizeof pi);
    int n;
    cin>>n;
    memo[0]=0;
    pi[0]=0;
    for(int i=0;i<(int)sizeof(a)/4;i++){
        for(int num=n;num>=0;num--){
            if(num-a[i]>=0 and memo[num-a[i]]!=-1 and (memo[num]==-1 or memo[num]>1+memo[num-a[i]])){
                memo[num]=1+memo[num-a[i]]; 
                pi[num]=num-a[i];           
            }
        }
    }   
    int N=n;
    while(N!=0){
        cout<<N-pi[N]<<" ";
        N=pi[N];
    }
    cout<<endl;
    cout<<memo[n]<<endl;
    cin.get();
    return 0;
}