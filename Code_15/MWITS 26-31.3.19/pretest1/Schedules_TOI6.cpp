/*
    TASK:Schedules_TOI6
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,idx;
    bool operator<(const A&o) const{
    if(i!=o.i)return i>o.i;
    return j>o.j;
    }
};
struct B{
    int i;
    bool operator<(const B&o) const{
    if(i!=o.i)return i>o.i;
    }
};
priority_queue<A> h;
priority_queue<B> hh;
int dp,mark[500100];
int main(){
     int n,k,q,i,j,ii,jj,idx,last=0;
     scanf("%d %d %d",&n,&k,&q);
     for(i=1;i<=n;i++){
        scanf("%d %d",&ii,&jj);
        h.push({ii,jj,i});
     }
     while(!h.empty()){
        ii=h.top().i;
        jj=h.top().j;
        idx=h.top().idx;
        h.pop();
        while(!hh.empty() && hh.top().i<ii){
            hh.pop();
        }
        if(hh.size()<k)mark[idx]=1,hh.push({jj});
     }
     while(q--){
        scanf("%d",&i);
        if(mark[i])printf("Y ");
        else printf("N ");
     }
     return 0;
}
