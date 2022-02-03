/*
    TASK:RT_SingaAirport
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator<(const A&o) const{
        return w<o.w;
    }
};
int a[210][210],mark[210][210],ans[210][210];
priority_queue< A > h;
int main(){
    int n,m,s,i,j,ii,jj,ww,si,sj,ei,ej;
    scanf("%d %d %d",&n,&m,&s);
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            h.push({i,j,a[i][j]});
        }
    }
    while(!h.empty()){
        ii=h.top().i;
        jj=h.top().j;
        ww=h.top().w;
        h.pop();
        if(mark[ii][jj]==n){
            printf("%d\n",ans[ii][jj]);
            return 0;
        }
        si=max(ii-s+1,0);
        sj=max(jj-s+1,0);
        ei=min(ii+s-1,m);
        ej=min(jj+s-1,0);
        for(i=si;i<=ei;i++){
            for(j=sj;j<=ej;j++){
                mark[i][j]++;
                ans[i][j]+=ww;
                if(mark[i][j]==n){
                    printf("%d\n",ans[i][j]);
                    return 0;
                }
            }
        }
    }
}
