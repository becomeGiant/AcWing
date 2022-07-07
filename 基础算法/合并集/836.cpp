#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int pre[N];

int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);  //路径压缩
    return pre[x];            //返回x的祖宗节点
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        pre[i]=i;
    for(int i=0;i<m;i++)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(s=="M")
            pre[find(a)]=find(b);
        else
            if(find(a)==find(b))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
    }
}
