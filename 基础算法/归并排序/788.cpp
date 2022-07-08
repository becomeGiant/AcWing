思路：假设在归并排序的过程中，其中某一个阶段是有序的
逆序对的来源：
1.两个数都来自左半边
2.两个数都来自右半边
3.一个数来自左半边，另一个数来自右半边

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N],temp[N];

long long mergeSort(int l,int r)
{
    if(l>=r) return 0;
    int mid=l+r>>1;
    long long res=mergeSort(l,mid)+mergeSort(mid+1,r);  //来源：1和2
    int i=l,j=mid+1,cnt=0;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j])
            temp[cnt++]=a[i++];
        else
        {
            temp[cnt++]=a[j++];
            res+=mid-i+1;        //来源：3
        }
    while(i<=mid) temp[cnt++]=a[i++];
    while(j<=r) temp[cnt++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++)
        a[i]=temp[j];
    return res;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<mergeSort(0,n-1);
}
