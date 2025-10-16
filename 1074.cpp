#include<iostream>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;
void solve();//异或 解
void solve1();//map解
void solve2();//set解
int main()
{
    //solve();
    //solve1();
    solve2();
    return 0;
}
void solve(){
    int n,p=0,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        p=p^t;
    }
    cout<<p;
}
void solve1(){
    unordered_map<int,int> mm;
    //或者map<int,int> mm;
    int n=0,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        mm[t]++;
    }
    for(const auto &[key, value]: mm){
        if(value==1){cout<<key;break;}
    }
}
void solve2(){
    set<int> set1;
    int n=0,t;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(set1.count(t)){
            set1.erase(t);
        }else{
            set1.insert(t);
        }
    }
    cout<<*set1.begin();
}