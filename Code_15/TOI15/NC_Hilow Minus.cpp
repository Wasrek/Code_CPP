/*
    TASK:NC_Hilow Minus
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int n,idx;
};
int a[1000010];
deque< A > dq;
int main(){
    int n,m,i,now,ans=2e9;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
       scanf("%d",&a[i]);
    }
    m=n-m;
    sort(a+1,a+1+n);
//    for(i=1;i<=n;i++){
//        printf("%d ",a[i]);
//    }
//    printf("\n");
    for(i=1;i<n;i++){
        now=a[i+1]-a[i];
        while(!dq.empty() && now<=dq.back().n)dq.pop_back();
        while(!dq.empty() && dq.front().idx<=i-m)dq.pop_front();
        dq.push_back({now,i});
        if(i>=m-1){
        ans=min(ans,dq.front().n+(a[i+1]-a[i-m+2]));
        //printf("%d %d %d\n",dq.front().n,a[i+1]-a[i-m+2],dq.front().n+(a[i+1]-a[i-m+2]));
        }
    }
    printf("%d\n",ans);
    return 0;
}
