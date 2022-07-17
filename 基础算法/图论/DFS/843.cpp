#include<bits/stdc++.h>
using namespace std;

const int N=10;
int n;
char graph[N][N];
bool col[N],dg[N],redg[N];

void dfs(int row)
{
    if(row==n)    //叶子节点
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<graph[i][j];
            cout<<endl;
        }
        cout<<endl;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!col[i]&&!dg[i-row+n]&&!redg[i+row])   //y=x+b 与 y=-x+b，第一个可能是负值，所以需要一个偏移量
        {
            col[i]=dg[i-row+n]=redg[i+row]=true;  //保存断点
            graph[row][i]='Q';
            dfs(row+1);
            col[i]=dg[i-row+n]=redg[i+row]=false; //恢复现场
            graph[row][i]='.';
        }
    }
}

int main()
{
    fill(graph[0],graph[0]+N*N,'.');
    cin>>n;
    dfs(0);
}
