#include<iostream>
using namespace std;
int arr[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,k,t;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t;
        arr[t]++;
    }
    int cnt=0;
    for(int i=0;i<=1000000;i++){
        cnt+=arr[i];
        if(cnt>=k){
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}