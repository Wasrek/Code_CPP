/*
    TASK:C. Eugene and an array
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<iostream>
#include<unordered_map>
using namespace std;
long long qs[100010];
unordered_map<long long,int> mp;
int main()
{
    int n,ch,la=0,cha;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        if(qs[i]==0){
            la=i;
            continue;
        }
        qs[i]+=qs[i-1];
        if(qs[i]==0){
            la=i;
            ans+=(i-mp[0]-1);
            continue;
        }
        if(mp[qs[i]] && mp[qs[i]]>=la){
            ans+=(i-mp[qs[i]]);
            la=mp[qs[i]];
        }else {
            ans+=(i-la);
        }
        mp[qs[i]]=i;
        // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
    return 0;
}