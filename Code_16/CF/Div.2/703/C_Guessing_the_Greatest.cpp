/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,r,ma,now,si;
    scanf("%d",&n);
    l=1,r=n;
    printf("? %d %d\n",l,r);
    fflush(stdout);
    scanf("%d",&ma);
    if(1!=ma){
        printf("? 1 %d\n",ma);
        fflush(stdout);
        scanf("%d",&now);
        if(now==ma) si=1,l=1,r=ma-1;
        else si=2,l=ma+1,r=n;
    }else{
        si=2,l=ma+1,r=n;
    }
    if(si==1){
        while(l<r){
            int mid=(l+r+1)/2;
            printf("? %d %d\n",mid,ma);
            fflush(stdout);
            scanf("%d",&now);
            if(now==ma){
                l=mid;
            }else r=mid-1;
        }
    }else{
        while(l<r){
            int mid=(l+r)/2;
            printf("? %d %d\n",ma,mid);
            fflush(stdout);
            scanf("%d",&now);
            if(now==ma){
                r=mid;
            }else l=mid+1;
        }
    }
    printf("! %d\n",l);
    return 0;
}
