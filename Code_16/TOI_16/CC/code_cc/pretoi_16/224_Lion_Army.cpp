/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int color[600010],mod=1000000007,c1,c2;
vector< int > g[600010];
int st(int a){
    if(a==1) return 2;
    int go=a/2;
    int next=st(go);
    next%=mod;
    if(a%2){
        return (next*((next*2)%mod))%mod;
    }else {
        return (next*next)%mod;
    }
}
int bipar(int i,int col){
    if((color[i]==c1 || color[i]==c2) && color[i]!=col) return 0;
    if((color[i]==c1 || color[i]==c2) && color[i]==col) return 1;
    color[i]=col;
    int nextcol;
    if(col==c1)nextcol=c2;
    else nextcol=c1;
    // printf("%d %d\n",i,col);
    for(auto x: g[i]){
        if(!bipar(x,nextcol)){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m,t,a,b,now,ch,chh;
    scanf("%d %d",&n,&m);
    now=n;
    int cnt=st(n);
    // printf("%d\n",cnt);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&t,&a,&b);
        if(!cnt){
            printf("0\n");
            continue;
        }
        if(color[a]!=0 && color[a]/2==color[b]/2)ch=0;
        else ch=1;
        c1=i*2;
        c2=i*2+1;
        if(t){
            now++;
            // printf("%d\n",now);
            g[a].push_back(now);
            g[b].push_back(now);
            g[now].push_back(a);
            g[now].push_back(b);
        }else{
            g[a].push_back(b);
            g[b].push_back(a);
        }
        chh=bipar(a,c1);
        if(!chh) cnt=0;
        // printf("%d\n",chh);
        // for(int j=1;j<=now;j++){
        //     printf("%d ",color[j]);
        // }
        // printf("\n");
        cnt/=(1<<ch);
        printf("%d\n",cnt);
    }
    
    return 0;
}