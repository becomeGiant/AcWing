拓展欧几里得算法 的应用
真实方程 推得 目标公式

欧几里得：(a,b)=(b,a%b)=d
裴属定理：ax+by=d  真实方程
题目：ax%m=b  目标公式
  ax=my+b (y=ax/m)

#include<bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-a/b*y;
    return d;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,x,y,m;
        cin>>a>>b>>m;
        int d=exgcd(a,m,x,y);
        if(b%d==0)
            cout<<(long long)x*(b/d)%m<<endl;   //方程两边同乘b/d
        else
            cout<<"impossible"<<endl;
    }
}
