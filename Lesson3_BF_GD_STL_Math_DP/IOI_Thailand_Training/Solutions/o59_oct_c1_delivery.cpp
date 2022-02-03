/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int k;
int g[20][20];
unordered_map<int,int> mp,re;
int dist(int a,int b){
    if(a>(1<<k)){
        a-=(1<<k);
        b-=(1<<k);
    }
    int cou=0;
    while(a!=b){
        if(a<b) b/=2;
        else a/=2;
        cou++;
    }
    return cou;
}
int find(int a,int b){
    int now=1e9;
    if(mp[a] && mp[b]) now=g[mp[a]][mp[b]];
    if(min(a,b)<(1<<k) && max(a,b)>(1<<k)) return min(now,(int)1e9);
    return min(now,dist(a,b));
}
int main()
{
    int l,q,a,b,cnt=0;
    scanf("%d %d %d",&k,&l,&q);
    for(int i=1;i<=l*2;i++){
        for(int j=1;j<=l*2;j++){
            g[i][j]=2e9;
        }
        g[i][i]=0;
    }
    for(int i=1;i<=l;i++){
        scanf("%d %d",&a,&b);
        if(!mp[a]) mp[a]=++cnt,re[cnt]=a;
        if(!mp[b]) mp[b]=++cnt,re[cnt]=b;
        g[mp[a]][mp[b]]=g[mp[b]][mp[a]]=1;
    }
    for(int k=1;k<=cnt;k++){
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=cnt;j++){
                g[i][j]=min(g[i][j],find(re[i],re[k])+find(re[k],re[j]));
            }
        }
    }
    int ans,ii,jj;
    while(q--){
        scanf("%d %d",&a,&b);
        ans=find(a,b);
        for(int i=1;i<=cnt;i++){
            for(int j=1;j<=cnt;j++){
                ii=re[i];jj=re[j];
                if((min(a,ii)<(1<<k) && max(a,ii)>(1<<k)) || (min(b,jj)<(1<<k) && max(b,jj)>(1<<k))) continue;
                ans=min(ans,find(a,ii)+find(jj,b)+g[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}