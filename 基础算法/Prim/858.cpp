#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int inf=1e9;
int n,m,res;
int e[N][N];
int dist[N];  //点到集合的最短距离
bool visited[N];

void prim()
{
    fill(dist,dist+N,inf);
    dist[1]=0;
    for(int i=1;i<=n;i++)
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
        {
            res=0;
            break;
        }
        visited[nextv]=true;
        res+=dist[nextv];
        for(int j=1;j<=n;j++)
        {
            dist[j]=min(dist[j],e[nextv][j]);   //维护"其他点通过nextv到集合"的最短距离
        }
    }
}

int main()
{
    fill(e[0],e[0]+N*N,inf);
    cin>>n>>m;
    for(int i=0,j,k,l;i<m;i++)
    {
        cin>>j>>k>>l;
        e[j][k]=e[k][j]=min(e[j][k],l);   //解决重边问题
    }
    prim();
    if(res) cout<<res;
    else cout<<"impossible";
}
