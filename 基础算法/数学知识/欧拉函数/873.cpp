欧拉函数Φ(n)：(1~n中与n互质(最大公约数为1)的数的个数)
  Φ(N)=N*(1-1/P1)*(1-1/P2)*...*(1-1/Pk),N为幂次表示
  证明：
    百度百科(合并容斥原理)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        int res=m;
        for(int j=2;j<=m/j;j++)
        {
            if(m%j==0)
            {
                res=res-res/j;  //算式化简(整除运算)
                while(m%j==0)
                {
                    m/=j;
                }
            }
        }
        if(m>1)
            res=res-res/m;
        cout<<res<<endl;
    }
}
