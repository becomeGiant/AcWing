#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N];

void quickSort(int l,int r)
{
    if(l>=r) return;
    int mid=a[l+r>>1],i=l-1,j=r+1;  //这里为模板，不用考虑边界问题
    while(i<j)
    {
        do i++; while(a[i]<mid);
        do j--; while(a[j]>mid);
        if(i<j) swap(a[i],a[j]);
    }
    quickSort(l,j);
    quickSort(j+1,r);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quickSort(0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
