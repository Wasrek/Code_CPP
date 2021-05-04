/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
    int q,k,n,ma1,ma2,ma,now;
    scanf("%d",&q);
    for(int Q=1;Q<=q;Q++){
        scanf("%d %d\n",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        ma1=ma2=ma=0;
        for(int i=1;i<=n;i++){
            if(a[i]-a[i-1] <= 1) continue;
            if(i==1){
                ma=max(ma,a[i]-1);
                // printf("%d %d\n",i,ma);
                if(ma>=ma1){
                    ma2=ma1;
                    ma1=ma;
                }else if(ma>ma2) ma2=ma;
                continue;
            }
            ma=max(ma,a[i]-a[i-1]-1);
            if(a[i]-a[i-1]<=1) continue;
            now=max((a[i]-a[i-1]-2)/2+1,(a[i]-a[i-1])/2);
            // printf("%d %d %d\n",i,(a[i]-a[i-1]-2)/2,now);
            if(now>=ma1){
                ma2=ma1;
                ma1=now;
            }else if(now>ma2) ma2=now;
        }
        ma=max(ma,k-a[n]);
        // printf("%d %d\n",n+1,k-a[n])/;
        if(k-a[n]>=ma1){
            ma2=ma1;
            ma1=k-a[n];
        }else if(k-a[n]>ma2) ma2=k-a[n];
        if(ma>ma1+ma2) ma1=ma,ma2=0;
        // printf("%d %d\n",ma1,ma2);
        printf("Case #%d: %lf\n",Q,((double)(ma1+ma2))/k);
    }
    return 0;
}