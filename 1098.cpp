#include <iostream>
#include <string>
using namespace std;
string a,b;
char s[100005];
int main()
{
    cin>>a>>b;
    int m=a.length()-1;
    int n=b.length()-1;
    int i=0,t=0,nxt=0;
    while(m>=0&&n>=0){
        t=nxt+a[m]-'0'+b[n]-'0';
        s[i]=t%10+'0';
        if(t>9)nxt=1;
        else nxt=0;
        m--;n--;i++;
    }
    while(m>=0){
        t=nxt+a[m]-'0';
        s[i]=t%10+'0';
        if(t>9)nxt=1;
        else nxt=0;
        m--;i++;
    }
    while(n>=0){
        t=nxt+b[n]-'0';
        s[i]=t%10+'0';
        if(t>9)nxt=1;
        else nxt=0;
        n--;i++;
    }
    if(nxt==1){
        s[i]='1';
        i++;
    }
    for(int j=i-1;j>=0;j--)cout<<s[j];
    return 0;
}