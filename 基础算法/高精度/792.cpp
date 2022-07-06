#include<bits/stdc++.h>
using namespace std;

string a,b;
vector<int> A,B;

vector<int> sub(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int temp=0;   //借位
    for(int i=0;i<a.size();i++)
    {
        temp=a[i]-temp;
        if(i<b.size()) temp-=b[i];
        c.push_back((temp+10)%10);
        if(temp>=0) temp=0;
        else temp=1;
    }
    while(c.size()>1&&c.back()==0) c.pop_back();  //去除前导0
    return c;
}

bool cmp(vector<int> a,vector<int> b)
{
    if(a.size()!=b.size())
        return a.size()>b.size();
    for(int i=a.size()-1;i>=0;i--)
        if(a[i]!=b[i])
            return a[i]>b[i];
    return true;
}

int main()
{
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
        B.push_back(b[i]-'0');
    vector<int> c;
    if(cmp(A,B))
        c=sub(A,B);
    else
    {
        cout<<"-";
        c=sub(B,A);
    }
    for(int i=c.size()-1;i>=0;i--)
        cout<<c[i];
}
