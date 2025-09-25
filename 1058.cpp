#include <iostream>
using namespace std;
int main()
{
    long long a,b,p,res=1;
    cin>>a>>b>>p;
    while(b){
        if(b&1){
            res*=a;
            res%=p;
        }
        /*else{
            res*=1;
            res%=p
        }*/
        b>>1;
        a=a*a%p;
    }
    cout<<res;
    return 0;
}