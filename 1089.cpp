#include<iostream>
using namespace std;
const int N=10005;
int arr[N],res[N],tr[N],n;
bool used[N];
int lowbit(int x){return x&(-x);}
void add(int i,int x){
    for(;i<=n;i+=lowbit(i)){
        tr[i]+=x;
    }
}
int query(int i){
    int sum=0;
    for(;i>=1;i-=lowbit(i)){
        sum+=tr[i];
    }
    return sum;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        add(i,1);
    }
    for(int i=n;i>=1;i--){
        int k=arr[i]+1;
        int l=1,r=n+1,mid=0,ans=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(query(mid)>=k){
                r=mid;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        add(ans,-1);
        res[i]=ans;
    }
    for(int i=1;i<n;i++){
        cout<<res[i]<<' ';
    }
    cout<<res[n];
    return 0;
}

void solve1(){
    for(int i=n;i>=1;i--){
        int k=arr[i]+1;
        int t=0;
        for(int j=1;j<=n;j++){
            if(!used[j])t++;
            if(t==k){
                res[i]=j;
                used[j]=1;
                break;
            }
        }
    }
}