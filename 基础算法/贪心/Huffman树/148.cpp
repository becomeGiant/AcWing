证明
1.最小的两个点，深度一定最深，且可以互为兄弟
（反证法）最先合并的必定是合并次数最多的，合并次数越多意味着这两个数加的次数越多，加的数越大那么自然答案也会变大，这样就不是最优解了，所以每次必须合并两堆最小的。剩下每次合并同理。

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> heap;  //优先队列-小根堆
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        heap.push(x);
    }
    int ans=0;
    while(heap.size()>1)
    {
        int a=heap.top(); heap.pop();
        int b=heap.top(); heap.pop();
        ans+=a+b;
        heap.push(a+b);
    }
    cout<<ans;
}
