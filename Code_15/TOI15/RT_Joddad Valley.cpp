/*
    TASK:RT_Joddad Valley
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long s;
    double v,w;
    bool operator <(const A &o)const {
        return w>o.w;
    }
};
double dis[250][250],mark[250];
char ss[10];
priority_queue<A>h;
int main(){
    long long n,m,q,a,b,i,j,k,s,t,ts,ch;
    double w,v,c,tv,tw;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            dis[i][j]=dis[j][i]=(double)LONG_LONG_MAX;
        }
    }
    while(m--){
        scanf("%lld %lld %lf",&a,&b,&w);
        dis[a][b]=dis[b][a]=min(w,dis[a][b]);
    }
    while(q--){
        scanf(" %s",ss);
        if(ss[0]=='a'){
            scanf("%lld %lld",&a,&k);
            while(k--){
                scanf("%lld %lf",&b,&w);
                dis[a][b]=dis[b][a]=min(w,dis[a][b]);
            }
        }else
        if(ss[0]=='d'){
            scanf("%lld",&a);
            for(i=1;i<=n;i++){
                dis[a][i]=dis[i][a]=(double)LONG_LONG_MAX;
            }
        }else
        if(ss[0]=='t'){
            ch=1;
            scanf("%lld %lld %lf %lf",&s,&t,&v,&c);
            h.push({s,v,0});
            for(i=1;i<=n;i++){
                mark[i]=0;
            }
            while(!h.empty()){
                ts=h.top().s;
                tv=h.top().v;
                tw=h.top().w;
                h.pop();
                if(mark[ts])continue;
                mark[ts]=1;
                if(ts==t){
                    printf("%.2lf\n",tw);
                    ch=0;break;
                }
                if(tv<=0)continue;
                for(i=1;i<=n;i++){
                    if(dis[ts][i]==(double)LONG_LONG_MAX)continue;
                    if(mark[i]==0){
                        h.push({i,tv-(dis[ts][i]*c),tw+(dis[ts][i]/tv)});
                    }
                }
            }
            if(ch)printf("IMPOSSIBLE\n");
            while(!h.empty())h.pop();
        }
    }
}
