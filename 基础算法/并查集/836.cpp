并查集：
1.两个集合合并
2.询问两个元素是否在一个集合中

基本原理：每个集合用一棵树来表示。树根的编号就是整个集合的编号。每个节点存储它的父节点，pre[x]表示x的父节点。
关键：根节点的pre[x]=x
合并两个集合：pre[x]是x的集合编号，pre[y]是y的集合编号，pre[x]=y，即一个集合作为另一个集合的孩子

路径压缩优化：所有的子节点都指向根节点，这样只需要搜索一次

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
