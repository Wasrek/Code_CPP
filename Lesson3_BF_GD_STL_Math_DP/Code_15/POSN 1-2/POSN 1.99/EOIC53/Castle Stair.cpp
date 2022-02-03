/*
    TASK:Castle Stair
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],qs[100100],ans[100100];
int main(){
    int n,k,id,q;
    scanf("%d",&q);
    while(q--){
    scanf("%d %d",&n,&k);
    int i,num;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    ans[1]=qs[1]=1;
    for(i=2;i<=n;i++){
        id=lower_bound(a+1,a+n+1,a[i]-k)-a;
        num=qs[i-1]-qs[id-1];
        ans[i]=num;
        ans[i]+=95959;
        ans[i]%=95959;
        qs[i]=qs[i-1]+ans[i];
        qs[i]%=95959;
    }
    printf("%d\n",ans[n]);
    }
}
