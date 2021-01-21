/*
    TASK:Milk_Scheduling
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,v;
};
int t[10100],in[10100],out[10100],maa[10100];
vector< int > g[10010];
queue< A > q;
int main()
{
    freopen("msched.in","r",stdin);
    freopen("msched.out","w",stdout);
    int n,m,a,b,ma=0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        in[b]++;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push({i,t[i]});
            ma=max(ma,t[i]);
        }
    }
    int tn,tv;
    while(!q.empty()){
        tn=q.front().n;
        tv=q.front().v;
        q.pop();
        for(auto x: g[tn]){
            in[x]--;
            maa[x]=max(maa[x],tv);
            ma=max(ma,t[x]+maa[x]);
            if(in[x]==0){
                q.push({x,t[x]+maa[x]});
            }
        }
    }
    printf("%d\n",ma);
    return 0;
}
