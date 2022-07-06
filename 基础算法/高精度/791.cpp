#include<bits/stdc++.h>
using namespace std;

string a,b;
vector<int> A,B;

vector<int> add(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int temp=0;
    for(int i=0;i<a.size();i++)
    {
        temp+=a[i];
        if(i<b.size()) temp+=b[i];
        c.push_back(temp%10);
        temp/=10;
    }
    if(temp) c.push_back(temp);
    return c;
}

bool cmp(vector<int> &a,vector<int> &b)
{
    if(a.size()!=b.size())
        return a.size()>b.size();
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i])
            return a[i]>b[i];
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
        c=add(A,B);
    else
        c=add(B,A);
    for(int i=c.size()-1;i>=0;i--)
        cout<<c[i];
}
