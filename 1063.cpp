#include<iostream>
#include<string>
using namespace std;
int pmt[100005];
int main()
{
    string s;
    cin>>s;
    int j=0;
    int m=s.length();
    for(int i=1;i<m;i++){
        while(j>0&&s[j]!=s[i]){
            j=pmt[j-1];
        }
        if(s[j]==s[i]){j++;}
        pmt[i]=j;
    }
    for(int i=0;i<m-1;i++)cout<<pmt[i]<<' ';
    cout<<pmt[m-1];
    return 0;
}
/*void solve2(string s){
        int i=1,lenj=0;
    int m=s.length();
    while(i<m){
        if(s[i]==s[lenj]){
            lenj++;
            pmt[i]=lenj;
            i++;
        }else if(lenj!=0){
            lenj=pmt[lenj-1];
        }else{
            pmt[i]=0;
            i++;
        }
    }
}*/
// #include<iostream>
// #include<string>
// using namespace std;
// int pmt[100005];
// void solve1(string s){    
//     int m=s.length();
//     for(int i=1;i<m;i++){//最后一位字符编号是i的字符串，长度为i+1
//         for(int len=i;len>=1;len--){
//             bool match=1;
//             for(int j=0;j<len;j++){
//                 if(s[j]!=s[i-len+1+j]){
//                     match=0;
//                     break;
//                 }
//             }
//             if(match){
//                 pmt[i]=len;
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     string s;
//     cin>>s;
//     int m=s.length();
//     solve1(s);
//     for(int i=0;i<m;i++)cout<<pmt[i]<<' ';
//     return 0;
// }