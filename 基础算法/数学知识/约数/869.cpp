试除法求约数
1.从小到大依次枚举所有数
  优化的算法同"试除法求质数"

#include<bits/stdc++.h>
using namespace std;

int n,m;
set<int> res;

void divisor(int x)
{
    res.clear();
    for(int i=1;i<=x/i;i++)
    {
        if(x%i==0)
        {
            res.insert(i);
            res.insert(x/i);
        }
    }
    for(auto i:res)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        divisor(m);
    }
}
