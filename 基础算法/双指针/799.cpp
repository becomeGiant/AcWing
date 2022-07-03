

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
        state[a[i]]++;
        while(j<n&&state[a[i]]>1)
        {
            state[a[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}
