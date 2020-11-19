/*
    TASK:E. Minimizing Difference
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010];
map<int,int> mp;
int main()
{
    long long n,k,j=0,b,ch=0;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&b);
        if(!mp[b])a[++j]=b;
        mp[b]++;
    }
    sort(a+1,a+1+j);
    // printf("%lld\n",j);
    // for(int i=1;i<=j;i++){
    //     printf("%lld %lld\n",a[i],mp[a[i]]);
    // }
    long long ma=a[j],mi=a[1],l=1,r=j;
    while(l<r){
        long long nl=(a[l+1]-a[l])*mp[a[l]];
        long long nr=(a[r]-a[r-1])*mp[a[r]];
        // printf("%lld %lld %lld %lld %lld %lld %lld\n",l,nl,r,nr,ma,mi,k);
        if(nl<nr){
            if(k>=nl){
                k-=nl;
                mi=a[l+1];
                mp[a[l+1]]+=mp[a[l]];
                l++;
            }else{
                ch=1;
                break;
            }
        }else{
            if(k>=nr){
                k-=nr;
                ma=a[r-1];
                mp[a[r-1]]+=mp[a[r]];
                r--;
            }else{
                ch=1;
                break;
            }
        }
    }
    // printf("%lld %lld\n",ma,mi);
    printf("%lld\n",ma-mi);
    return 0;
}