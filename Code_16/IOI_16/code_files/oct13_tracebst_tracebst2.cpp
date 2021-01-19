/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector< int > qu; 
char a[100010];
int cou=0;
unordered_map<int,int> mp,ans;
void dfs(int i){
    if(mp[i*2]) dfs(i*2);
    ans[i]=++cou;
    if(mp[i*2+1]) dfs(i*2+1);
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",a+1);
        for(int j=1,now=1;j<=strlen(a+1);j++){
            if(a[j]=='*'){
                mp[now]=1;
                qu.push_back(now);
                break;
            }
            if(a[j]=='R') now=2*now+1;
            else now*=2;
        }
    }
    dfs(1);
    for(auto x: qu) printf("%d\n",ans[x]);
    return 0;
}