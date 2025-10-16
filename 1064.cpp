#include<iostream>
#include<string>
using namespace std;
int pmt[100005];
void nxt(string t){
    int m=t.length();
    int j=0;
    for(int i=1;i<m;i++){
        while(j>0&&t[j]!=t[i])j=pmt[j-1];
        if(t[j]==t[i])j++;
        pmt[i]=j;
    }
}
void solve(string s, string t){
    nxt(t);
    int n=s.length();
    int m=t.length();
    int j=0;
    for(int i=0;i<n;i++){
        while(j>0&&t[j]!=s[i]){
            j=pmt[j-1];
        }
        if(t[j]==s[i]){j++;}
        if(j==m){
            cout<<i-m+1<<'\n';
            return;
        }
    }
    cout<<n<<'\n';
}
int main()
{
    string s,t;
    while(cin>>s>>t){
        solve(s,t);
    }
    return 0;
}