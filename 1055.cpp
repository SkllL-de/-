#include <iostream>
using namespace std;
const int N=1030;
long long arr[N][N];
long long res[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int h,w,r;
    cin>>h>>w>>r;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>arr[i][j];
            arr[i][j]=arr[i][j]+arr[i-1][j]
                    +arr[i][j-1]
                    -arr[i-1][j-1];
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            int sx=max(1,i-r);
            int sy=max(1,j-r);
            int ex=min(h,i+r);
            int ey=min(w,j+r);
            long long sum=0;
            sum=arr[ex][ey]-arr[sx-1][ey]-arr[ex][sy-1]+arr[sx-1][sy-1];
            res[i][j]=sum/((ex-sx+1)*(ey-sy+1));
        }
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<w;j++){
            cout<<res[i][j]<<' ';
        }
        cout<<res[i][w]<<'\n';
    }
    return 0;
}