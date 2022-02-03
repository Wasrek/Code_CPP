/*
    TASK:AP_MagicHat
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int w,v,d,x;
    bool operator <(const A&o) const{
    return w>o.w;
    }
};
vector< A > a[1000100];
priority_queue< A > h;
int mark[200100];
int main(){
    int n,m,i,what,ty,w,v,d,x,j,ch,ww,vv,dd,xx;
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
            }else if(ty==2){
                scanf("%d %d %d",&w,&v,&d);
                h.push({w,v,d,i});
            }else if(ty==3){
                scanf("%d %d %d %d",&w,&v,&d,&x);
                h.push({w,v,d,i});
                a[d].push_back({x,v,n+m+1,i});
            }
        }else if(what==2){
            ch=0;
            while(!h.empty()){
                ww=h.top().w;
                vv=h.top().v;
                dd=h.top().d;
                xx=h.top().x;
                h.pop();
                if(dd<=i){continue;}
                if(mark[xx])continue;
                mark[xx]=1;
                printf("%d\n",vv);
                ch=1;
                break;
            }
            if(ch==0){
                printf("0\n");
            }
        }
    }
}
