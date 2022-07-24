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
