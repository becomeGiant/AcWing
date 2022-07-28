埃氏筛法
由唯一分解定理,只需要筛质数就可以了

#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,cnt;
bool state[N];

void getPrime(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(!state[i])
        {
            cnt++;
            for(int j=i+i;j<=n;j+=i)
                state[j]=true;
        }
    }
}

int main()
{
    cin>>n;
    getPrime(n);
    cout<<cnt;
}
