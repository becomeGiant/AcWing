#include<bits/stdc++.h>
using namespace std;

const int N=3e5+10;
typedef pair<int,int> PII;
int n,m;
int a[N],s[N];
vector<int> alls;
vector<PII> add,query;

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0,j,k;i<n;i++)
    {
        cin>>j>>k;
        add.push_back({j,k});
        alls.push_back(j);
    }
    for(int i=0,j,k;i<m;i++)
    {
        cin>>j>>k;
        query.push_back({j,k});
        alls.push_back(j);
        alls.push_back(k);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto i:add)
    {
        int x=find(i.first);
        a[x]+=i.second;
    }
    for(int i=1;i<=alls.size();i++)
        s[i]=s[i-1]+a[i];
    for(auto i:query)
    {
        int l=find(i.first),r=find(i.second);
        cout<<s[r]-s[l-1]<<endl;
    }
}
