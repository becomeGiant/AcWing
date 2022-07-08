先手必胜状态：可以走到某一个必败状态
先手必败状态：走不到任何一个必胜状态

Nim游戏结论：
A1^A2^......^An==0，先手必败
A1^A2^......^An!=0，先手必胜
证明：
已知A1^A2^......^An==x!=0
假设x的二进制表示中最高一位的1在第k位，则A1~An中必然存在一个数Ai，Ai的第k位是1
因为Ai^x<Ai，所以必然可以拿走Ai-(Ai^x)，使得Ai-(Ai-(Ai^x))=Ai^x(剩下)
最后，A1^A2^...^Ai^x^...^An=x^x=0

  
  
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,res=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        res^=x;
    }
    if(res)
        cout<<"Yes";
    else
        cout<<"No";
}
