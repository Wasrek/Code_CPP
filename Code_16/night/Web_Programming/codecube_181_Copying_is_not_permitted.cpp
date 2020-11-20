/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A & o) const{
        return w<o.w;
    }
};
struct B{
    int u,v;
};
vector< A > vm;
vector< B > g;
int p[40100];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main()
{
    int n,m,k,u,v,w,a,b,pa,pb,ch=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        vm.push_back({u,v,w});
    }
    sort(vm.begin(),vm.end());
    for(int j=1;j<=k;j++){
        scanf("%d %d",&a,&b);   
        g.push_back({a,b});
    }
    long long l=0,r=2e9,mid;
    while(l<r){
        mid=(l+r+1)/2;
        // printf("%d %d\n",l,r);
        for(int i=1;i<=n;i++) p[i]=i;
        for(auto x: vm){
            if(x.w>=mid) break;
            p[fin(x.u)]=fin(x.v);
        }
        ch=0;
        for(auto x: g){
            if(fin(x.u)==fin(x.v)){
                ch=1;
                break;
            }
        }
        // printf("%d %d %d\n",l,r,mid);
        if(ch){
            r=mid-1;
        }else{
            l=mid;
        }
    }
    // printf("%d %d\n",l,r);
    if(l==2e9) printf("-1\n");
    else printf("%d\n",l);
    return 0;
}