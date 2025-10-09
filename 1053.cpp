#include <iostream>
#include <algorithm>
using namespace std;
int n,k,t;
void solve(int x, int arr[]){
    int best_a=0;
    int best_b=0;
    int l=0,r=n-1;
    bool found = false;
    //if(x<arr[0]+arr[1]||x>arr[n-2]+arr[n-1])goto end;
    while(l<r){
        long sum=arr[l]+arr[r];
        if(sum==x){
            best_a=arr[l],best_b=arr[r];
            found=1;
            l++,r--;
        }
        else if(sum>x)--r;
        else if(sum<x)++l;
    }
//end:
    if(found)cout<<best_a<<' '<<best_b<<'\n';
    else cout<<0<<'\n';
}
int main()
{
    cin>>n>>k;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];   
     }
    sort(arr,arr+n);
    while(k--){
        cin>>t;
        solve(t, arr);
    }
    delete[] arr;
    return 0;
}