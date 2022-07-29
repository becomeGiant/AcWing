求约数之和
  和=P1的0次幂+P1的1次幂+...+P1的A1次幂)*...*(Pk的0次幂+Pk的1次幂+...+Pk的Ak次幂(公式)
  证明：
    将上述公式展开就可以得到"原"约数之和

#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
map<int,int> primes;

void divide(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            int sum=0;
            while(n%i==0)
            {
                n/=i;
                sum++;
            }
            primes[i]+=sum;
        }
    }
    if(n>1)
        primes[n]++;
}

int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        divide(m);
    }
    long long res=1;
    for(auto i:primes)
    {
        long long temp=1;
        for(int j=0;j<i.second;j++)
        {
            temp=(temp*i.first+1)%mod;
        }
        res=res*temp%mod;
    }
    cout<<res;
}
