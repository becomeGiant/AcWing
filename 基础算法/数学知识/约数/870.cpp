1.求约数个数
  一个数的幂次表示为N=P1的A1次幂*P2的A2次幂*...*Pk的Ak次幂(唯一分解定理)
  个数=(A1+1)*(A2+1)*...*(Ak+1)(公式)
  证明：
    由唯一分解定理,一个数的所有约数也是质数,所以这些约数也可以使用幂次表示
    M=P1的B1次幂*P2的B2次幂*...*Pk的Bk次幂(约数,唯一分解定理),且0≤Bi≤Ai
    
#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
map<int,int> primes;

void divide(int x)
{
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)
        {
            int sum=0;
            while(x%i==0)
            {
                x/=i;
                sum++;
            }
            primes[i]+=sum;
        }
    }
    if(x>1)
        primes[x]+=1;
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
        res=res*(i.second+1)%mod;
    cout<<res;
}
