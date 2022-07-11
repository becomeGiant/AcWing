思路：
状态表示：所有的上升子序列--->满足条件的第i个上升子序列
状态转移(分类：从以前的状态到现在的状态)：从前一个满足条件的状态值+1

#include<bits/stdc++.h>
using namespace std;

const int N=1010;
const int inf=1e9;
int n;
int a[N];
int f[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    fill(f,f+N,1);
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--)
        {
            if(a[i]>a[j])
                f[i]=max(f[i],f[j]+1);
        }
    int maxn=0;
    for(int i=0;i<n;i++)
        maxn=max(maxn,f[i]);
    cout<<maxn;
}
