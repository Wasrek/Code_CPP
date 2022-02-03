/*
    TASK:N_Counting
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int fw[20100],bs[20100],n;
struct A{
    int v,i;
    bool operator <(const A & o) const{
        if(v!=o.v) return v<o.v;
        return i<o.i;
    }
};
A a[20100];
void upd(int b,int v){
    for(int i=b;i<=n;i+=(i&-i)){
        fw[i]+=v;
    }
}
int qu(int b){
    int sum=0;
    for(int i=b;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    return sum;
}
int main()
{
    int q,l,r,s,e,now;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].i=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        bs[i]=a[i].v;
    }
    while(q--){
        scanf("%d %d %d %d",&l,&r,&s,&e);
        now=lower_bound(bs+1,bs+1+n,s)-bs;
        // printf("%d\n",now);
        for(int i=now;bs[i]<=e && i<=n;i++){
            upd(a[i].i,1);
            // printf("here %d\n",a[i].i);
        }
        l=qu(l-1);
        r=qu(r);
        // printf("%d %d %d %d %d %d %d\n",l,r,qu(1),qu(2),qu(3),qu(4),qu(5));
        printf("%d\n",r-l);
        for(int i=now;bs[i]<=e && i<=n;i++){
            upd(a[i].i,-1);
        }
    }
    return 0;
}