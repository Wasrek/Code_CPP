/*
    TASK:RC_Tree Beauty
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[1000010],one;
int a[1000010],mark[1000010],cou=0;
void dfs(int i){
    mark[i]=1;
    cou++;
//    printf("c %d\n",cou);
    for(auto x: g[i]){
//        printf("%d %d %d\n",x,a[x],mark[]);
        if(a[x]==1 && !mark[x]){
            dfs(x);
        }
    }
}
int main(){
    int n,m,i,u,v,ch=0,mi=1e9,ans=0;
    scanf("%d",&n);
    m=n-1;
    for(i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1)one.push_back(i),ch++;
        mi=min(mi,a[i]);
    }
    if(!ch){
        printf("%d/1",mi);
        return 0;
    }
    for(auto x: one){
        if(mark[x])continue;
        cou=0;
        dfs(x);
//        printf("%d",cou);
        ans=max(ans,cou);
    }
    printf("1/%d",ans);
}
/*
5
1 2
1 3
2 4
5 2
2
1
1
1
1
*/
