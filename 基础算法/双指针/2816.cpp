单调性：
A和B是顺次匹配
证明：
1.双指针做法可以找到一种匹配方式
2.如果存在一种匹配方式，则上述算法必然可以找出一个匹配

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],b[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    for(int i=0,j=0;i<n;i++,j++)
    {
        while(j<m&&a[i]!=b[j])
            j++;
        if(j==m)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
