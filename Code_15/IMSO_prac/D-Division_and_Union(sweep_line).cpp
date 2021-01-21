/*
    TASK:D-Division_and_Union
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,po;
    bool operator <(const A&o)const{
        if(l!=o.l)return l<o.l;
        else return r<o.r;
    }
};
A a[200010];
int ans[200010];
int main()
{
    int q,n,i,last,ch,cch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].l,&a[i].r);
            a[i].po=i;
        }
        sort(a+1,a+1+n);
        last=a[1].r,ch=1,ans[a[1].po]=ch;cch=1;
        for(i=2;i<=n;i++){
            if(a[i].l<=last)last=max(last,a[i].r),ans[a[i].po]=ch;
            else ch=3-ch,ans[a[i].po]=ch,last=a[i].r,cch=0;
        }
        if(cch)printf("-1");
        else
        for(i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
