状态表示：所有的合并方式--->第i堆石子到第j堆石子合并成一堆的合并方式
1 3 5 2:
  1,3 5 2:
    3,5 2
    3 5,2
  1 3,5 2:
  1 3 5,2:
    1,3 5
    1 3,5
状态转移：最后的结果往前推一步--->以最后只有两堆合并成一堆为分界线的位置来分类
  f[i,k]+f[k+1,j]
  
#include<bits/stdc++.h>
using namespace std;

const int N=310;
const int inf=1e9;
int n;
int a[N],s[N];
int f[N][N];

int main()
{
    // fill(f[0],f[0]+N*N,inf);   //f[0,0]上的值不是0
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int l=i,r=i+len-1;
            f[l][r]=inf;
            for(int k=l;k<r;k++)
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    cout<<f[1][n];
}
