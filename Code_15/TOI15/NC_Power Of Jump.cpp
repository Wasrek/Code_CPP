/*
    TASK:NC_Power Of Jump
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 5050
#define mod 1000000007
struct A{
    int x,y;
    bool operator<(const A&o)const{
        if(x!=o.x)return x<o.x;
        return y>o.y;
    }
};
A tmp[N];
int val[N],pos[N],n;
long long dp[N][110];
void update(int a,int b,int c){
    int i;
    for(i=a;i<=n;i+=(i&-i)){
        dp[i][b]=(dp[i][b]+c)%mod;
    }
}
long long query(int a,int b){
    int i;
    long long ans=0;
    for(i=a;i>0;i-=(i&-i)){
        ans+=dp[i][b];
        ans%=mod;
    }
    return ans;
}
int main(){
    int q,i,k,j,l,a,b,c,d;
    long long cnt,ans;
    scanf("%d",&q);
    while(q--){
        memset(dp,0,sizeof dp);
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%d",&val[i]);
            tmp[i]={val[i],i};
        }
        sort(tmp+1,tmp+1+n);
        for(i=1;i<=n;i++){
            pos[tmp[i].y]=i;
        }
        update(pos[1],0,1);
        for(i=2;i<=n;i++){
            for(j=0;j<=k;j++){
                cnt=0;
                cnt = query(pos[i],j);
                if(j>0){
                    cnt=(cnt+query(n,j-1)-query(pos[i],j-1))%mod;
                }
                if(cnt<0)cnt+=mod;
                update(pos[i],j,cnt);
            }
        }
        ans=0;
        for(i=0;i<=k;i++){
            ans=(ans+query(pos[n],i)-query(pos[n]-1,i))%mod;
        }
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
