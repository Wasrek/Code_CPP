/*
    TASK:RC_Shuffle Machine
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110],mark[110];
long long gcd(long long a,long long b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
long long dfs(int i){
    if(mark[i])return 0;
    mark[i]=1;
    return dfs(a[i])+1;
}
int main(){
    long long n,m,x,y,i,cou,lcm=1;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)a[i]=i;
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&x,&y);
        swap(a[x],a[y]);
    }
    for(i=1;i<=n;i++){
        if(mark[i])continue;
        if(a[i]!=i){
            cou=dfs(i);
            //printf("%d\n",cou);
            lcm=(lcm*cou)/gcd(lcm,cou);
        }
    }
    printf("%lld\n",lcm);
   return 0;
}
