#include<iostream>
#include<cmath>
using namespace std;
const int N=100005;
int w[N],v[N],dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,c;
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=1;j--){
            if(j>=w[i])dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[c];
    return 0;
}