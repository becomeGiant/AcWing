由 拓展欧几里得算法 实现 裴属定理
列出两个公式可以推出结果(注意x和y的互换)

#include<bits/stdc++.h>
using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y=y-a/b*x;
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
