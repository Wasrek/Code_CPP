/*
    TASK:Bomb
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
    bool operator<(const A & o) const{
        if(i!=o.i) return i<o.i;
        return j<o.j;
    }
};
A ans[1000100];
struct B{
    int i,j;
    bool operator<(const B & o) const{
        if(i!=o.i) return i<o.i;
        return j>o.j;
    }
};
priority_queue< B > h;
int main()
{
    int n,ma=0,x,y,k=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        h.push({x,y});
    }
    while(!h.empty()){
        if(ma<=h.top().j){
            ans[++k].i=h.top().i;
            ans[k].j=h.top().j;
        }
        ma=max(ma,h.top().j);
        h.pop();
    }
    sort(ans+1,ans+1+k);
    for(int i=1;i<=k;i++){
        printf("%d %d\n",ans[i].i,ans[i].j);
    }
    return 0;
}