有边数限制的最短路
for N次(经过不超过N条边的最短路)
  备份最短路 //防止出现串联更新
  for 所有边(从A到B存在一条权重为W的边)
    dist[b]=min(dist[b],dist[a]+w)

3点 3边 2次
1 2 1
2 3 1
1 3 3
1--->2--->3   1--->3
第一次迭代：利用上次的dist(backup)更新1-2,2-3,1-3，结果为0,1,3(2-3更新的结果是无穷+1)
第二次迭代：利用上次的dist(backup)更新1-2,2-3,1-3，结果为0,1,2

#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int inf=1e9;
struct Edge
{
    int a,b,w;
};
int n,m,k;
vector<Edge> e;
int dist[N],backup[N];

void bellmanFord()
{
    fill(dist,dist+N,inf);    //初始化
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof(dist));
        for(auto j:e)
        {
            dist[j.b]=min(dist[j.b],backup[j.a]+j.w);
        }
    }
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        Edge temp;
        cin>>temp.a>>temp.b>>temp.w;
        e.push_back(temp);
    }
    bellmanFord();
    if(dist[n]>inf>>1)    //可能存在负权边，所以dist不会完全等于inf
        cout<<"impossible";
    else
        cout<<dist[n];
}
