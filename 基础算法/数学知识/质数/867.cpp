分解质因数(短除法分解)
如果其中某个质因数多次出现,则可以用幂次的形式表示
当试除数是i时,表示已经把2~i-1中的所有质因子除完
例如i=3时,表示n一定不含2

#include<bits/stdc++.h>
using namespace std;

void divide(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)  //i一定是质数
        {
            int sum=0;
            while(n%i==0)
            {
                n/=i;
                sum++;
            }
            printf("%d %d\n",i,sum);  //幂次表示
        }
    }
    if(n>1) //剩余的数是质数
        printf("%d %d\n",n,1);
    cout<<endl;
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
}
