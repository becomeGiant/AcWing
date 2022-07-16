#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int inf=1e9;
int n,m;
int e[N][N];
int dist[N];
bool visited[N];

void dijkstra()
{
    fill(dist,dist+N,inf);
    dist[1]=0;
    for(int i=0;i<n;i++)
    {
        int nextv=-1,minn=inf;
        for(int j=1;j<=n;j++)
        {
            if(!visited[j]&&dist[j]<minn)
            {
                nextv=j;
                minn=dist[j];
            }
        }
        if(nextv==-1)
            break;
        visited[nextv]=true;
        for(int j=1;j<=n;j++)
        {
            if(dist[nextv]+e[nextv][j]<dist[j])
            {
                dist[j]=dist[nextv]+e[nextv][j];
            }
        }
    }
}

int main()
{
    fill(e[0],e[0]+N*N,inf);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        e[a][b]=min(e[a][b],c); //解决重边
    }
    dijkstra();
    if(dist[n]!=inf)
        cout<<dist[n];
    else
        cout<<"-1";
}
