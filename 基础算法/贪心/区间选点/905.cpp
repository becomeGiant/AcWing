1.将每个区间按右端点从小到大排序  
2.从前往后依次枚举每个区间
    如果当前区间中已经包含点，则Pass  
    否则，选择当前区间的右端点

证明：
设ans是所有合法方案中的最小值,cnt是一种合法方案
1.ans≤cnt
上述选法必然会使每个区间里至少包含一个点，是一种合法方案，所以ans≤cnt(围绕cnt往大了说)
2.ans≥cnt
通过贪心方案我们知道序列中包含了cnt个相互之间没有交集的区间，所以对于一个合法方案，必然至少包含cnt个点，所以ans≥cnt(围绕cnt往小了说)

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct Range
{
    int l,r;
    bool operator < (const Range &W) const  //重载<
    {
        return r<W.r;
    }
};
int n;
Range a[N];

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        a[i].l=l;
        a[i].r=r;
    }
    sort(a,a+n);
    int ans=0,ed=-2e9;
    for(int i=0;i<n;i++)
        if(a[i].l>ed)
        {
            ans++;
            ed=a[i].r;
        }
    cout<<ans;
}
