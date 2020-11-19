/*
    TASK:Salesman
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int d,l,p;
    bool operator<(const A & o) const{
        if(d!=o.d){
            return d<o.d;
        }else return l<o.l;
    }
};
int u,d;
A a[500100];
int dp[500100];
int dis(int f,int t){
    t=a[t].l;
    f=a[f].l;
    if(t-f>0){
        return u*(t-f);
    }
    return d*(f-t);
}
int main(){
    int n,s,i,j,now;
    scanf("%d %d %d %d",&n,&u,&d,&s);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].d,&a[i].l,&a[i].p);
        dp[i]=-1e9;
    }
    sort(a+1,a+1+n);
    a[0].d=a[n+1].d=0;
    a[0].l=a[n+1].l=s;
    a[0].p=a[n+1].p=0;
    n++;
    dp[0]=0;
    for(i=1;i<=n;i++){
        for(j=0;j<i;j++){
                now=a[i].p-dis(j,i)+dp[j];
                //printf("%d %d %d\n",now,i,j);
                dp[i]=max(dp[i],now);
        }
        //printf("%d\n",dp[n]);
    }
    printf("%d\n",dp[n]);
}