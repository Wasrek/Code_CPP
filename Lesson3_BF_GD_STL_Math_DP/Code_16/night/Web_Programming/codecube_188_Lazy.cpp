/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
int a[100100];
vector< int > g[100100];
int main(){
    int n,m,cou=0,l,r,v,ub,lb;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!mp[a[i]])mp[a[i]]=++cou;
        a[i]=mp[a[i]]; 
        g[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&l,&r,&v);
        if(!mp[v]){
            printf("0\n");
            continue;
        }
        v=mp[v];
        lb=lower_bound(g[v].begin(),g[v].end(),l)-g[v].begin();
        ub=upper_bound(g[v].begin(),g[v].end(),r)-g[v].begin();
        printf("%d\n",ub-lb);
    }
}