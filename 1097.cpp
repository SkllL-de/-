#include <iostream>
using namespace std;
const int N=100005;
long long arr[N];
int n,k;
int lowbit(int x){
    return x&(-x);
}
void add(int i,int x){
    for(;i<=n;i+=lowbit(i)){
        arr[i]+=x;
    }
}
long long query(int i){
    long long res=0;
    for(;i>=1;i-=lowbit(i)){
        res+=arr[i];
    }
    return res;
}
int main()
{
    cin>>n>>k;
    int t;
    for(int i=1;i<=n;i++){
        cin>>t;
        add(i,t);
    }
    char op='\0';
    int i,j,d;
    while(k--){
        cin>>op;
        if(op=='U'){
            cin>>i>>d;
            add(i,d);
        }
        else{
            cin>>i>>j;
            cout<<query(j)-query(i-1)<<'\n';
        }
    }
    return 0;
}