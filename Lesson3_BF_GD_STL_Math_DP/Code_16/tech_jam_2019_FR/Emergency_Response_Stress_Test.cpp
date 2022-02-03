/*
    TASK:Emergency Response Stress Test
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,t,i;
    bool operator <(const A & o) const{
        return n<o.n;
    }
};
vector< A > v;
vector< int > g;
int p[200010],c[200010],t[200010];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        g.push_back(p[i]);
    }
    sort(p+1,p+1+n);
    sort(g.begin(),g.end());
    for(int i=1;i<=m;i++){
        scanf("%d %d",&c[i],&t[i]);
        v.push_back({c[i],t[i],i});
    }
    sort(v.begin(),v.end());
    int r,l,rr,ll,le,ri,cnt=0;
    for(int i=0;i<v.size();i++){
        l=0;
        r=g.size()-1;
        ri=v[i].n+v[i].t;
        le=v[i].n-v[i].t;
        // printf("%d\n",i);
        while(l<r){
            int mid=(l+r)/2;
            if(g[mid]>=le){
                r=mid;
            }else l=mid+1;
        }
        if(g[l]>=le && g[l]<=ri){
        cnt++;
        g.erase(g.begin()+l);
        }
        // printf("%d\n",cnt);
    }
    printf("%d\n",cnt);
    return 0;
}