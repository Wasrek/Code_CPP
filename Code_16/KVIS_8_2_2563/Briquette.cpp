/*
    TASK:Briquette
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int l[10010],ch[10010],p[10010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,k,last;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        p[i]=i;
    }
    int ans=0,la,now;
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        if(k==0){ans++;continue;} 
        scanf("%d",&la);
        ch[la]=1;
        for(int i=2;i<=k;i++){
            scanf("%d",&now);
            la=fin(la);
            now=fin(now);
            p[la]=now;
            ch[now]=1;
        }
    }
    for(int i=1;i<=m;i++){
        if(ch[fin(i)]==1){
            ans++;
            ch[fin(i)]=0;
        }
    }
    printf("%d\n",ans-1);
    return 0;
}