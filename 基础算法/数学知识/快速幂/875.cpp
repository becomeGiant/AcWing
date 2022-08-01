算法原理：百度百科
1.预处理
  每个数都是前一个数的平方倍 % p
  
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

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
    int n,a,k,p;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>k>>p;
        cout<<quickPower(a,k,p)<<endl;
    }
}
