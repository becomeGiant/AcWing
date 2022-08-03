由 拓展欧几里得算法 实现 裴属定理

列出两个公式可以推出结果
欧几里得：(a,b)=(b,a%b)=d
裴属定理：ax+by=d  目标公式
    bx+(a%b)y=d
    ay+b(x-a/b*y)=d 真实方程

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
    // cout<<"x:"<<x<<" y:"<<y<<endl;
    return d;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,x,y;
        cin>>a>>b;
        exgcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
}
