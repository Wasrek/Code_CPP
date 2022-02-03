/*
    TASK:Infinity Lime
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[700010];
vector<long long> ans;
int main(){
    long long m,k,i,j,n,idx;
    scanf("%lld %lld",&m,&k);
    a[0]=0;
    for(i=1;i<=m;i++){
        scanf("%lld",&a[i]);
    }
    a[m+1]=1e18;
    sort(a,a+2+m);
    for(i=2;i<=m;i++)a[i]-=(i-1);
    for(i=1;i<=k;i++){
        scanf("%lld",&n);
        idx=upper_bound(a,a+2+m,n)-a;
        idx--;
        n+=idx;
        //printf("%lld ",idx);
        ans.push_back(n);
    }
    //printf("\n");
    for(auto x:ans){
        printf("%lld ",x);
    }
    printf("\n");
    return 0;
}
