/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct B{
    int i,v;
    bool operator< (const B & o) const{
        return i<o.i;
    }
};
B cnt[200100];
int main()
{
    int n,m,a,b,ans=0;
    char ask;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        cnt[i*2+1]={a,1};
        cnt[i*2+2]={b+1,-1};
    }
    scanf(" %c",&ask);
    sort(cnt+1,cnt+1+2*m);
    cnt[2*m+1]={n+1,0};
    cnt[0]={1,0};
    for(int i=0;i<=m*2;i++){
        if(cnt[i].i!=0) cnt[i].v+=cnt[i-1].v;
        if(cnt[i].i==cnt[i+1].i) continue;
        if(ask=='R'){
            if(cnt[i].v%3==1) ans+=(2*(cnt[i+1].i-cnt[i].i));
            if(cnt[i].v%3==2) ans+=((cnt[i+1].i-cnt[i].i)); 
        }else if(ask=='G'){
            if(cnt[i].v%3==0) ans+=(cnt[i+1].i-cnt[i].i); 
            if(cnt[i].v%3==2) ans+=2*(cnt[i+1].i-cnt[i].i); 
        }else{
            if(cnt[i].v%3==1) ans+=(cnt[i+1].i-cnt[i].i);
            if(cnt[i].v%3==0) ans+=2*(cnt[i+1].i-cnt[i].i); 
        }
        // printf("%d %d %d\n",cnt[i].i,cnt[i].v,ans);
    }
    printf("%d\n",ans);
    return 0;
}