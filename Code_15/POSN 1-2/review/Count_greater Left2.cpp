/*
    TASK:Count_greater Left2
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100005],temp[100005];
long long coun[100005];
int b[100005];
long long ans;
void mergesort(int st,int en)
{
    if(st==en)
        return ;
    int mid=(st+en)/2;
    mergesort(st,mid);
    mergesort(mid+1,en);
    int i=st,j=mid+1,k=st;
    while(i<=mid&&j<=en)
    {
        if(a[i].first<=a[j].first)
            temp[k++]=a[i++];
        else
        {
            coun[a[j].second]+=mid-i+1;
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=en)
        temp[k++]=a[j++];
    for(i=st;i<=en;i++)
        a[i]=temp[i];
}
int main()
{
    int q,i,n,att;
    scanf("%d",&q);
    while(q--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            a[i]={b[i],i};
        }
        memset(coun,0,sizeof(coun));
        mergesort(0,n-1);
        for(i=0;i<n;i++){
        printf("%d ",coun[i]);
        }
        printf("\n");
    }
    return 0;
}
