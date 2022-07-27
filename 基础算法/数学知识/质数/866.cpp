1.约数是成对存在的
  d是n的约数,那么n/d也是n的约数
  如果从小到大依次枚举,那么只需要枚举满足d≤n/d的数

#include<bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    if(n<=1)
        return false;
    for(int i=2;i<=n/i;i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(prime(m))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
