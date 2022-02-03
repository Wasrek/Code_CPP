/*
    TASK:COI Great Raid
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e,w;
    bool operator < (const A&o) const{
    if(w!=o.w){
        return w<o.w;
    }
    }
};
A a[1000100];
int w[100100],p[100100];
int fin(int i){
    if(p[i]==i)return i;
    else return p[i]=fin(p[i]);
}
int main(){
    int n,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&y);
        w[i]=y;
        p[i]=i;
    }
    int m,c;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a[i].s,&a[i].e);
        a[i].w=w[a[i].s]+w[a[i].e];
    }
    sort(a,a+m);
    int ans=0,ps,pe;
    for(int i=0;i<m;i++){
        ps=fin(a[i].s),pe=fin(a[i].e);
        if(ps!=pe){
            ans+=a[i].w;p[ps]=pe;
        }
    }
    printf("%d\n",ans);
}
