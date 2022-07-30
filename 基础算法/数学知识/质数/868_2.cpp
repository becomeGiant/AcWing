原理：n只会被最小质因子筛除
  primes[]是存放质数的
  i%primes[j]==0
    primes[j]一定是i的最小质因子,primes[j]一定是primes[j]*i的最小质因子
  i%primes[j]!=0
    primes[j]一定小于i的所有质因子,primes[j]一定是primes[j]*i的最小质因子

#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int primes[N],cnt;
bool state[N];

int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(!state[i])
            primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            state[primes[j]*i]=true;
            if(i%primes[j]==0)  //primes[j]是最小质因子
                break;
        }
    }
    cout<<cnt;
}
