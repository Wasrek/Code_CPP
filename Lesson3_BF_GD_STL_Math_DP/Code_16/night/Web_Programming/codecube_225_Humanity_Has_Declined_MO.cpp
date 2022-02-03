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
    bool operator<(const A & o) const{
        if(r!=o.r) return r<o.r;
        return l<o.l;
    }
};
vector< A > g[500];
int a[200100],cnt[200100],ans[200100];
int main()
{
    int n,w,q,l,r,now,ma=0,sq=ceil(sqrt(200100.00));
    scanf("%d %d %d",&n,&w,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        g[l/sq].push_back({l,r,i});
        ma=max(ma,l/sq);
        // printf("- %d\n",l/450);
    }
    for(int i=0;i<=ma;i++){
        sort(g[i].begin(),g[i].end());
        // printf("- %d\n",i);
        now=0;
        l=g[i][0].l;
        r=g[i][0].r;
        // printf("+ %d %d\n",l,r);
        for(int j=l;j<=r;j++){
            if(!cnt[a[j]] && a[j]<=w){
                now++;
            }
            cnt[a[j]]++;
        }
        if(now==w){
            ans[g[i][0].i]=1;
        }else ans[g[i][0].i]=0;
        // printf("%d %d %d\n",g[i][0].l,g[i][0].r,g[i][0].i);
        // for(int k=1;k<=w;k++) printf("%d ",cnt[k]);
        // printf("\n");
        // printf("%d\n",now);
        for(int j=1;j<g[i].size();j++){
            while(r<g[i][j].r){
                r++;
                if(!cnt[a[r]] && a[r]<=w) now++;
                cnt[a[r]]++;
            }
            while(l<g[i][j].l){
                if(cnt[a[l]]==1 && a[l]<=w) now--;
                cnt[a[l]]--;
                l++;
            }
            while(l>g[i][j].l){
                l--;
                if(!cnt[a[l]] && a[l]<=w) now++;
                cnt[a[l]]++;
            }
            if(now==w){
                ans[g[i][j].i]=1;
            }else ans[g[i][j].i]=0;
            // printf("%d %d %d\n",g[i][j].l,g[i][j].r,g[i][j].i);
            // for(int k=1;k<=w;k++) printf("%d ",cnt[k]);
            // printf("\n");
            // printf("%d\n",now);
        }
        memset(cnt,0,sizeof cnt);
    }
    for(int i=1;i<=q;i++){
        if(ans[i]){
            printf("YES\n");
        }else printf("NO\n");
    }
    return 0;
}

//ถ้าไม่ทำ MO เจน array ว่าช่องที่ i ต้องไปทางขวากี่ตัวถึงจะครบชี้ two pointers เอา แล้ววนตอบแบบ online