/*
    TASK:Cable Car TOI12
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator<(const A &o)const{
    if(w!=o.w)return w<o.w;
    }
};
int p[2600];
priority_queue< A >h;
int fin(int i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,m,i,u,v,w,s,d,pe,tu,tv;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        h.push({u,v,w});
    }
    for(i=1;i<=n;i++)p[i]=i;
    scanf("%d %d %d",&s,&d,&pe);
    while(!h.empty()){
        tu=h.top().u;
        tv=h.top().v;
        if(fin(tv)!=fin(tu)){
            p[fin(tv)]=tu;
        }
        if(fin(p[s])==fin(p[d])){
            w=h.top().w;
            w--;
            //printf("%d\n",w);
            if(pe%w==0){
                printf("%d\n",pe/w);
            }else{
                printf("%d\n",pe/w+1);
            }
            return 0;
        }
        h.pop();
    }
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/
