/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,ma;
    bool operator<(const A & o) const{
        return ma<o.ma;
    }
};
vector< int > g[100010];
vector< A > gm[100010];
long long ma[100010],ans[100010],cnt=0,qs[100010];
void dfs(int i){
    ma[i]=i;
    for(auto x: g[i]){
        dfs(x);
        ma[i]=max(ma[i],ma[x]);
    }
    return ;
}
void gen(int i){
    for(auto x: gm[i]){
        gen(x.i);
    }
    ans[++cnt]=i;
}
int main()
{
    long long n,m,p,r,opr,now=0,k;
    long long summ=0;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p);
        g[p].push_back(i);
        if(p==0) r=i;
    }
    dfs(r);//gen each max
    for(int i=1;i<=n;i++){
        for(auto x: g[i]){
            gm[i].push_back({x,ma[x]});
        }
        sort(gm[i].begin(),gm[i].end());

    }
    gen(r);
    for(int i=1;i<=n;i++){
        qs[i]=qs[i-1]+ans[i];
        // printf("%lld ",ma[i]);
    }
    // printf("\n");
    // for(int i=1;i<=n;i++) printf("%d ",qs[i]);
    for(int i=1;i<=m;i++){
        scanf("%lld",&opr);
        if(opr==3){
            printf("%lld\n",qs[now]);
            continue;
        }
        scanf("%lld",&k);
        if(opr==1){
            now+=k;
            printf("%lld\n",ans[now]);
        }else{
            now-=k;
        }
    }
    return 0;
}
/*
7 5
7
7
5
0
4
4
4
1 3
1 1
3
1 3
3
*/