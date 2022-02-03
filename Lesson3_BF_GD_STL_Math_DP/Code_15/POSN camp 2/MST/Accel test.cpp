/*
    TASK:Accel test
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator <(const A&o) const{
        return w<o.w;
    }
};
A edge[300100];
typedef pair<int,int> PII;
int p[100100];
PII x[100100],y[100100],z[100100];
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,i,ans=0,cnt=0,u,v;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&x[i].first,&y[i].first,&z[i].first);
        x[i].second=y[i].second=z[i].second=i,p[i]=i;
    }
    sort(x+1,x+n+1),sort(y+1,y+n+1),sort(z+1,z+n+1);
    for(i=1;i<n;i++){
        edge[cnt++]={x[i].second,x[i+1].second,abs(x[i].first-x[i+1].first)};
        edge[cnt++]={y[i].second,y[i+1].second,abs(y[i].first-y[i+1].first)};
        edge[cnt++]={z[i].second,z[i+1].second,abs(z[i].first-z[i+1].first)};
    }
    sort(edge,edge+cnt);
    for(i=0;i<cnt;i++){
        u = fin(edge[i].u),v = fin(edge[i].v);
        if(u!=v){
            ans+=edge[i].w;
            p[u]=v;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
3
-3 -3 -3
1 5 10
7 8 2
*/
