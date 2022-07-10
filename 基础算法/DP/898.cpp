思路:
状态表示：所有走法--->所有从起点，走到(i,j)的路径
状态转移：来自左上f[i-1,j-1]和右上f[i-1,j]

#include<bits/stdc++.h>
using namespace std;

const int N=510;
const int inf=1e9;
int n;
int a[N][N];
int f[N][N];

int main()
{
    fill(f[0],f[0]+N*N,-inf);   //解决边界问题
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            cin>>a[i][j];
    f[1][1]=a[1][1];           //初始化起点状态
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
        {
            f[i][j]=max(f[i-1][j-1],f[i-1][j])+a[i][j];
        }
    int maxn=-inf;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,f[n][i]);
    cout<<maxn;
}
