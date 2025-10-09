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
//     for(int i=1;i<m;i++){
//      //最后一位字符编号是i的字符串，长度为i+1
//      //i是位置，从*第2个字符*到*第m-1个字符*(即最后一个字符)
//      //i从第二个字符开始是因为第一个字符的最长公共前后缀一定为0(字符串的最长真公共前后缀不能算*自己本身*和*自己本身*)
//         for(int len=i;len>=1;len--){ abcabc // aaa->aa,aa
//          //第i位向前找，找从第0位开始最长的和后面第i-len+1位开始，最长的相等的字符串的长度
//          //len不行，就找长为len-1的串（短一个的串）
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