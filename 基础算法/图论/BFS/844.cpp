BFS:
1.边权为1
2.具有层次顺序

#include<bits/stdc++.h>
using namespace std;

const int N=110;
int n,m;
int graph[N][N],dist[N][N];
queue<pair<int,int>> q;

void bfs()
{
    fill(dist[0],dist[0]+N*N,-1);
    dist[0][0]=0;
    pair<int,int> cur={0,0};
    q.push(cur);
    int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
    while(!q.empty())
    {
        cur=q.front();    //取队头
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nextx=cur.first+dx[i],nexty=cur.second+dy[i];
            if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m&&graph[nextx][nexty]==0&&dist[nextx][nexty]==-1)
            {
                dist[nextx][nexty]=dist[cur.first][cur.second]+1;
                q.push({nextx,nexty});    //拓展队头
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>graph[i][j];
    bfs();
    cout<<dist[n-1][m-1];
}
