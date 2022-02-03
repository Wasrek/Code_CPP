/*
    TASK:RT Shattered Glass Shoe
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100];
int main(){
    long long n,i,m,mid,sum,l,r;
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    for(i=0;i<n;i++) scanf("%lld",&b[i]);
    scanf("%lld",&m);
    l=0,r=1e9;
    while(l<r){
        mid=(l+r+1)/2;
        for(i=0,sum=0;i<n;i++){
            sum+=max(0ll,(mid*a[i])-b[i]);
        }
        if(sum<=m) l=mid;
            else r=mid-1;
    }
    printf("%lld",r);
}
/*
4
5 2 3 1
9 9 9 9
25
*/
