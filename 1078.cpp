#include<iostream>
#include<cmath>
using namespace std;
int st[100005][25];
int log_2[20];
void query(int a, int b){
    int k=log_2[b-a+1];
    cout<<max(st[a][k],st[b-(1<<k)+1][k])<<'\n';
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>st[i][0];
    }
    for(int i=2;i<=100005;i++){
        if((i&(i-1))==0)log_2[i]=log_2[i/2]+1;
        else log_2[i]=log_2[i-1];
    }
    for(int k=1;k<=20;k++){
        for(int i=1;i+(1<<k)-1<=n;i++){
            st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][(k-1)]);
        }
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        query(a,b);
    }
    return 0;
}