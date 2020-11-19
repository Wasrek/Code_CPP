/*
    TASK:Teap's nitrous
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct H{
    int n,j,t;
    bool operator <(const H & o) const{
        if(t!=o.t)return t>o.t;
        return n>o.n;
    }
};
struct V{
    int j,t;
};
priority_queue<H> h;
vector< V > v[100100];
int mark[110][5100];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int i,x,y,t,ni;
    while(m--)
    {
        scanf("%d %d %d",&x,&y,&t);
        v[x].push_back({y,t});
        v[y].push_back({x,t});
    }
    memset(mark,127,sizeof mark);
    int r=k;
    h.push({r,1,0});
    mark[r][1]=0;
    int j,tt,Min=1e9;
    while(!h.empty()){
        ni=h.top().n;
        j=h.top().j;
        tt=h.top().t;
        h.pop();
        if(mark[ni][j]!=tt)continue;
        if(j==n){
            if(ni==k) {printf("%d\n%d\n%d\n",mark[k][n],Min,mark[k][n]-Min);return 0;}
            else Min=min(Min,tt);
        }
        for(i=0;i<v[j].size();i++){
            if(ni>0&&mark[ni-1][v[j][i].j]>tt+(v[j][i].t/2))
                h.push({ni-1,v[j][i].j,tt+(v[j][i].t/2)}),mark[ni-1][v[j][i].j]=tt+(v[j][i].t/2);
            if(mark[ni][v[j][i].j]>tt+v[j][i].t)
                h.push({ni,v[j][i].j,tt+v[j][i].t}),mark[ni][v[j][i].j]=tt+v[j][i].t;
        }
    }
}
/*
6 8 1
1 2 4
1 4 2
2 3 4
2 4 6
3 6 6
4 3 12
4 5 10
5 6 4
*/
