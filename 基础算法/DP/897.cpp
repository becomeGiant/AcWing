状态表示：所有"公共"子序列
对于A字符串而言：acbd
假设状态表示的是第i个的所有子序列
1.空 a
2.空 a c ac
3.空 a c b ac ab cb acb
4.空 a c b d ac ab ad cb cd bd acb acd abd cbd acbd
从1可以转移到2，从2可以转移到3，从3可以转移到4，转移条件：最后一个元素的"选"与"不选"
本题要求的是"公共"，所以就存在两个字符串
最后根据两个字符串的"选"与"不选"组合可以得到四种的集合划分

状态转移：根据上述的状态表示，可以分成00 01 10 11四种情况

#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int n,m;
char a[N],b[N];
int f[N][N];

int main()
{
    cin>>n>>m;
    scanf("%s%s",a+1,b+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
        }
    cout<<f[n][m];
}
