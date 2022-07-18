二分图的最大匹配问题：
比喻：男女的匹配问题
for 所有的男生
  为每个男生找对象
    for 意中人
      如果这个女生是单身 或者 可以为这个女生的对象找到下家(因为目前这个女生不是单身，所以找到的是下家)
        挖墙脚

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n1,n2,m;
vector<int> e[N];
bool visited[N];
int match[N];

bool find(int x)
{
    for(auto i:e[x])
    {
        if(!visited[i])
        {
            visited[i]=true;
            if(match[i]==0||find(match[i]))
            {
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n1>>n2>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
    }
    int res=0;
    for(int i=1;i<=n1;i++)
    {
        fill(visited,visited+N,false);
        if(find(i))
            res++;
    }
    cout<<res;
}
