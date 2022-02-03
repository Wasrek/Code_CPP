/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i;
    float h;
    bool operator < (const A & o) const{
        return h<o.h;
    }
};
int val[200100],s[200100],e[200100],ce[200100];
A g[1000010];
int main()
{
    int h,n,m,k,now,nh,ma=0,ch=0;
    scanf("%d %d %d",&h,&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        s[i]=e[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %f",&g[i].i,&g[i].h);
    }
    scanf("%d",&k);
    sort(g+1,g+1+m);
    for(int i=1;i<=m;i++){
        swap(e[s[g[i].i]],e[s[g[i].i+1]]);
        swap(s[g[i].i],s[g[i].i+1]);
    }
    ma=val[e[k]];
    for(int i=1;i<=n;i++){
        // printf("%d %d\n",e[i],s[i]);
        ce[i]=e[i];
        e[i]=s[i]=i;
    };
    for(int i=1;i<=m;i++){
        swap(e[s[g[i].i]],e[s[g[i].i+1]]);
        swap(s[g[i].i],s[g[i].i+1]);
        if(g[i].h==g[i+1].h) continue;
        if(val[ce[s[e[k]+1]]]>ma){
            ma=val[ce[s[e[k]+1]]];
            ch=1;
        }
        if(val[ce[s[e[k]-1]]]>ma){
            ma=val[ce[s[e[k]-1]]];
            ch=1;
        }
    }
    printf("%d\n",ma);
    if(ch)printf("USE\n");
    else printf("NO\n");
    return 0;
}
/*
20 5 6
7 5 3 9 4
1 5
1 6
2 10
1 12
3 6
3 13
1
*/