/*
    TASK:RT_Bomb Disposal
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[20],mark[20][20][1<<16];
struct A{
    int b,n,w,bm,cbm;
};
deque<A> dq;
int main(){
    int q,n,p,i,fb,fn,fw,fbm,fc;
    scanf("%d",&q);
    while(q--){
        memset(mark,127,sizeof mark);
        scanf("%d %d",&n,&p);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]!=1){
            dq.push_back({0,i,0,0,0});
            mark[0][i][0]=0;
            }else{
            dq.push_back({1,i,0,0,0});
            mark[1][i][0]=0;
            }
        }
        while(!dq.empty()){
            fb=dq.front().b;
            fn=dq.front().n;
            fw=dq.front().w;
            fbm=dq.front().bm;
            fc=dq.front().cbm;
            dq.pop_front();
            if(fb==n){
                printf("%d\n",fw);
                break;
            }
            if(fbm&(1<<(fb+1))){
                if(fw<mark[fb+1][fn][fbm]){
                mark[fb+1][fn][fbm]=fw;
                dq.push_front({fb+1,fn,fw,fbm,fc-1});
                }
            }
            if(fc<p && ((1<<a[fn])&fbm)==0){
                if(fw<mark[fb][fn][fbm|(1<<a[fn])]){
                mark[fb][fn][fbm|(1<<a[fn])]=fw;
                dq.push_front({fb,fn,fw,fbm|(1<<a[fn]),fc+1});
                }
            }
            if(fn+1<=n){
            if(a[fn+1] == fb+1){
                if(fw+1<mark[fb+1][fn+1][fbm]){
                mark[fb+1][fn+1][fbm]=fw+1;
                dq.push_back({fb+1,fn+1,fw+1,fbm,fc});
                }
            }
            if(fw+1<mark[fb][fn+1][fbm]){
                mark[fb][fn+1][fbm]=fw+1;
                dq.push_back({fb,fn+1,fw+1,fbm,fc});
            }
            }
            if(fn-1>=1){
            if(fw+1<mark[fb][fn-1][fbm]){
                mark[fb][fn-1][fbm]=fw+1;
                dq.push_back({fb,fn-1,fw+1,fbm,fc});
            }
            if(a[fn-1] == fb+1){
                if(fw+1<mark[fb+1][fn-1][fbm]){
                mark[fb+1][fn-1][fbm]=fw+1;
                dq.push_back({fb+1,fn-1,fw+1,fbm,fc});
                }
            }
            }
        }
        while(!dq.empty())dq.pop_back();
    }
}
