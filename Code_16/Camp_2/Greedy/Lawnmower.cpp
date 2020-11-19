/*
    TASK:Lawnmower
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],mi[110],mj[110];
int main()
{
    int q,n,m,ch=0;
    scanf("%d",&q);    
    for(int k=1;k<=q;k++){
        memset(mi,0,sizeof mi);
        memset(mj,0,sizeof mj);
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                mi[i]=max(mi[i],a[i][j]);
                mj[j]=max(mj[j],a[i][j]);
            }
        }
        ch=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]<mi[i] && a[i][j]<mj[j]) {
                    ch=1;
                    break;
                }
            }
            if(ch) break;
        }
        printf("Case #%d: ",k);
        if(ch) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}