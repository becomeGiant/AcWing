01背包问题思路：
状态表示(集合)：所有选法--->满足只从前i个物品中选，且总体积<=j
状态转移(集合划分：从小状态(集合)到大状态(集合))：包含i(曲线救国，先剔除i，从不包含i的角度出发，再加上i)与不包含i

无优化
#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int n,m;
int v[N],w[N];
int f[N][N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i]) f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    cout<<f[n][m];
}



优化后
#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int n,m;
int v[N],w[N];
int f[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    cout<<f[m];
}
