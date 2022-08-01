#include<bits/stdc++.h>
using namespace std;

int quickPower(int a,int k,int p)
{
    long long res=1;
    while(k)
    {
        if(k&1)
            res=res*a%p;
        k>>=1;
        a=(long long)a*a%p;
    }
    return res;
}

int main()
{
    int n,a,p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>p;
        if(a%p) cout<<quickPower(a,p-2,p)<<endl;
        else cout<<"impossible"<<endl;
    }
}
