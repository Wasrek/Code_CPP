/*
    TASK:Lazy
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,int> mp;
vector<int> g[100010];
int main(){
    int n,q,i,id=0,l,r,v,up,lo,ans;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!mp[a[i]])mp[a[i]]=++id;
        g[mp[a[i]]].push_back(i);
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&v);
        up=upper_bound(g[mp[v]].begin(),g[mp[v]].end(),r)-g[mp[v]].begin();
        lo=lower_bound(g[mp[v]].begin(),g[mp[v]].end(),l)-g[mp[v]].begin();
        ans=up-lo;
        printf("%d\n",ans);
    }
}
