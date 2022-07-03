单调性思路：
数组A和B是升序的，总和x值不变，i指向A，j指向B
只有当i++，j--才有可能出现解
这样对于每一个i，不需要重新计算j的位置

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],b[N];

int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
    for(int i=0,j=m-1;i<n;i++)
    {
        while(j>=0&&a[i]+b[j]>x) j--;
        if(a[i]+b[j]==x)
        {
            cout<<i<<" "<<j;
            return 0;
        }
    }
}
