回溯算法：记录前一个状态(父节点)
DFS：
1.层数(层数的实际意义，叶子节点)
2.断点(保存断点，恢复现场)
  
#include<bits/stdc++.h>
using namespace std;

const int N=10;
int n;
int path[N];
bool visited[N];

void dfs(int curv)
{
    if(curv==n)         //叶子节点
    {
        for(int i=0;i<n;i++)
            cout<<path[i]<<" ";
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;    //保存断点
            path[curv]=i;
            dfs(curv+1);
            visited[i]=false;   //恢复现场
            path[curv]=0;
        }
    }
}

int main()
{
    cin>>n;
    dfs(0);
}
