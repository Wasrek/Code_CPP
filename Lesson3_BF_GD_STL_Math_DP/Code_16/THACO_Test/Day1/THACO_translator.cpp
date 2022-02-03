/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int p[100010],cnt[100010],g[100010],use[100010];
vector< int > cy;
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,now,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) p[i]=i,cnt[i]=1;
    g[1]=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&now);
        if(fin(i)!=fin(now)){
            g[cnt[p[fin(i)]]]--;
            g[cnt[p[fin(now)]]]--;
            cnt[p[fin(i)]]+=cnt[p[fin(now)]];
            g[cnt[p[fin(i)]]]++;
            cnt[p[fin(now)]]=0;
            p[fin(now)]=p[fin(i)];
        }
    }
    now=0;
    // for(int i=1;i<=n;i++){
    //     printf("%d %d\n",p[i],cnt[i]);
    // }
    for(int i=1;i<=n;i++){
        if(!g[i])continue;
        for(int j=1;j<i;j++){
            use[j]+=(((i-1)/j)*g[i]);
        }
    }
    // for(int i=1;i<=n;i++) printf("%d ",use[i]);
    int l=1,r=n,mid;
    while(q--){
        l=1,r=n;
        scanf("%d",&m);
        while(l<r){
            mid=(l+r)/2;
            // printf("%d\n",mid);
            if(use[mid]>m){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}