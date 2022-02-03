/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > g[100010],ans;
int sum[100010],cnt=0;
void dfs(int i,int la){
    int ma=0;
    // printf("now %d %d\n",i,la);
    for(auto x: g[i]){
        if(x==la) continue;
        dfs(x,i);
        // printf("-- %d %d %d\n",x,sum[x],ma);
        if(sum[x]<=ma){
            // printf("ans %d %d\n",x,sum[x]);
            ans.push_back(sum[x]);
        }else{
            if(ma) ans.push_back(ma);
            ma=sum[x];
        }
    }
    if(g[i].size()>1) cnt++;
    sum[i]+=ma;
    // printf("%d\n",sum[i]);
    return; 
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        sum[i]=1;
    }
    sum[n]=1;
    dfs(1,-1);
    ans.push_back(sum[1]);
    sort(ans.begin(),ans.end(),greater< int >());
    printf("%d\n",ans.size());
    for(auto x: ans) printf("%d\n",x);
    return 0;
}