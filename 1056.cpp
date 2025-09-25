#include<iostream>
using namespace std;
void solve(int x){
    int sum=0;
    sum+=x/100;x-=x/100*100;
    sum+=x/50;x-=x/50*50;
    sum+=x/20;x-=x/20*20;
    sum+=x/10;x-=x/10*10;
    sum+=x/5;x-=x/5*5;
    sum+=x/2;x-=x/2*2;
    sum+=x/1;//x-=x/1*1;
    cout<<sum<<'\n';
}
int main()
{
    int n,k;
    cin>>n;
    while(n--){
        cin>>k;
        solve(k);
    }
    return 0;
}