/*
    TASK:AP_MagicHat
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int w,v,ti,co;
    bool operator < (const A&o) const{
        return w>o.w;
    }

};
priority_queue< A > h;
vector< A > a[1000100];
int mark[200100];
int main(){
    int n,m,what,ty,ti,w,v,nw,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+m;i++){
        for(j=0;j<a[i].size();j++){
            h.push(a[i][j]);
        }
        scanf("%d",&what);
        if(what==1){
            scanf("%d",&ty);
            if(ty==1){
                scanf("%d %d",&w,&v);
                h.push({w,v,n+m+1,i});
            }else
            if(ty==2){
                scanf("%d %d %d",&w,&v,&ti);
                h.push({w,v,ti,i});
            }else
            if(ty==3){
                scanf("%d %d %d %d",&w,&v,&ti,&nw);
                h.push({w,v,ti,i});
                a[ti].push_back({nw,v,n+m+1,i});
            }
        }
        if(what==2){
            int ch=0,ww,vv,tt,ii;
            while(!h.empty()){
                tt=h.top().ti;
                ii=h.top().co;
                ww=h.top().w;
                vv=h.top().v;
                h.pop();
                if(tt<=i){continue;}
                if(mark[ii])continue;
                mark[ii]=1;
                printf("%d\n",vv);
                ch=1;
                break;
            }
            if(ch==0){
                printf("0\n");
            }
        }
    }
    return 0;
}
/*
5 4
1 1 10 20
1 2 30 10 3
2
2
1 3 40 20 7 5
1 1 30 30
1 2 25 50 7
2
2
*/
