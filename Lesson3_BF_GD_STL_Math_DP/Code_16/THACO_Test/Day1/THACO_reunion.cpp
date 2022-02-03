/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y,r;
};
A a[110],c[30010];
int cnt[300010];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);;
    }
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&c[i].x,&c[i].y,&c[i].r);
    }
    long long dis;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
            dis=(a[i].y-c[j].y)*(a[i].y-c[j].y)+(a[i].x-c[j].x)*(a[i].x-c[j].x);
            if(dis>=(c[j].r*c[j].r)) continue;
            cnt[j]++;
        }
    }
    int ans=0,ch=0;
    for(int i=1;i<=m;i++){
        if(cnt[i]!=n && cnt[i]!=0){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}