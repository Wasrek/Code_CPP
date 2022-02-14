/*
    TASK: N-Counting
    LANG: CPP
    AUTHOR: WasreK
    ALGO: Fenwick
    TYPE: BATCH
    SCORE: 100
*/
#include<bits/stdc++.h>
using namespace std;
int n,ans[200100],arr[20100],fw[20100],mp[20100];
struct A{
    int i,a,b,q,ch;
    bool operator <(const A&o) const{
        return i>o.i;
    }
};
priority_queue< A > h;
int find_id(int u,int ty){
    if(ty==1){//lb
        return lower_bound(mp+1,mp+1+n,u)-mp;
    }else{//ub
        return upper_bound(mp+1,mp+1+n,u)-mp;
    }
}
void upd(int u){
    for(int i=u;i<=20000;i+=(i&-i)) fw[i]++;
    return ;
}
int qy(int u){
    int now=0;
    for(int i=u;i>0;i-=(i&-i)) now+=fw[i];
    return now;
}
int main()
{
    int q,a,b,s,e,l,r;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        mp[i]=arr[i];
    }
    sort(mp+1,mp+1+n);
    for(int i=1;i<=q;i++){
        scanf("%d %d %d %d",&a,&b,&s,&e);
        l=find_id(s,1);
        r=find_id(e,2)-1;
        h.push({b,l-1,r,i,1});
        h.push({a-1,l-1,r,i,-1});
    }
    for(int i=0;i<=n;i++){
        if(h.empty()) break;
        if(i>0) upd(find_id(arr[i],1));
        while(!h.empty() && h.top().i==i){
            ans[h.top().q]+=(qy(h.top().b)-qy(h.top().a))*h.top().ch;
            h.pop();
        }
    }
    for(int i=1;i<=q;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}