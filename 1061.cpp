#include<iostream>
#include<algorithm>
using namespace std;
long arr[25];
int res[25],n,m,Rank=0;
//bool used[25];
bool found=0;
void dfs(int left, int i){
    if(left==0){
        for(int j = 1; j <= Rank; j++)cout<<res[j];
        cout<<res[Rank];
        exit(0);
    }
    for(int j = i; j <= n; j++){
        //if(!used[j]){
            if(left-arr[j]>=0){
                //used[j]=1;
                res[++Rank]=arr[j];
                dfs(left-arr[j], j+1);
                //used[j]=0;
                res[Rank--]=0;
            }else{
                return;
            }
        //}
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    dfs(m, 1);
    return 0;
}