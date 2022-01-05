/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 200100
struct A{
    int x,y;
    bool operator <(const A& o) const{
        if(x!=o.x) return x<o.x;
        return y<o.y;
    }
};
A a[N];
int le[N],ri[N];
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        sort(a+1,a+1+n);
        le[1]=a[1].y;ri[n]=a[n].y;
        for(int i=2;i<=n;i++){
            le[i]=min(le[i-1],a[i].y);
        }
        for(int i=n-1;i>=1;i--){
            ri[i]=max(ri[i+1],a[i].y);
        }
        int ans=1;
        for(int i=1;i<n;i++){
            if(le[i]>ri[i+1]){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
10
333339669 -999981533
333352504 -999973500
333344813 -999984276
-333306369 -333303976
-333327626 -333308870
-333310050 -333305189
-999990036 333350159
-999997002 333333823
-999995170 333345274
-1666634272 1000005434
9
333333488 -999996098
333345717 -999999708
333352051 -999982579
-333313436 -333313616
-333311605 -333327887
-333321793 -333318563
-999980085 333335201
-999973698 333358999
-999990103 333350367
*/