/*
    TASK:B-Partition
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int n,k,sum=0,ma=0,l,r,mid,now,cnt;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        ma=max(ma,a[i]);
    }
    l=ma;
    r=sum;
    // no to yes
    while(l<r){
        mid=(l+r)/2;
        now=a[1];
        cnt=1;
        for(int i=2;i<=n;i++){
            if(a[i]+now<=mid){
                now+=a[i];
            }else{
                now=a[i];
                cnt++;
            }
        }
        if(cnt<=k) r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}