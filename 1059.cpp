#include<iostream>
using namespace std;
void dfs(int n, char s ,char t, char m){
    if(n==1){
        cout<<1<<' '<<s<<' '<<t<<'\n';
        return;
    }
    dfs(n-1, s, m, t);
    cout<<n<<' '<<s<<' '<<t<<'\n';
    dfs(n-1,m,t,s);
}
int main()
{
    int n;
    cin>>n;
    dfs(n,'A','B','C');
    return 0;
}