1.将每个区间按右端点从小到大排序  
2.从前往后依次枚举每个区间  
    如果当前区间中已经包含点，则Pass  
    否则，选择当前区间的右端点(局部最优)

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct Range
{
    int l,r;
    bool operator < (const Range &W) const  //重载＜
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
