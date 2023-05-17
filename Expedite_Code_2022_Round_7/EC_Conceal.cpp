/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,cnt;
};
struct H{
    long long v,i;
    bool operator <(const H & o) const{
        return v>o.v;
    }
};
A a[500010];
int l[500010],r[500010],nc2[500010][3];
priority_queue< H > h;
int main()
{
    int n;
    long long now;
    long long ans=0;
    int la=1;
    nc2[1][1]=1;
    nc2[2][2]=1;
    nc2[2][1]=2;
    for(int i=3;i<=500000;i++){
        nc2[i][1]=i;
        nc2[i][2]=nc2[i-1][2]+nc2[i-1][1];
    }
    // for(int i=1;i<=5;i++) printf("%d ",nc2[i][2]);
    // printf("\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&now);
        if(i==1){
            a[la]={now,1};
        }else{
            if(now==a[la].v) a[la].cnt++;
            else{
                la++;
                a[la]={now,1};
            }
        }
    }
    for(int i=1;i<=la;i++){
        // printf("%d %d\n",a[i].v,a[i].cnt);
        h.push({a[i].v,i});
        if(a[i].cnt>1) ans+=nc2[a[i].cnt][2];
        l[i]=i-1;
        r[i]=i+1;
    }
    H tp;
    while(!h.empty()){
        tp=h.top();
        h.pop();
        if(r[tp.i]<=la){
            if(tp.v != a[r[tp.i]].v) ans+=a[tp.i].cnt;
            else ans+=(a[tp.i].cnt*a[r[tp.i]].cnt);
        }
        if(l[tp.i]>0){
            if(tp.v != a[l[tp.i]].v) ans+=a[tp.i].cnt;
            else ans+=(a[tp.i].cnt*a[l[tp.i]].cnt);
        }
        // printf("%d %d %d %d\n",tp.v,tp.i,a[tp.i].cnt,ans);
        // if(r[tp.i]<=n && l[tp.i]>0) ans+=(a[l[tp.i]].cnt * a[r[tp.i]].cnt);
        r[l[tp.i]]=r[tp.i];
        l[r[tp.i]]=l[tp.i]; 
    }
    printf("%lld\n",ans);
    return 0;
}