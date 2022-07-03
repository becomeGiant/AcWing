双指针可以把时间复杂度从O(n^2)优化为O(n)
双指针题目通常具有单调性规律

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N];
int state[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=0,j=0;i<n;i++)
    {
        state[a[i]]++;              //通过标记实现重复子序列的记录
        while(j<n&&state[a[i]]>1)   //处理重复子序列
        {
            state[a[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}
