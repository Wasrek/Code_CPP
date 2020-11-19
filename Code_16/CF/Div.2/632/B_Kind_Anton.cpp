/*
    TASK:B. Kind Anton
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    int q,n,now,ch0,chp,chm,mi0,mip,mim,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ch0=chp=chm=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&now);
            a[i]=now;
            if(now==0 && !ch0)ch0=1,mi0=i;
            else if(now==1 && !chp)chp=1,mip=i;
            else if(now==-1 && !chm)chm=1,mim=i;
        }
        // printf("%d %d %d\n",mi0,mip,mim);
        ch=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&now);
            if(now==a[i]) continue;
            if((now>a[i] && (!chp || (chp && mip>=i)))|| (now<a[i] && (!chm  || (chm && mim>=i)))){
                ch=0;
            }
        }
        if(ch)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}