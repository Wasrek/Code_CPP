/*
    TASK:FC_Salary
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,h;
};
struct B{
    long long s,e;
};
A a[500100];
B t[1000010];
vector<long long> g[500100];
long long cou=0,fw[1000010];
void dfs(long long i){
    t[i].s=++cou;
    for(auto x:g[i]){
        dfs(x);
    }
    t[i].e=++cou;
}
int main(){
    long long n,m,i,j,q,x,qs;
    char w;
    scanf("%lld %lld",&n,&m);
    scanf("%lld",&a[1].w);
    for(i=2;i<=n;i++){
        scanf("%lld %lld",&a[i].w,&a[i].h);
        g[a[i].h].push_back(i);
    }
    dfs(1);
    /*
    for(i=1;i<=n;i++){
        printf("%d %d\n",t[i].s,t[i].e);
    }*/
    while(m--){
        scanf(" %c",&w);
        if(w=='p'){
            scanf("%lld %lld",&q,&x);
             //printf("c");
            for(i=t[q].s+1;i<=2*n;i+=(i&-i))fw[i]+=x;
            for(i=t[q].e;i<=2*n;i+=(i&-i))fw[i]-=x;
        }else
        if(w=='u'){
            scanf("%lld",&q);
            qs=0;
            //printf("c");
            for(i=t[q].e;i>0;i-=(i&-i))qs+=fw[i];
            printf("%lld\n",qs+a[q].w);
             //printf("c");
        }
    }
    return 0;
}
/*
5 5
4
2 1
6 1
7 1
3 4
u 3
p 1-1
u 3
p 4 5
u 5
*/
