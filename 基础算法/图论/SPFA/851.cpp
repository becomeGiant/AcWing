SPFA算法是对BellmanFord算法的优化
优化思路：
BellmanFord算法的松弛公式：dist[b]=min(dist[b],dist[a]+w)，如果dist[a]没有变小，dist[b]也不可能变小

初始化队列
while(队列非空)
  枚举队头的所有出边
    更新(只要有某个点的距离被更新了，就把它加到队列中，去更新其它点，所有每个点有被重复加入队列的可能)
    拓展队列(值发生变化)
  
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int inf=1e9;
struct Edge
{
    int b,w;
};
int n,m;
vector<Edge> e[N];
int dist[N];
bool visited[N];
queue<int> q;

void spfa()
{
    fill(dist,dist+N,inf);
    dist[1]=0;
    q.push(1);
    visited[1]=true;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        visited[cur]=false;
        for(auto i:e[cur])
        {
            if(dist[i.b]>dist[cur]+i.w)
            {
                dist[i.b]=dist[cur]+i.w;
                if(!visited[i.b])
                {
                    q.push(i.b);
                    visited[i.b]=true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        Edge temp;
        cin>>a>>temp.b>>temp.w;
        e[a].push_back(temp);
    }
    spfa();
    if(dist[n]>inf>>1)
        cout<<"impossible";
    else
        cout<<dist[n];
}
