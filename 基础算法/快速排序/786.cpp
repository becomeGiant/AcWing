#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
int a[N];

void quickSort(int l,int r)
{
    if(l>=r) return;
    int mid=a[l+r>>1],i=l-1,j=r+1;
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
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    quickSort(0,n-1);
    cout<<a[m-1];
}
