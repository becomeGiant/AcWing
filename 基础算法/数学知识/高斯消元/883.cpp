高斯消元
1.枚举每一列c(阶梯形矩阵)
  1.找到绝对值最大的一行
  2.将该行换到最上面
  3.将该行第一个数变成1
  4.将下面所有行的第c列消成0
2.化 行最简形矩阵

#include<bits/stdc++.h>
using namespace std;

const int N=110;
const double eps=1e-9;
int n;
double a[N][N];

int gauss()
{
    int c,r;
    for(c=0,r=0;c<n;c++)
    {
        int maxr=r;
        for(int i=r;i<n;i++)
            if(fabs(a[maxr][c])<fabs(a[i][r]))
                maxr=i;
        if(fabs(a[maxr][c])<eps)
            continue;
        for(int j=c;j<n+1;j++)
            swap(a[maxr][j],a[r][j]);
        for(int j=n;j>=c;j--)
            a[r][j]/=a[r][c];
        for(int i=r+1;i<n;i++)
            for(int j=n;j>=c;j--)
                a[i][j]-=a[i][c]*a[r][j];
        r++;
    }
    if(r<n)
    {
        for(int i=r;i<n;i++)
            if(fabs(a[i][n])>eps)
                return 0;
        return 2;
    }
    for(int i=n-2;i>=0;i--)
        for(int j=i+1;j<n;j++)
            a[i][n]-=a[i][j]*a[j][n];
    return 1;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n+1;j++)
            cin>>a[i][j];
    int ans=gauss();
    if(ans==0)
        cout<<"No solution";
    else if(ans==1)
    {
        for(int i=0;i<n;i++)
        {
            if(fabs(a[i][n])<eps)
                a[i][n]=0;
            printf("%.2f\n",a[i][n]);
        }
    }
    else
        cout<<"Infinite group solutions";
}
