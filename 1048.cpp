#include<iostream>
#include<stack>
#include<utility>
using namespace std;
int n,m,t;
int directionX[4]={0,0,-1,1};
int directionY[4]={-1,1,0,0};
char grid[105][105];
bool visited[105][105];
bool found;
void dfs(int startX, int startY) {
    stack <pair<int,int> > s;
    s.push({startX,startY});
    visited[startX][startY] = true;
    while (!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        if (grid[x][y]=='T') {
            found = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x+directionX[i];
            int ny = y+directionY[i];
            if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&!visited[nx][ny]) {
                if (grid[nx][ny]=='T'||grid[nx][ny]=='.') {
                    s.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}
void solve() {
    int x=0,y=0;
    found=false;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            grid[i][j]='\0';
            visited[i][j]=false;
        }
    }
    cin>>n>>m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            cin>>grid[i][j];
            if (grid[i][j]=='S') {
                x=i,y=j;
                grid[i][j]='.';
            }
        }
    }
    dfs(x,y);
    if (found) {
        cout<<"Yes"<<'\n';
    }
    else {
        cout<<"No"<<'\n';
    }
}
int main()
{
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}