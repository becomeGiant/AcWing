#include<bits/stdc++.h>
using namespace std;

const int N=1e2+10,M=1e4+10;
int n,m;
int a[N],f[M];

int sg(int x)   //SG函数(SG(x)=mex{SG(y) | y是x的后继}，SG(终点)=0)
{
    if(f[x]!=-1)    //记忆化搜索
        return f[x];
    vector<int> s;
    for(int i=0;i<m;i++)
    {
        int sub=a[i];
        if(x>=sub)
            s.push_back(sg(x-sub));   //后续状态
    }
    for(int i=0;;i++)     //Mex运算(表示最小的不属于这个集合的非负整数)
        if(find(s.begin(),s.end(),i)==s.end())
            return f[x]=i;
}

int main()
{
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    fill(f,f+M,-1);
    cin>>n;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        res^=sg(x);
    }
    if(res)
        cout<<"Yes";
    else
        cout<<"No";
}
