/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,i;
    bool operator < (const A & o){
        if(r!=o.r) return r<o.r;
        else return l<o.l;
    }
};
int a[200010],mark[200010],ans[200010];
vector< A > qu[510];
int main()
{
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,p,s,sq,ll,rr,sum,l,r,ma=0;
    scanf("%d %d %d",&n,&p,&m);
    for(int i=1;i<=n;i++){
        scanf(" %d",&a[i]);
    }
    sq=(int)(sqrt((double)(n)));
    for(int i=1;i<=m;i++){
        scanf(" %d %d",&l,&r);
        s=l/sq;
        ma=max(ma,s);
        qu[s].push_back({l,r,i});
        // printf("%d\n",s);
    }
    // printf("%d\n",ma);
    for(int i=0;i<=ma;i++){
        // printf("%d %d\n",i,qu[i].size());
        if(qu[i].size()==0)continue;
        sort(qu[i].begin(),qu[i].end());
        sum=0;
        ll=qu[i][0].l;
        rr=qu[i][0].l-1;
        // printf("first one of the set %d\n",ans[qu[i][0].i]);
        for(auto x: qu[i]){
            // printf("%d\n",x);
            if(ll<x.l){
                // printf("ll<l\n");
                for(int j=ll;j<x.l;j++){
                    mark[a[j]]--;
                    if(!mark[a[j]] && a[j]<=p){
                        sum--;
                    }
                }
            }
            if(ll>x.l){
                for(int j=ll-1;j>=x.l;j--){
                    if(!mark[a[j]]){
                        if(a[j]<=p)sum++;
                    }
                    mark[a[j]]++;
                }
            }
            if(rr<x.r){
                for(int j=rr+1;j<=x.r;j++){
                    if(!mark[a[j]]){
                        if(a[j]<=p)sum++;
                    }
                    mark[a[j]]++;
                }
            }
            if(sum==p) ans[x.i]=1;
            else ans[x.i]=0;
            // printf("%d\n",x.i);
            // for(int i=1;i<=p;i++){
            //     printf("%d ",i);
            // }
            // printf("\n");
            // for(int i=1;i<=p;i++){
            //     printf("%d ",mark[i]);
            // }
            // printf("\n");
            ll=x.l;
            rr=x.r;
        }
        // printf("here\n");
        memset(mark,0,sizeof mark);
    }
    // printf("here\n");
    for(int i=1;i<=m;i++){
        if(ans[i])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}