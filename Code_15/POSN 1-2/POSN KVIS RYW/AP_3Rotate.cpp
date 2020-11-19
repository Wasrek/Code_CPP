/*
    TASK:AP_3Rotate
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
long long ans=0;
void merges(int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)/2;
    merges(l,mid);
    merges(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++],ans+=mid-i+1;
        }
    }
    while(i<=mid)
    {
        b[k++]=a[i++];
    }
    while(j<=r)
    {
        b[k++]=a[j++];
    }
    for(i=l; i<=r; i++)
    {
        a[i]=b[i];
    }
    return ;
}
int main()
{
    int q,n,i;
    scanf("%d",&q);
    while(q--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        merges(0,n-1);
        if(ans%2==0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}
