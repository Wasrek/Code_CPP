/*
    TASK:Boattrip Tom
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator< (const A & o) const{
        if(a!=o.a) return a<o.a;
        else return b<o.b; 
    }
};
A p[300010];
int main()
{
    int n,m,a,b,cnt=0;
    long long ans=0;
    scanf("%d %d",&m,&n);
    ans=n;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        if(a<=b) continue;
        p[++cnt].b=a;
        p[cnt].a=b;
    }
    sort(p+1,p+1+cnt);
    // printf("%d\n",cnt);
    int mi=p[1].a,ma=p[1].b;
    for(int i=2;i<=cnt;i++){
        if(p[i].a<=ma){
            ma=max(ma,p[i].b);
        }else{
            ans+=((ma-mi)*2);
            mi=p[i].a;
            ma=p[i].b;
            // printf("%d\n",ans);
        }
    }
    // printf("%d %d\n",ma,mi);
    ans+=((ma-mi)*2);
    printf("%lld\n",ans);
    return 0;
}