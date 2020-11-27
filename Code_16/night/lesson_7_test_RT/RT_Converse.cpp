/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
map< int,int > a,b;
int main()
{
    int q,n,now,ansa=0,ansb=0,ans;
    scanf("%d",&q);
    while(q--){
        ansa=ansb=0;
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&now);
            a[now]++;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&now);
            b[now]++;
        }
        for(int i=1;i<=5;i++){
            if(b[i]>a[i]){
                // printf("%d %d\n",a[i],b[i]);
                ansa+=((b[i]-a[i])/2);
            }else ansb+=((a[i]-b[i])/2);
            if((b[i]+a[i])%2){
                ans=-1;
                break;
            }
        }
        if(ans==-1 || ansa!=ansb)printf("-1\n");
        else printf("%d\n",ansa);
        a.clear();
        b.clear();
    }
    return 0;
}