#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int pre[N],num[N];

int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        pre[i]=i;
        num[i]=1;
    }
    while(m--)
    {
        string s;
        cin>>s;
        int a,b;
        if(s=="C")
        {
            cin>>a>>b;
            if(find(a)==find(b))        //已经在一个集合中
                continue;
            num[find(b)]+=num[find(a)]; //维护所在集合的数量
            pre[find(a)]=find(b);
        }
        else if(s=="Q1")
        {
            cin>>a>>b;
            if(find(a)==find(b))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
        {
            cin>>a;
            cout<<num[find(a)]<<endl;
        }
    }
}
