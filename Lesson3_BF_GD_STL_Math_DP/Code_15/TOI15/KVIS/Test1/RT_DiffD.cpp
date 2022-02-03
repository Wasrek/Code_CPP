/*
    TASK:RT_DiffD
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100010
int a[N],dp[N];
map<int,int> id;
int main(){
    int n,q,d,i,l,r;
    scanf("%d %d %d",&n,&q,&d);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++){
        dp[i]=max(id[a[i]-d],id[a[i]+d]);
        dp[i]=max(dp[i-1],dp[i]);
        id[a[i]]=i;
    }
    while(q--){
        scanf("%d %d",&l,&r);
        if
        (dp[r]>=l){
        printf("yes\n");
        }else{
            printf("no\n");
        }
    }
}
