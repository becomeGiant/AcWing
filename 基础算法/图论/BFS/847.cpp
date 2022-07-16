BFS:
边权为1的最短距离

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
vector<int> graph[N];
int dist[N];
queue<int> q;

void bfs()
{
    fill(dist,dist+N,-1);
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for(auto i:graph[cur])
        {
            if(dist[i]==-1)
            {
                dist[i]=dist[cur]+1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    bfs();
    cout<<dist[n];
}
