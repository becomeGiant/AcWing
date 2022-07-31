筛法求欧拉函数
1.质数i的欧拉函数为i-1
2.i%primes[j]==0
  Φ(i)=i*(1-1/P1)*(1-1/P2)*...*(1-1/Pk)
  Φ(primes[j]*i)=primes[j]*i*(1-1/P1)*(1-1/P2)*...*(1-1/Pk)=primes[j]*Φ(i)
3.i%primes[j]!=0
  Φ(i)=i*(1-1/P1)*(1-1/P2)*...*(1-1/Pk)
  Φ(primes[j]*i)=primes[j]*i*(1-1/P1)*(1-1/P2)*...*(1-1/Pk)*(1-1/Pj)=primes[j]*Φ(i)*(1-1/Pj)

#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int primes[N],cnt;
bool state[N];
int phi[N];

int main()
{
    int n;
    cin>>n;
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!state[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            state[primes[j]*i]=true;
            if(i%primes[j]==0)
            {
                phi[primes[j]*i]=phi[i]*primes[j];
                break;
            }
            phi[primes[j]*i]=phi[i]*(primes[j]-1);
        }
    }
    long long res=0;
    for(int i=1;i<=n;i++)
        res+=phi[i];
    cout<<res;
}
