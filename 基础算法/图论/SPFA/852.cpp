start---...--->a--->b
根据SPFA的松弛操作：dist[b]=min(dist[b],dist[a]+w)，表示从a到b具有更小的距离
cnt[b]=cnt[a]+1
cnt[b]表示从起点(start)到b中所有的点的数量，即上述表示b拥有的点数为从start到a再加上b
根据抽屉原理，如果一条点数为n的路径上具有≥n的边数，则必存在重复的点

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
int cnt[N];

bool spfa()
{
    fill(dist,dist+N,inf);
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
        visited[i]=true;
    }
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
                cnt[i.b]=cnt[cur]+1;
                if(cnt[i.b]>=n)
                    return true;
            }
        }
    }
    return false;
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
    if(spfa())
        cout<<"Yes";
    else
        cout<<"No";
}
