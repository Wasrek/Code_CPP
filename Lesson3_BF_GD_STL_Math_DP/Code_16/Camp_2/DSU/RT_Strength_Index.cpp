/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
struct B{
    int w,i,j;
    bool operator< (const B & o) const{
        return w>o.w;
    }
};
priority_queue< B > h;
A a[1010];
int p[1010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int q,n,k,w,cnt,tu,tv,tw,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        cnt=n;ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
            p[i]=i;
            for(int j=1;j<i;j++){
                w=abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
                h.push({w,i,j});
            }
        }
        while(!h.empty()){
            tu=h.top().i;
            tv=h.top().j;
            tw=h.top().w;
            h.pop();
            tu=fin(tu);
            tv=fin(tv);
            if(tu==tv){
                continue;
            }
            if(cnt==k){
                while(!h.empty())h.pop();
                ans=tw;
                break;
            }
            p[tu]=tv;
            cnt--;
        }
        printf("%d\n",ans);
    }
    return 0;
}