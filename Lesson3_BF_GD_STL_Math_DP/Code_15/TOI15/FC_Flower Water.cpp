/*
    TASK:FC_Flower Water
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,i;
    bool operator<(const A&o)const{
    return u<o.u;
    }
};
int p[100010];
int fin(int i){
    if(p[i]==i)return i;
    else return p[i]=fin(p[i]);
}
A x[100010],y[100010];
int mark[100010];
int main(){
    int q,n,a,b,i,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&x[i].u,&y[i].u);
            x[i].i=y[i].i=i;
        }
        for(i=1;i<=n;i++)p[i]=i;
        sort(x+1,x+1+n);
        sort(y+1,y+1+n);
        for(i=2;i<=n;i++){
            if(x[i-1].u==x[i].u){
                p[fin(x[i].i)]=fin(x[i-1].i);
            }
        }
        for(i=2;i<=n;i++){
            if(fin(y[i].i)==fin(y[i-1].i))continue;
            if(y[i-1].u==y[i].u){
                p[fin(y[i].i)]=fin(y[i-1].i);
            }
        }
        ans=0;
        for(i=1;i<=n;i++){
            if(!mark[fin(p[i])]){
                mark[fin(p[i])]=1;
                ans++;
            }
        }
        //printf("%d\n",ans);
        if(ans%2){
            ans/=2;
            ans++;
        }else ans/=2;
        printf("%d\n",ans);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
//sort x dsu sort y dsu /2 floor func
