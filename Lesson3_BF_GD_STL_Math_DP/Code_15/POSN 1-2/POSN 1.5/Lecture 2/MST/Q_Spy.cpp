#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
int p[1100];
priority_queue<A > he;
int fin(int i){
   if(p[i]==i) return i;
   else return p[i]=fin(p[i]);
}
int main(){
    int n,i,j,num,x,y,z,rx,ry,ans = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&num);
            if(j<=i)    continue;
            he.push({i,j,num});
        }
    }
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        he.push({i,n+1,num});
    }
    for(i=1;i<=n+1;i++)
        p[i]=i;
    while(!he.empty()){
        x=he.top().u,y=he.top().v,z=he.top().w;
        he.pop();
        rx = fin(x),ry = fin(y);
        if(rx != ry){
            ans+=z;
            p[rx]=ry;
        }
    }
    printf("%d",ans);
    return 0;
}
