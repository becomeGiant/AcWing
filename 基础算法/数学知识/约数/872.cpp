1.最大公约数
  欧几里得算法(辗转相除法)
  证明：
    百度百科
  
#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    return b ? gcd(b,a%b):a;
}

int main()
{
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
}
