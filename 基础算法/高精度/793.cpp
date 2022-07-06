#include<bits/stdc++.h>
using namespace std;

string a;
int b;
vector<int> A;

vector<int> mul(vector<int> &a,int b)
{
    vector<int> c;
    int temp=0;
    for(int i=0;i<a.size();i++)
    {
        temp+=a[i]*b;
        c.push_back(temp%10);
        temp/=10;
    }
    if(temp) c.push_back(temp);
    while(c.size()>1&&c.back()==0) c.pop_back();
    return c;
}

int main()
{
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    vector<int> c=mul(A,b);
    for(int i=c.size()-1;i>=0;i--)
        cout<<c[i];
}
