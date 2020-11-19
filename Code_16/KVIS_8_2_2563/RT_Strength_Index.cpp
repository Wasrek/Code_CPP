/*
    TASK:RT_Strength_Index
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
};
struct B{
    int dis,a,b;
    bool operator < (const B&o) const{
        return dis>o.dis;
    }
};
A a[1010];
priority_queue< B >h;
int p[1010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int q,n,m,now,all,pa,pb,ans;
    scanf("%d",&q);
    while(q--) {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].a,&a[i].b);
            p[i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                now=abs(a[i].a-a[j].a)+abs(a[i].b-a[j].b);
                h.push({now,i,j});
            }
        }
        all=n;
        ans=0;
        while(!h.empty()){
            pa=fin(h.top().a);
            pb=fin(h.top().b);
            now=h.top().dis;
            h.pop();
            if(pa==pb) continue;
            // printf("%d\n",now);
            if(all==m){
                printf("%d\n",now);
                break;
            }
            all--;
            p[pa]=pb;
        }
        while(!h.empty()){
            h.pop();
        }
    }   
    return 0;
}