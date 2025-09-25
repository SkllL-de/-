#include<iostream>
using namespace std;
const int N=100005;
int arr[N];
void solve(int n){
    int min=0x7f7f7f;
    int sum=-0x7f7f7f;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]-min>sum)sum=arr[i]-min;
        if(arr[i]<min)min=arr[i];
    }
    cout<<sum<<'\n';
}
int main()
{
    int n;
    while(cin>>n){
        solve(n);
    }
    return 0;
}