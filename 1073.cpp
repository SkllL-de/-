#include<iostream>
#include<algorithm>
using namespace std;
int arr[100005],n,m;
bool check(int x){
    int k=1;int pre=arr[1];
    for(int i=2;i<=n;i++){
        if(arr[i]-pre>=x){
            k++;
            pre=arr[i];
        }
        if(k>=m)return true;
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+1+n);
    int l=1,r=arr[n]-arr[1],mid,ans;
    while(l<r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout<<ans;
    return 0;
}