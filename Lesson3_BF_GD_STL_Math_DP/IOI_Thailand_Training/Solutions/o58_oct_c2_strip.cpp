/*
    TASK: o58_oct_c2_strip
    LANG: CPP
    AUTHOR: WasreK
    ALGO: fenwick
    TYPE: BATCH
    SCORE: 100
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int ty,i,b,d,x;
    bool operator <(const A & o) const{
        if(i!=o.i) return i>o.i;
        return ty>o.ty;
    }
} now;
priority_queue< A > h;
int fw[100100],ans[10100];
void upd(int u,int v){
    for(int i=u;i<100010;i+=(i&-i)){
        fw[i]+=v;
    }
}
int qy(int u){
    int v=0;
    for(int i=u;i>0;i-=(i&-i)){
        v+=fw[i];
    }
    return v;
}
int main()
{
    int n,m,k,a,b,c,d;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a++,b++,c++,d++;
        h.push({1,a,b,d,1});
        h.push({1,c+1,b,d,-1});
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        a++,b++;
        h.push({2,a,b,0,i});
    }
    while(!h.empty()){
        now=h.top(); h.pop();
        // printf("%d %d %d %d %d\n",now.ty,now.i,now.b,now.d,now.x);
        if(now.ty==1){
            upd(now.b,now.x);
            upd(now.d+1,now.x*(-1));
        }else{
            ans[now.x]=qy(now.b);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}