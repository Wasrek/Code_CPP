/*
    TASK:FC_Cinema
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
    bool operator<(const A&o)const{
        if(x!=o.x)return x>o.x;
        return y<o.y;
    }
};
A a[100010];
long long u[100010],tu[100010];
A p[100010];
vector<long long> ans;
int main(){
    long long n,i,x,y,k,sum=0;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].x,&a[i].y);
    }
    for(i=1;i<=n;i++){
        tu[i]=min(a[i].x,a[i].y);
        u[i]=min(a[i].x*2,a[i].y);
        sum+=tu[i];
        p[i].x=u[i]-tu[i];
        p[i].y=i;
    }
    sort(p+1,p+1+n);
    for(i=1;i<=k;i++){
        ans.push_back(p[i].y);
        sum+=p[i].x;
    }
    sort(ans.begin(),ans.end());
    for(i=0;i<k;i++){
        printf("%lld ",ans[i]);
    }
    printf("\n%lld\n",sum);
}
