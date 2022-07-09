分组背包问题：
状态表示：同01背包
状态转移(集合划分：从小状态(集合)到大状态(集合))：放第k个，不放

无优化
#include<bits/stdc++.h>
using namespace std;

const int N=110;
int n,m;
int v[N][N],w[N][N],s[N];
int f[N][N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i];j++)
            cin>>v[i][j]>>w[i][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j];
            for(int k=0;k<s[i];k++)
                if(j>=v[i][k])
                    f[i][j]=max(f[i][j],f[i-1][j-v[i][k]]+w[i][k]);
        }
    cout<<f[n][m];
}



优化
#include<bits/stdc++.h>
using namespace std;

const int N=110;
int n,m;
int v[N][N],w[N][N],s[N];
int f[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<s[i];j++)
            cin>>v[i][j]>>w[i][j];
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=0;j--)
            for(int k=0;k<s[i];k++)
            {
                if(j>=v[i][k])
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
            }
    cout<<f[m];
}
