完全背包：
状态表示：同01背包
状态转移(集合划分：从小状态(集合)到大状态(集合))：第i个物品选k个



优化前：
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
            for(int k=0;k*v[i]<=j;k++)
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
    cout<<f[n][m];
}



优化后：
优化思路：去除一个k循环。把f[i][j]的状态展开，寻找子状态(f[i][j-v]+w)进行替代优化
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
            if(j>=v[i])
                f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
        }
    cout<<f[n][m];
}
