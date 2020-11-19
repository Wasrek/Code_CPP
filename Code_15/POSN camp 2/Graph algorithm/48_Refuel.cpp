/*
    TASK:48_Refuel
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,c,h;
    bool operator<(const A&o) const{
    if(c!=o.c)return c>o.c;
    }
};
struct B{
    int v,di;
};
vector< B > g[1100];
int c[1100],ma[1100][120];
priority_queue< A > h;
int main(){
    int t,n,m,i,u,v,d,st,en,si,nv,nc,nh,ch,k;
    scanf("%d",&t);
    while(t--){
        memset(ma,127,sizeof ma);
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            scanf("%d",&c[i]);
        }
        while(m--){
            scanf("%d %d %d",&u,&v,&d);
            g[u].push_back({v,d});
            g[v].push_back({u,d});
        }
        scanf("%d %d %d",&si,&st,&en);
        h.push({st,0,0});
        ch=0;
        while(!h.empty()){
            nv=h.top().v,nc=h.top().c,nh=h.top().h;
            h.pop();
            if(ma[nv][nh]<nc)continue;
            ma[nv][nh]=nc;
            //printf("0");
            if(nv==en){
                printf("%d\n",nc);ch=1;
                break;
            }
            k=nh;
            if(k<si){
                if(ma[nv][nh+1]<nc+c[nv])continue;
                h.push({nv,nc+c[nv],nh+1});
            }
            for(i=0;i<g[nv].size();i++){
                if(nh>=g[nv][i].di){
                    if(ma[g[nv][i].v][nh-g[nv][i].di]<nc){continue;}
                    h.push({g[nv][i].v,nc,nh-g[nv][i].di});
                }
            }

        }
        //printf("0");
        while(!h.empty())h.pop();
        for(i=0;i<n;i++)g[i].clear();
        if(ch==0)printf("-99\n");
    }
}
/*
2
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
10 0 3
5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
20 1 4
*/
