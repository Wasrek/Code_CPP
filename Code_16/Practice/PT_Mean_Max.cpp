/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 300100
double a[N],qs[N],mi[N];
int main()
{
    int n,k,ch;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    double l=0,r=1e6,mid;
    while((r-l)>1e-6){
        ch=0;
        mid=(l+r+(1e-6))/2;
        for(int i=1;i<=n;i++){
            qs[i]=a[i]-mid+qs[i-1];
            mi[i]=min(qs[i],mi[i-1]);
            if(i>=k && qs[i]-mi[i-k]>=0){
                ch=1;
                break;
            }
        }
        if(ch) l=mid;
        else r=mid-(1e-6);
    }
    printf("%.1lf\n",r);
    return 0;
}