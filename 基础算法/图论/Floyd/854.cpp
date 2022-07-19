多源点的最短路
三层循环，记住模板

#include<bits/stdc++.h>
using namespace std;

const int N=210;
const int inf=1e9;
int n,m,q;
int dist[N][N];

void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) dist[i][j]=0;    //初始化
            else dist[i][j]=inf;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(dist[a][b],c); //重边
    }
    floyd();
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        if(dist[a][b]>inf>>1)         //可能存在负权边
            cout<<"impossible"<<endl;
        else
            cout<<dist[a][b]<<endl;
    }
}
