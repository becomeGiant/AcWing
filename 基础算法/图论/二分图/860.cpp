性质：二分图 当且仅当 图中不含奇数环
如果一幅图是二分图，那么它就可以被2染色(作用：判断是否为二分图)
  
for 所有的连通子块
  if 未染色
    dfs() 染色
      未染色
      已染色

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
vector<int> e[N];
int visited[N];

bool dfs(int curv,int color)
{
    visited[curv]=color;
    for(auto i:e[curv])
    {
        if(!visited[i])
        {
            if(!dfs(i,3-color))
                return false;
        }
        else if(visited[i]==color)
            return false;
    }
    return true;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    bool flag=true;
    for(int i=1;i<=n;i++)
        if(!visited[i])
            if(!dfs(i,1))
            {
                flag=false;
                break;
            }
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
}
