/*
    TASK:Canon at the Fort
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    int n,m,q,k,i,j,ii,jj,last,qs,ans,idx1,idx2,ll,rr;
    scanf("%d %d %d %d",&n,&m,&q,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
//    last=0;
    while(q--){
        qs=0;ans=0;
        last=1;
        for(i=1;i<=m;i++){
            scanf("%d",&ii);
            idx1=ii-k;
            idx2=ii+k;
            ll=lower_bound(a+last,a+1+n,idx1)-a;
            rr=last=upper_bound(a+last,a+1+n,idx2)-a;
            ans+=rr-ll;
    }
    printf("%d\n",ans);
    }
    return 0;
}
/*
3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001
*/
