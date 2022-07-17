先把所有入度为0的点入队  初始化
while(队列非空)
    枚举队头的所有出边
        删除边(度数)
        拓展队列(度数)
若输出的点数小于图中的点数，则表示该图存在回路，即无法拓扑排序(环中不存在入度为0的点)

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
vector<int> e[N];
int du[N];
queue<int> q;
vector<int> ans;

bool topSort()
{
    for(int i=1;i<=n;i++)
        if(du[i]==0)
            q.push(i);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        ans.push_back(cur);
        for(auto i:e[cur])
        {
            du[i]--;
            if(du[i]==0)
                q.push(i);
        }
    }
    if(ans.size()==n)
        return true;
    else
        return false;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        du[b]++;
    }
    if(topSort())
    {
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
    }
    else
        cout<<"-1";
}
