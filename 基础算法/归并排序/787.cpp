#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N],temp[N];

void mergeSort(int l,int r)
{
    if(l>=r) return;
    int mid=l+r>>1;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    int i=l,j=mid+1,cnt=0;
    while(i<=mid&&j<=r)         //所有的"="为模板需要，可以不考虑边界情况
    {
        if(a[i]<=a[j]) temp[cnt++]=a[i++];
        else temp[cnt++]=a[j++];
    }
    while(i<=mid) temp[cnt++]=a[i++];
    while(j<=r) temp[cnt++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++)
        a[i]=temp[j];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergeSort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
