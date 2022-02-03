/*
    TASK:FC_Circle
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map< int,int > mp;
int p[600010];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
int main(){
    int n,ans=0,x,r,cou=0,i;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++){
        p[i]=i;
    }
    while(n--){
        scanf("%d %d",&x,&r);
        ans++;
        if(!mp[x-r])mp[x-r]=++cou;
        if(!mp[x+r])mp[x+r]=++cou;
        if(fin(mp[x-r])==fin(mp[x+r]))ans++;
        p[fin(mp[x-r])]=fin(mp[x+r]);
    }
    ans++;
    printf("%d\n",ans);
}
