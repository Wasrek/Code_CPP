/*
    TASK:Fairy Land
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int p[100010];
int fin(int i){
    if(p[i]==i) return i;
    else return p[i]=fin(p[i]);
}
int main()
{
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        a=fin(a);
        b=fin(b);
        p[a]=b;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        a=fin(a);
        b=fin(b);
        if(a==b)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}