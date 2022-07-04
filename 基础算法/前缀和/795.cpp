前缀和：可以预处理数据，把计算两个区间的值从O(n)优化为O(1)
本题为一维区间

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
int a[N],s[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=0,j,k;i<m;i++)
    {
        cin>>j>>k;
        cout<<s[k]-s[j-1]<<endl;
    }
}
