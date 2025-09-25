#include<iostream>
#include<queue>
using namespace std;
char arr[105][105];
bool vis[105][105];
int dis[105][105];
int moveX[4]={0,0,-1,1};
int moveY[4]={-1,1,0,0};
int main()
{
    int n,m;
    queue<pair<int,int> >qq;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='S'){
                arr[i][j]='.';
                vis[i][j]=1;
                qq.push({i,j});
            }
        }
    }
    while(!qq.empty()){
        int x = qq.front().first;
        int y = qq.front().second;
        qq.pop();
        for(int i=0;i<4;i++){
            int xx=x+moveX[i];
            int yy=y+moveY[i];
            if(arr[xx][yy]=='T'){
                cout<<dis[x][y]+1;
                return 0;
            }
            else if(arr[xx][yy]=='.'){
                if(!vis[xx][yy]){
                    qq.push({xx,yy});
                    vis[xx][yy]=1;
                    dis[xx][yy]=dis[x][y]+1;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}