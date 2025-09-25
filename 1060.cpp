#include<iostream>
#include<cmath>
using namespace std;
const int N = 50005;
int arr[N],brr[N],f[N];//f[50005][50005]
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>arr[i];}
    for(int i=1;i<=m;i++){cin>>brr[i];}
    int pre,tmp;
    for(int i=1;i<=n;i++){
        pre=f[0];
        for(int j=1;j<=m;j++){
            tmp=f[j];
            if(arr[i]==brr[j]){
            //     f[i][j]=f[i-1][j-1]+1;
                f[j]=pre+1;
            }
            else{
            //     f[i][j]=max(f[i-1][j],f[i][j-1]);
                f[j]=max(f[j-1],f[j]);
            }
            pre=tmp;
        }
    }
    cout<<f[m];
    return 0;
}