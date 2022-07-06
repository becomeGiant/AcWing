#include<bits/stdc++.h>
using namespace std;

string a;
int b,temp;
vector<int> A;

vector<int> div(vector<int> a,int b)
{
    vector<int> c;
    reverse(a.begin(),a.end());   //求商需要从高位开始处理
    for(int i=0;i<a.size();i++)
    {
        temp=temp*10+a[i];
        c.push_back(temp/b);
        temp%=b;
    }
    reverse(c.begin(),c.end());   //1.为去除前导0做准备 2.与其他运算答案的排序保持一致
    while(c.size()>1&&c.back()==0) c.pop_back();
    return c;
}

int main()
{
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    vector<int> c=div(A,b);
    for(int i=c.size()-1;i>=0;i--)
        cout<<c[i];
    cout<<endl<<temp;
}
