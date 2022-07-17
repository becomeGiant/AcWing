#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int inf=1e9;
int n,ans=inf;
vector<int> e[N];
bool visited[N];

int dfs(int curv)
{
    visited[curv]=true;     //有向无环图(树)无需标记数组
    int cursum=1,tempMax=0;
    for(auto i:e[curv])
    {
        if(!visited[i])
        {
            int child=dfs(i);       //未走过的连通子块的点数
            cursum+=child;
            tempMax=max(tempMax,child);
        }
    }
    tempMax=max(tempMax,n-cursum);  //已走过的连通子块的点数
    ans=min(ans,tempMax);
    return cursum;
}

int main()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1);
    cout<<ans;
}
