/*
    TASK:restaurant
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,v;
    bool operator<(const A&o) const {
        return v>o.v;
    }
};
int dg[310],a[310][310],p[310];
int fin(int i){
    if(p[i]==i) return i;
    return p[i] = fin(p[i]);
}
vector<int> g[310];
priority_queue< A > h;
int main()
{
    int n,t;
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++){
        p[i]=i;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(j<i)h.push({i,j,a[i][j]});
        }
    }
    int cnt=0,i,j,k=n-1;
    while(!h.empty() && cnt<k){
        i=h.top().i;
        j=h.top().j;
        h.pop();
        if(fin(i)==fin(j))continue;
        p[fin(i)]=fin(j);
        dg[i]++;
        dg[j]++;
        g[i].push_back(j);
        g[j].push_back(i);
        cnt++;
        // printf("%d %d %d\n",i,j,a[i][j]);
    }
    for(int i=1;i<=n;i++){
        if(dg[i]>2){
            printf("%d\n",i);
            if(t==2){
                printf("%d\n",g[i].size());
            }
            return 0;
        }
    }
    return 0;
}