/*
    TASK:Chest Treasure
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,v2,v3,v5,v7;
    bool operator <(const A & o) const{
        return i<o.i;
    }
};
A e[400010];
int main()
{
    long long m,n,x,a,b,cnt,pl,v2,v3,v5,v7,cma,now,ma=1;
    scanf("%lld %lld",&m,&n);
    cma=n;
    cnt=0;
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&x,&a,&b);
        v2=v3=v5=v7=0;
        if(x%2==0){
            if(x!=4 && x!=8)v2=1;
            if(x==4) v2=2;
            if(x==8) v2=3;
        }
        if(x%3==0){
            if(x!=9) v3=1;
            else v3=2;
        }
        if(x%5==0) v5=1;
        if(x%7==0) v7=1;
        e[++cnt].i=a;
        e[cnt].v2=v2;
        e[cnt].v3=v3;
        e[cnt].v5=v5;
        e[cnt].v7=v7;
        e[++cnt].i=b+1;
        e[cnt].v2=-v2;
        e[cnt].v3=-v3;
        e[cnt].v5=-v5;
        e[cnt].v7=-v7;
    }
    sort(e+1,e+1+cnt);
    for(int i=1;i<=cnt;i++){
        e[i].v2+=e[i-1].v2;
        e[i].v3+=e[i-1].v3;
        e[i].v5+=e[i-1].v5;
        e[i].v7+=e[i-1].v7;
        if(e[i].i==e[i+1].i) continue;
        now=(e[i].v2+1)*(e[i].v3+1)*(e[i].v5+1)*(e[i].v7+1);
        if(now>ma){
            ma=now;
            cma=0;
        }
        if(now==ma){
            cma+=(e[i+1].i-e[i].i);
        }
    }
    printf("%lld %lld",ma,cma);
    return 0;
}