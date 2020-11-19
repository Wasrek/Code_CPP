/*
    TASK:Durian Company
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int fw[1000010];
int main()
{
    int a,b,pp=0,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        // upd(a,b);
        pp=max(pp,max(a,b));
        fw[a]++;
        fw[b]--;
    }
    int ma=0;
    for(int i=1;i<=pp;i++){
        fw[i]+=fw[i-1];
        ma=max(ma,fw[i]);
    }
    printf("%d\n",ma);
    return 0;
}