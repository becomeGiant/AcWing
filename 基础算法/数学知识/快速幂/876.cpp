快速幂求逆元
题目要求是求a的逆元,即a*a的逆元 恒等于 1(mod p)
p为质数,由费马定理可得答案公式

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
