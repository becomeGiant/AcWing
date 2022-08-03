拓展欧几里得算法 的应用

裴属定理：ax+by=d
目标公式：ax%m=b
  ax+(-my)=b (y=ax/m)
  

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
        int a,b,m,x,y;
        cin>>a>>b>>m;
        int d=exgcd(a,m,x,y);
        if(b%d==0)  cout<<(long long)x*(b/d)%m<<endl;
        else cout<<"impossible"<<endl;
    }
}
